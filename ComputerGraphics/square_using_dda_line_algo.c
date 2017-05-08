#include <stdio.h>
#include <graphics.h>
#include <math.h>

// Function to find the absolute value

int abs(int n){
	return ((n>0)?n:(n*(-1)));
}

// DDA Function for line generation

void DDA(int X0, int Y0, int X1, int Y1){
	// calculate dx and dy
	int dx = X1 - X0;
	int dy = Y1 - Y0;

	// Calculate steps required for generating pixels 
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	// calculate increment in x and y for each step
	float x_inc = dx /(float)steps;
	float y_inc = dy /(float)steps;
	int i;
	int X = X0, Y = Y0;
	for(i = 0; i <= steps; i++){
		putpixel(X,Y,WHITE); // Put pixel at (X,Y)
		X += x_inc; // increment in x at each step
		Y += y_inc; // increment in y at each step
	}
}

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	DDA(100,100,200,100);
	DDA(200,100,200,200);
	DDA(200,200,100,200);
	DDA(100,200,100,100);
	delay(1000);
	return 0;
}