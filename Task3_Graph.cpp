#include "graphics.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define pi 3.1415

double f(double x)
{
	return cos(x);
}

double getYmax(double Xmax, double Xmin)
{
	double ValueMax=0;
	for(Xmin;Xmin<Xmax;Xmin+=0.01)
	{
		if(f(Xmin)>ValueMax)
			ValueMax=f(Xmin);		
	}
	return ValueMax;
}

double getYmin(double Xmax, double Xmin)

{
	double ValueMin=0;
	for(Xmin;Xmin<Xmax;Xmin+=0.01)
	{
		if(f(Xmin)<ValueMin)
			ValueMin=f(Xmin);		
	}
	return ValueMin;
}



int main( )
{
	int ScreenMaxWidth, ScreenMaxHeight, xl, yl, xr, yr, Xgr, Ygr;
	double koef, Xmax, Xmin, Ymax, Ymin, a1, a2, b1, b2, x0, y0;
	koef=pi/180;
	Xmin=0*koef; 
	Xmax=1000*koef;
	ScreenMaxWidth=getmaxwidth();
	ScreenMaxHeight=getmaxheight();
	printf("ScreenMaxWidth = %d ScreenMaxHeight = %d\n", ScreenMaxWidth, ScreenMaxHeight);
	initwindow(ScreenMaxWidth, ScreenMaxHeight, "F*ck this programm");
	xl=ScreenMaxWidth/20; 
	yl=ScreenMaxHeight/20;
	xr=ScreenMaxWidth-xl; 
	yr=ScreenMaxHeight-yl;
	Ymax=getYmax(Xmax, Xmin);
	Ymin=getYmin(Xmax, Xmin);
	a1 = (xr - xl)/(Xmax - Xmin);
	a2 = xl - a1*Xmin;
	b1 = (yl - yr)/(Ymax - Ymin);
	b2 = yl - b1*Ymax;
	rectangle(xl,yl,xr,yr);
	outtextxy(xl,yl-ScreenMaxHeight/25,"Y = cos(x), 0 < x < 1000, -1 < y < 1");
	for(Xmin;Xmin<Xmax;Xmin+=0.01)
	{
		Xgr=a1*Xmin+a2;
		Ygr=b1*f(Xmin)+b2;
		putpixel(Xgr,Ygr, 15);
	}
	/*tochka x0 y0*/
	x0=a1*(360*koef)+a2;
	y0=b1*0+b2;
	/*osi*/
	line(x0,y0,x0,yr);
	line(x0,y0,x0,yl);
	line(x0,y0,xr,y0);
	line(x0,y0,xl,y0);
	printf("x0=%0.lf y0=%0.lf\n", x0, y0);
	outtextxy(x0+1,y0+1,"0");
	outtextxy(xr-10,y0+1,"X");
	outtextxy(x0+1,yl+3,"Y");
	while (!kbhit( ))
    {
        delay(200);
    }
    return 0; 
}