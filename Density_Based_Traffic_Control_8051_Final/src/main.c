/* Density-Based Traffic Light Control (8051) - concise version
   Author: Rahul Trivedi, M.Tech
*/
#include <reg52.h>
#include "traffic.h"

void delay_seconds(unsigned int sec) {
    unsigned int i,j;
    for(i=0;i<sec;i++) for(j=0;j<30000;j++);
}

unsigned char read_presence(unsigned char e, unsigned char x) {
    unsigned char c=0;
    if ((P1 & (1<<e)) == 0) c++;
    if ((P1 & (1<<x)) == 0) c++;
    return c;
}

unsigned int get_duration(unsigned char cnt) {
    if (cnt<=2) return 5;
    if (cnt<=6) return 10;
    return 20;
}

void set_lane_state(unsigned char lane, unsigned char state) {
    unsigned char r=(RED_MASK<<(lane*3));
    unsigned char y=(YELLOW_MASK<<(lane*3));
    unsigned char g=(GREEN_MASK<<(lane*3));
    P2 &= ~(r|y|g);
    if (state==0) P2 |= r;
    else if (state==1) P2 |= g;
    else if (state==2) P2 |= y;
}

void all_red() { P2 = 0x00; P2 |= (RED_MASK | (RED_MASK<<3) | (RED_MASK<<6) | (RED_MASK<<9)); }
void init_ports() { P1 = 0xFF; P2 = 0x00; }

void main(void){
    unsigned char entry[4]={0,2,4,6}, exitp[4]={1,3,5,7}, i;
    unsigned int scores[4];
    init_ports();
    while(1){
        unsigned int max=0, maxl=0;
        for(i=0;i<4;i++){ scores[i]=read_presence(entry[i], exitp[i]); if(scores[i]>max){max=scores[i]; maxl=i;} }
        for(i=0;i<4;i++) set_lane_state(i, (i==maxl)?1:0);
        delay_seconds(get_duration(scores[maxl]));
        set_lane_state(maxl,2); delay_seconds(2);
        all_red(); delay_seconds(1);
    }
}
