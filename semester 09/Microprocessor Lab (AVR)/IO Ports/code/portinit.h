#ifndef _PORTINIT_H
#define _PORTINIT_H


void initialPorts(void);
char isPD7Pressed(void);
char isPD6Down(void);
void updatePortD(unsigned char,unsigned char,unsigned char,unsigned char);
void updatePortB(void);
#endif 