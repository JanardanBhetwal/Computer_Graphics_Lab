// Implement cohen sutherland line clipping algorithm
# include <stdio.h>
# include <graphics.h>
# include <math.h>
# include <conio.h>
# include <stdlib.h>

void getCode(float x,float y,float xmin,float ymin,float xmax,float ymax,float code[])
{
    if(y>ymax)
        code[0]=1;
    else
        code[0]=0;
    if(y<ymin)
        code[1]=1;
    else
        code[1]=0;
    if(x>xmax)
        code[2]=1;
    else
        code[2]=0;
    if(x<xmin)
        code[3]=1;
    else
        code[3]=0;
}

void cohen_sutherland(float x1,float y1,float x2,float y2,float xmin,float ymin,float xmax,float ymax)
{
    int i;
    float code1[4],code2[4],flag=0,sum=0,m,xtemp,ytemp;
    if(x1==x2)
    {
        printf("Slope cannot be calculated.");
        exit(0);
    }
    m=(y2-y1)/(x2-x1);
    setcolor(RED);
    rectangle(xmin,ymin,xmax,ymax);
    setcolor(WHITE);
    getCode(x1,y1,xmin,ymin,xmax,ymax,code1);
    getCode(x2,y2,xmin,ymin,xmax,ymax,code2);
    for(i=0;i<4;i++)
    {
        if((code1[i]+code2[i])!=0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    { 
        printf("The line lies entirely inside the window");
        line(x1,y1,x2,y2);
    }
    else
    {
        sum=0;
        for(i=0;i<4;i++)
        {
            sum+=code1[i]*code2[i];
        }
        if(sum!=0)
        {
            printf("The line lies entirely outside the window");
        }
        else
        {
            printf("The line lies partially inside the window");
            if(code1[3]==1)
            {
                xtemp=xmin;
                ytemp=y1+m*(xmin-x1);
                if(ytemp<ymin)
                {
                    ytemp=ymin;
                    xtemp=x1+(ymin-y1)/m;
                }
                else if(ytemp>ymax)
                {
                    ytemp=ymax;
                    xtemp=x1+(ymax-y1)/m;
                }
                x1=xtemp;
                y1=ytemp;
            }
            else if(code1[2]==1)
            {
                xtemp=xmax;
                ytemp=y1+m*(xmax-x1);
                if(ytemp<ymin)
                {
                    ytemp=ymin;
                    xtemp=x1+(ymin-y1)/m;
                }
                else if(ytemp>ymax)
                {
                    ytemp=ymax;
                    xtemp=x1+(ymax-y1)/m;
                }
                x1=xtemp;
                y1=ytemp;
            }
            else if(code1[0]==1)
            {
                ytemp=ymax;
                xtemp=x1+(ymax-y1)/m;
                x1=xtemp;
                y1=ytemp;
            }
            else if(code1[1]==1)
            {
                ytemp=ymin;
                xtemp=x1+(ymin-y1)/m;
                x1=xtemp;
                y1=ytemp;
            }
            if (code2[3]==1)
            {
                xtemp=xmin;
                ytemp=y2+m*(xmin-x2);
                if(ytemp<ymin)
                {
                    ytemp=ymin;
                    xtemp=x2+(ymin-y2)/m;
                }
                else if(ytemp>ymax)
                {
                    ytemp=ymax;
                    xtemp=x2+(ymax-y2)/m;
                }
                x2=xtemp;
                y2=ytemp;
            }
            else if(code2[2]==1)
            {
                xtemp=xmax;
                ytemp=y2+m*(xmax-x2);
                if(ytemp<ymin)
                {
                    ytemp=ymin;
                    xtemp=x2+(ymin-y2)/m;
                }
                else if(ytemp>ymax)
                {
                    ytemp=ymax;
                    xtemp=x2+(ymax-y2)/m;
                }
                x2=xtemp;
                y2=ytemp;
            }
            else if(code2[0]==1)
            {
                ytemp=ymax;
                xtemp=x2+(ymax-y2)/m;
                x2=xtemp;
                y2=ytemp;
            }
            else if(code2[1]==1)
            {
                ytemp=ymin;
                xtemp=x2+(ymin-y2)/m;
                x2=xtemp;
                y2=ytemp;
            }
            if(x1<=xmax && x2<=xmax && y1<=ymax && y2<=ymax && x1>=xmin && x2>=xmin && y1>=ymin && y2>=ymin)
            {
                printf("Line accepted ");
                line(x1,y1,x2,y2);
            }
            else
                printf("Line rejected");
        }
    }
}

int main()
{
    int gm, x, y, gd = DETECT;
    float x1=100,y1=20,x2=200,y2=400,xmin=50,ymin=50,xmax=300,ymax=300;
    char path[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    initgraph(&gd, &gm, path);

    cohen_sutherland(x1,y1,x2,y2,xmin,ymin,xmax,ymax);
    
    
    getch();
    closegraph();
    
    return 0;
}