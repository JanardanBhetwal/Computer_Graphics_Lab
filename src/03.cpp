// Mid-point Algorithm to make a circle
# include <stdio.h>
# include <graphics.h>
# include <math.h>
# include <conio.h>
# include <stdlib.h>


void mid_point_circle(int x1,int y1,int r)
{
    int p0=1-r;
    int x0=0;
    int y0=r;
    while(x0<=y0)
    {
        if(p0<0)
        {
            x0=x0+1;
            y0=y0;
            p0=p0+2*x0+1;
        }
        else
        {
            x0=x0+1;
            y0=y0-1;
            p0=p0+2*x0-2*y0+1;
        }
        putpixel(x0+x1,y0+y1,15);
        putpixel(y0+x1,x0+y1,15);
        putpixel(-x0+x1,y0+y1,15);
        putpixel(-y0+x1,x0+y1,15);
        putpixel(-x0+x1,-y0+y1,15);
        putpixel(-y0+x1,-x0+y1,15);
        putpixel(x0+x1,-y0+y1,15);
        putpixel(y0+x1,-x0+y1,15);
        
    }
}

int main()
{
    int gm, x, y, gd = DETECT;
    int x1, y1, r;
    char path[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    initgraph(&gd, &gm, path);
    
    // circle(100, 100, 50);
    printf("Enter the center of the circle: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);
    mid_point_circle(x1, y1, r);
    getch();
    closegraph();
    
    return 0;
}