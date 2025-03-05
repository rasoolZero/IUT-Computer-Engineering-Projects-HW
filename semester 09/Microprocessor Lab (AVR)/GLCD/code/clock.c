#include <glcd.h>
#include <font5x7.h>
#include <math.h>
#include <delay.h>

float degree_to_radian(float degree)
{
	return (degree*(0.0174f));
}
void render_hour(int hr,int radius){
    int xcoordinate,intermediate,ycoordinate;
    float radian,degree=30.0;
    float actualdegree;
    actualdegree= (90.0-(degree*hr));
    //actualdegree= (actualdegree-((90.0-status_degree)/12.0));
    radian= degree_to_radian(actualdegree);
	intermediate= radius*(cos(radian));
	xcoordinate= (64+intermediate);
	intermediate= radius*(sin(radian));
	ycoordinate= (32.0-intermediate);
    
    glcd_line(64,32,xcoordinate,ycoordinate);
    
}

void render_second(int sec,int radius)
{
	int ycoordinate,intermediate,xcoordinate;
	float radian;
    float degree = 6.0;
    float actualdegree;
	actualdegree= (90.0-(degree*sec));
	radian = degree_to_radian(actualdegree);
	intermediate= radius*(cos(radian));
	xcoordinate= (64+intermediate);
	intermediate= radius*(sin(radian));
	ycoordinate= (32-intermediate);
    glcd_line(64,32,xcoordinate,ycoordinate);
}



void render_clock(int seconds,int minutes,int hours){ 
    glcd_clear();
    //render_second(seconds,20);
    render_hour(hours,10);
}