/* traffic.h - simple pin masks and notes for mapping
   Each lane uses 3 bits in P2 (conceptual): [R, Y, G]
   Lane 0 (North): bits 0..2
   Lane 1 (South): bits 3..5
   Lane 2 (East) : bits 6..8 (note: P2 is 8-bit; adjust wiring if exceeding P2 width)
   Lane 3 (West) : bits 9..11 (may require external port expansion in real hardware)
*/

#define RED_MASK    0x01
#define YELLOW_MASK 0x02
#define GREEN_MASK  0x04

/* Note: On real hardware, ensure proper wiring and drivers (transistors) for LEDs. 
   Keil / Flash Magic instructions provided in README.
*/

