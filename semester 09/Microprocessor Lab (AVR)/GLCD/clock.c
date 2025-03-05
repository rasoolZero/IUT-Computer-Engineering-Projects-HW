
#include <avr/io.h>
#include <util/delay.h>
#include "gfx.h"
#include "fonts/arial12.h"
#include "font.h"
#include <math.h>

#include "clock.h"

//global variable

double status_degree;

//function definition

void Draw_clock_hand(int xcoordinate,int ycoordinate)
{
	GFXLine(64,32,xcoordinate,ycoordinate,GFX_COLOR_BLACK);
	_delay_us(10);
}

double degree_to_radian(double degree)
{
	double radian;
	radian=(degree*(0.0174));
	return radian;
}


int min_x_coordinate_finder(uint16_t min,uint16_t radius,double degree)
{
	int xcoordinate,intermediate;
	double actualdegree;
	double radian;
	actualdegree= (90-(degree*min));
	status_degree=actualdegree;
	radian= degree_to_radian(actualdegree);
	intermediate= radius*(cos(radian));
	xcoordinate= (64+intermediate);
	return xcoordinate;
}


int min_y_coordinate_finder(uint16_t min,uint16_t radius,double degree)
{
	int ycoordinate,intermediate;
	double actualdegree;
	double radian;
	actualdegree= (90-(degree*min));
	status_degree=actualdegree;
	radian= degree_to_radian(actualdegree);
	intermediate= radius*(sin(radian));
	ycoordinate= (32-intermediate);
	return ycoordinate;
}

int sec_x_coordinate_finder(uint16_t sec,uint16_t radius,double degree)
{
	int ycoordinate,intermediate;
	double actualdegree;
	double radian;
	actualdegree= (90-(degree*sec));
	radian= degree_to_radian(actualdegree);
	intermediate= radius*(cos(radian));
	ycoordinate= (64+intermediate);
	return ycoordinate;
}

int sec_y_coordinate_finder(uint16_t sec,uint16_t radius,double degree)
{
	int ycoordinate,intermediate;
	double actualdegree;
	double radian;
	actualdegree= (90-(degree*sec));
	radian= degree_to_radian(actualdegree);
	intermediate= radius*(sin(radian));
	ycoordinate= (32-intermediate);
	return ycoordinate;
}

int hr_x_coordinate_finder(uint16_t hr,uint16_t radius,double degree)
{
	int xcoordinate,intermediate;
	double actualdegree;
	double radian;
	actualdegree= (90-(degree*hr));
	actualdegree= (actualdegree-((90-status_degree)/12));
	radian= degree_to_radian(actualdegree);
	intermediate= radius*(cos(radian));
	xcoordinate= (64+intermediate);
	return xcoordinate;
}

int hr_y_coordinate_finder(uint16_t hr,uint16_t radius,double degree)
{
	int ycoordinate,intermediate;
	double actualdegree;
	double radian;
	actualdegree= (90-(degree*hr));
	actualdegree= (actualdegree-((90-status_degree)/12));
	radian= degree_to_radian(actualdegree);
	intermediate= radius*(sin(radian));
	ycoordinate= (32-intermediate);
	return ycoordinate;
}





void Draw_clock(uint16_t hr,uint16_t min,uint16_t sec)
{
	
	int hr_x_coordinate,hr_y_coordinate,min_x_coordinate,min_y_coordinate,sec_x_coordinate,sec_y_coordinate;
	
	if(hr>=12 && hr<=24) hr=hr-12;
	
	
		
	if(sec==60)
	{
		sec=0;
		min=min+1;
		if(min==60)
		{
			min=0;
			
			hr=hr+1;			
		}
	}
	
	GFXCircle(64,32,30,GFX_COLOR_BLACK);
	
	hr_x_coordinate= hr_x_coordinate_finder(hr,HR_RADIUS,30);
	hr_y_coordinate= hr_y_coordinate_finder(hr,HR_RADIUS,30);
	Draw_clock_hand(hr_x_coordinate,hr_y_coordinate);
	
	_delay_us(5);
	min_x_coordinate=min_x_coordinate_finder(min,MIN_RADIUS,6);
	min_y_coordinate=min_y_coordinate_finder(min,MIN_RADIUS,6);
	Draw_clock_hand(min_x_coordinate,min_y_coordinate);
	
	_delay_us(5);
	sec_x_coordinate=sec_x_coordinate_finder(sec,SEC_RADIUS,6);
	sec_y_coordinate=sec_y_coordinate_finder(sec,SEC_RADIUS,6);
	Draw_clock_hand(sec_x_coordinate,sec_y_coordinate);
	GFXUpdate();
}
