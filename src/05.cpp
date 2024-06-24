// 2-D Transformation
# include <stdio.h>
# include <graphics.h>
# include <math.h>
# include <conio.h>
# include <stdlib.h>
#include <iostream>

void init(float A[3][3]) {
    float temp[3][3] = {{100, 100, 1}, {200, 100, 1}, {200, 200, 1}};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            A[i][j] = temp[i][j];
        }
    }
}

void translation(float A[3][3])
{
    float tx, ty;
    tx=50, ty=50;
    for (int i=0;i<3;i++)
    {
        A[i][0] = A[i][0] + tx;
        A[i][1] = A[i][1] + ty;
    }

}

void scaling(float A[3][3])
{
    float sx,sy;
    float pivot_x=80,pivot_y=50;
    sx=2,sy=2;
    for (int i=0;i<3;i++)
    {
        A[i][0] = A[i][0] * sx+pivot_x*(1-sx);
        A[i][1] = A[i][1] * sy + pivot_y*(1-sy);
    
    }
}

void rotation(float A[3][3])
{
    float theta=30;
    float pivot_x=80,pivot_y=80;
    theta=3.14*theta/180;
    putpixel(pivot_x,pivot_y,WHITE);
    for (int i=0;i<3;i++)
    {
        float x = A[i][0];
        float y = A[i][1];
        A[i][0] = x*cos(theta) - y*sin(theta)+pivot_x*(1-cos(theta))+pivot_y*sin(theta);
        A[i][1] = x*sin(theta) + y*cos(theta)+pivot_y*(1-cos(theta))-pivot_x*sin(theta);
    }
}

void shearing(float A[3][3])
{
    float shx,shy;
    shx=0.5,shy=0.5;
    for (int i=0;i<3;i++)
    {
        float x = A[i][0];
        float y = A[i][1];
        A[i][0] = A[i][0] + shx*y;
        A[i][1] = A[i][1] + shy*x;
    }
}

void reflection(float A[3][3])
{
    float x1 = 0, y1 = 0; // Start point of the line
    float x2 = 200, y2 = 300; // End point of the line
    // Calculate slope of the line
    float m = (y2 - y1) / (x2 - x1);
    // Calculate y-intercept of the line
    float c = y1 - m * x1;

    // Calculate denominator of the reflection formula
    float den = 1 + m * m;

    // Draw the original line (if using graphics library)
    setcolor(RED);
    line(x1, y1, x2, y2);

    // Reflect each point in matrix A across the line
    for (int i = 0; i < 3; ++i) {
        float x = A[i][0];
        float y = A[i][1];

        // Apply reflection formula
        A[i][0] = (x * (1 - m * m) + 2 * m * y - 2 * c * m) / den;
        A[i][1] = ((-1+m * m) * y + 2 * m * x + 2 * c * m) / den;
    }
    setcolor(WHITE);
}

void draw(float A[3][3])
{
    line(A[0][0],A[0][1],A[1][0],A[1][1]);
    line(A[1][0],A[1][1],A[2][0],A[2][1]);
    line(A[2][0],A[2][1],A[0][0],A[0][1]);
}

int main()
{
    int gm, gd = DETECT,select;
    float A[3][3];
    char path[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    initgraph(&gd, &gm, path);
    while(true)
    {
    init(A);
    printf("Enter the 2d transformation you want to perform\n");
    printf("1.Translation\n2.Scaling\n3.Rotation\n4.Shearing\n5.Reflection\n6.Exit\n");
    scanf("%d",&select);
    cleardevice();
    draw(A);
    switch(select)
    {
        case 1:
            translation(A);
            break;
        case 2:
            scaling(A);
            break;
        case 3:
            rotation(A);
            break;
        case 4:
            shearing(A);
            break;
        case 5:
            reflection(A);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    draw(A);
    }
    
    getch();
    closegraph();
    
    return 0;
}