#include <stdio.h>
#include <graphics.h>

int main()
{
	// For graphics
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"");
	
	// The start and end points
	
	int x1, x2, y1, y2;
	
	// p  : decision parameter for which pixel to be choosen
	// dx : change in x
	// dy : change in y
	// x_next : next value for x
	// y_next : next value for y
	
	int dx, dy, p, x_next, y_next;
	scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
	// // Using Manual Input
	// x1 = 10;
	// y1 = 10;
	// x2 = 50;
	// y2 = 30;
	
	// Change in x and change in y
	// In this implementation we are asuuming that m < 1 i.e. change in x should be less that change in y
	// so that we sample along x i.e. x_next = x + 1
	
	dy = y2 - y1;
	dx = x2 - x1;
	
	/*
		Main equation for P (decision parameter):
		P_next = P + 2*dy - 2(y_next - y)
		But (y_next-y) is 0 when P < 0 cause we are choosing 
		that pixel which is closer to y else it is 1 since
		we are choosing the y_next as y+1.
	*/
		
	p = 2*dy - dx; // The starting value should be this

	// We assume that x1,y1 is the starting point and x2, y2 is the ending point
	x_next = x1;
	y_next = y1;

	// While the end point is found, end point is x2 since here we assume that
	// m < 1 and we are sampling along x axis that is x_next = x + 1

	while(x_next != x2){
		// p < 0 implies d_lower > d_higher || Refer <https://www.tutorialspoint.com/computer_graphics/line_generation_algorithm.htm>
		if(p <= 0){
			x_next += 1; // x_next = x + 1 cause we are sampling along x
			y_next += 0; // since p <= 0 so the line is closer to y and not to y+1. So, y_next = y
						// when p = 0, d_lower = d_higher =.; we can choose any one i.e, y_next = y or y_next = y + 1. We chose y_next = y
			p += 2*dy;  // since y_next = y so y_next - y = 0 
		}
		else{
			x_next += 1; // x_next = x + 1 cause we are sampling along x
			y_next += 1; // since p > 0 so the line is closer to y and not to y+1. So, y_next = y
			p += 2*(dy - dx); // since y_next = y + 1 so y_next - y = 1 
		}
		putpixel(x_next, y_next, WHITE); // displaying of the pixel
		// delay(1000); // waiting for 1 second after the pixel is displayed
	}
	delay(5000); // The graph waits for 5 seconds before closing of the display
	return 0;
}
