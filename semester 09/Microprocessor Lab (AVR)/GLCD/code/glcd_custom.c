
#include <glcd.h>
#include <font5x7.h>

void glcd_custom_image(void){
    glcd_setlinestyle(5, GLCD_LINE_SOLID);
    // I    
    glcd_line(38,16,38,48);
    // U
    glcd_rectround(46,6,25,43,8);
    glcd_setfillcolor(0);
    glcd_bar(46, 0, 71, 15);
    glcd_setfillcolor(1);
    
    // T                 
    glcd_line(81,16,81,48);
    glcd_line(73,16,93,16);
    
        
    // frame
    glcd_setlinestyle(2, GLCD_LINE_DOT_LARGE);
    glcd_line(16,32,36,52);
    glcd_line(16,32,36,12);
    glcd_line(36,52,96,52);
    glcd_line(36,12,96,12);
    glcd_line(112,32,96,52);
    glcd_line(112,32,96,12);
}