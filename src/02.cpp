// Bresenham's Algorithm to make a line
# include <stdio.h>
# include <graphics.h>
# include <math.h>
# include <conio.h>
# include <stdlib.h>

int calculateP(int p0,int dx,int dy)
{
    if (p0 < 0)
        return p0 + 2*dy;
    else
        return p0 + 2*dy - 2*dx;
}

int main()
{
    int gm, x, y, gd = DETECT;
    char path[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    initgraph(&gd, &gm, path);
    int x1 = 100, y1 = 100, x2 = 200, y2 = 150;
    int dx = x2 - x1;
    int dy=y2-y1;
    float m=dy/dx;
    if(abs(m)<0)
    {
        int p0=2*(y2-y1)-(x2-x1);
        while(abs(x1)<=abs(x2) && abs(y1)<=abs(y2))
        {if(p0<0)
        {
            x1=x1+1;
            y1=y1;
        }
        else
        {   x1=x1+1;
            y1=y1+1;
        }
        putpixel(x1,y1,15);
        p0=calculateP(p0,dx,dy);
        }
    }
    else
    {
        int p0=2*dx-dy;
        while(x1<=x2)
        {if(p0<0)
        {
            x1=x1;
            y1=y1+1;
        }
        else
        {   x1=x1+1;
            y1=y1+1;
        }
        putpixel(x1,y1,15);
        p0=calculateP(p0,dy,dx);
        }
    }
    
    
    getch();
    closegraph();
    
    return 0;
}