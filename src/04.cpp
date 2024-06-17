// Mid Point Algorithm to make an ellipse
# include <stdio.h>
# include <graphics.h>
# include <math.h>
# include <conio.h>
# include <stdlib.h>

void drawPixel(int xc,int yc,int x,int y)
{
    putpixel(xc+x,yc+y,RED);
    putpixel(xc-x,yc+y,RED);
    putpixel(xc+x,yc-y,RED);
    putpixel(xc-x,yc-y,RED);
}

void mid_point_ellipse(int xc,int yc,int a, int b)
{
    int p10=b*b+a*a/4-a*a*b;
    int x0=0;
    int y0=b;
    while(x0*b*b<=y0*a*a)
    {
        x0=x0+1;
        if(p10<0)
        {
            p10+=2*b*b*x0+b*b;
        }
        else
        {
            y0=y0-1;
            p10+=2*b*b*x0-2*a*a*y0+b*b;
        }
        drawPixel(xc,yc,x0,y0);
    }
    int p20=b*b*(x0+0.5)*(x0+0.5)+a*a*(y0-1)*(y0-1)-a*a*b*b;
    while(y0>=0)
    {
        y0=y0-1;
        if(p20>0)
        {
            p20+=-2*a*a*y0+a*a;
        }
        else
        {
            x0=x0+1;
            p20+=2*b*b*x0-2*a*a*y0+a*a;
        }
        drawPixel(xc,yc,x0,y0);
    }
}

int main()
{
    int gm, x, y, gd = DETECT;
    int xc, yc, a, b;
    char path[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    initgraph(&gd, &gm, path);
    
    printf("Enter the center of the ellipse: ");
    scanf("%d %d", &xc, &yc);
    printf("Enter the semi major axis and semi minor axis of the ellipse: ");
    scanf("%d %d", &a,&b);
    mid_point_ellipse(xc, yc, a,b);
    
    getch();
    closegraph();
    
    return 0;
}