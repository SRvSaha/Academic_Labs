#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main(){
    int gd=DETECT,gm; 
    initgraph(&gd,&gm,NULL);
    
    int x1,x2;
    int y1,y2;
    int x_increment,y_increment;
    int steps;
    
   /*printf("Please enter co-ordinates of the first point : ");
    scanf("%d%d",&x1,&y1);
    printf("Please enter co-ordinates of the second point : ");
    scanf("%d%d",&x2,&y2);
   */
    x1 = 10;
    x2 = 100;
    y1 = 0; 
    y2 = 200;
    int x = x1, y  = y1;
    int dx = (x1-x2);
    int dy = (y1-y2);
    float m = dy/dx;
    if(abs(m) <= 1){
        // when dx >= dy
        x_increment = 1;
        y_increment = round(m);
        steps = abs(dx);
    }
    else{
        //when dx < dy
        x_increment = round(1/m);
        y_increment = 1;
        steps = abs(dy);
    }
    for(int i = 0; i < steps; i++){
        x += x_increment;
        y += y_increment;
        putpixel(x,y,15);
        //delay(500); 
    }
    delay(5000); 
    return 0;
}
