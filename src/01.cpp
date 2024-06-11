// DDA Algorithm to make a line
# include <stdio.h>
# include <graphics.h>
# include <math.h>
# include <conio.h>
# include <stdlib.h>

int main()
{
    int gm, x, y, gd = DETECT;
    float m;
    char path[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    initgraph(&gd, &gm, path);
    float x1 = 100, y1 = 100, x2 = 200, y2 = 200,i;
    m=(y2-y1)/(x2-x1);
    if(abs(m)<1)
    {
        while(x1<=x2)
        {
            x1 = x1+1;
            y1 = y1+m;
            putpixel(round(x1), round(y1), 15);
        }
    }
    else
    {
        while(y1<=y2)
        {
            y1 = y1+1;
            x1 = x1+(1/m);
            putpixel(round(x1), round(y1), 15);
        }
    }
    getch();
    closegraph();
    
    return 0;
}