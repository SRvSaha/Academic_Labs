/*
@author 	: SRvSaha
Date 		: 22-03-2017
Description : Animation of Circle
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	int r = 40;
	int i,x, y;
	while(1){
		x = rand()%(getmaxx());
		y = rand()%(getmaxy());
		if(x <= r || y <= r || x >= getmaxx()-r || y >= getmaxy()-r){
			circle(getmaxx()/2,getmaxy()/2,r);
		}
		else{
			circle(x,y,r);
		}
		delay(1000);
		cleardevice();
	}
	return 0;
}
