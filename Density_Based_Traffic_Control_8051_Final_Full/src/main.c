/* 
 Density Based Traffic Light Control System (4-way, dual-sensor per lane)
 Priority-based dynamic green assignment - Plain C (Keil compatible)
 Author: Rahul Trivedi, M.Tech
 Note: This is a reference implementation (presence-based demo). For production, use
 interrupt-driven counters and hardware debouncing.
*/

#include <reg52.h>
#include "traffic.h"

// Rough blocking delay (~1 second). Replace with Timer0 for accuracy on real hardware.
void delay_seconds(unsigned int sec) {
    unsigned int i,j;
    for(i=0;i<sec;i++) {
        for(j=0;j<30000;j++) { /* approx delay for 11.0592MHz */ }
    }
}

// Read simple presence on entry/exit sensors for a lane (entry_pin, exit_pin are bit positions 0-7)
unsigned char read_presence(unsigned char entry_pin, unsigned char exit_pin) {
    unsigned char entry = 0;
    unsigned char exitc = 0;
    if ((P1 & (1<<entry_pin)) == 0) entry = 1; // active-low sensor
    if ((P1 & (1<<exit_pin)) == 0) exitc = 1;
    // return net presence count (0,1,2)
    return entry + exitc;
}

// Map density (0-2) to a density score for prioritization. For demo, we treat presence sum as density.
unsigned int density_score(unsigned char count) {
    return (unsigned int)count; // 0..2
}

// Determine duration from score - step-wise mapping
unsigned int get_duration(unsigned int score) {
    if (score <= 2) return 5;      // Low
    else if (score <= 6) return 10; // Medium (kept for completeness)
    else return 20;                // High
}

// Set lane LEDs - lane index 0..3
void set_lane_red(unsigned char lane) {
    unsigned char mask = (RED_MASK << (lane*3));
    P2 &= ~(GREEN_MASK << (lane*3));
    P2 &= ~(YELLOW_MASK << (lane*3));
    P2 |= mask;
}
void set_lane_yellow(unsigned char lane) {
    P2 &= ~(GREEN_MASK << (lane*3));
    P2 &= ~(RED_MASK << (lane*3));
    P2 |= (YELLOW_MASK << (lane*3));
}
void set_lane_green(unsigned char lane) {
    P2 &= ~(RED_MASK << (lane*3));
    P2 &= ~(YELLOW_MASK << (lane*3));
    P2 |= (GREEN_MASK << (lane*3));
}

void all_red() {
    P2 = 0x00;
    P2 |= (RED_MASK | (RED_MASK<<3) | (RED_MASK<<6) | (RED_MASK<<9));
}

void init_ports() {
    P1 = 0xFF; // inputs (pull-ups)
    P2 = 0x00; // outputs
}

void main() {
    unsigned int scores[4];
    unsigned char i;
    unsigned char entry_pins[4] = {0,2,4,6}; // P1.0,P1.2,P1.4,P1.6
    unsigned char exit_pins[4]  = {1,3,5,7}; // P1.1,P1.3,P1.5,P1.7
    init_ports();
    while(1) {
        for(i=0;i<4;i++) {
            unsigned char cnt = read_presence(entry_pins[i], exit_pins[i]);
            scores[i] = density_score(cnt);
        }
        unsigned int max = 0;
        unsigned char max_lane = 0;
        for(i=0;i<4;i++) {
            if (scores[i] > max) { max = scores[i]; max_lane = i; }
        }
        for(i=0;i<4;i++) {
            if (i == max_lane) set_lane_green(i);
            else set_lane_red(i);
        }
        unsigned int dur = get_duration(scores[max_lane]);
        delay_seconds(dur);
        set_lane_yellow(max_lane);
        delay_seconds(2);
        all_red();
        delay_seconds(1);
    }
}
