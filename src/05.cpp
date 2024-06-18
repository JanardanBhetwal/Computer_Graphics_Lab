// 2-D Transformation
# include <stdio.h>
# include <graphics.h>
# include <math.h>
# include <conio.h>
# include <stdlib.h>

int A[3],B[3],C[3],_A[3],_B[3],_C[3];

void init()
{
    A[0]=50;
    A[1]=50;
    A[2]=1; // [x,y,1
    B[0]=100;
    B[1]=50;
    B[2]=1;
    C[0]=75;
    C[1]=100;
    C[2]=1;
    _A[0]=A[0];
    _A[1]=A[1];
    _A[2]=A[2];
    _B[0]=B[0];
    _B[1]=B[1];
    _B[2]=B[2];
    _C[0]=C[0];
    _C[1]=C[1];
    _C[2]=C[2];
}

void draw_triangle()
{
    setcolor(WHITE);
    line(A[0],A[1],B[0],B[1]);
    line(B[0],B[1],C[0],C[1]);
    line(C[0],C[1],A[0],A[1]);
    setcolor(RED);
    line(_A[0],_A[1],_B[0],_B[1]);
    line(_B[0],_B[1],_C[0],_C[1]);
    line(_C[0],_C[1],_A[0],_A[1]);
}

void trans_mul(int A[],int tx,int ty)
{
    int T[3][3]={{1,0,tx},{0,1,ty},{0,0,1}};
    int res[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                res[i][j]+=T[i][k]*A[k][j];
            }
        }
    }
    _A[0]=res[0][0];
    _A[1]=res[1][0];
    _B[0]=res[0][1];
    _B[1]=res[1][1];
    _C[0]=res[0][2];
    _C[1]=res[1][2];
  
    draw_triangle();
}

void translation(int tx,int ty)
{

    draw_triangle();
}

void scaling(int h,int k,int sx,int sy)
{
    _A[0]=h+(A[0]-h)*sx;
    _A[1]=k+(A[1]-k)*sy;
    _B[0]=h+(B[0]-h)*sx;
    _B[1]=k+(B[1]-k)*sy;
    _C[0]=h+(C[0]-h)*sx;
    _C[1]=k+(C[1]-k)*sy;
  
    draw_triangle();
}

int main()
{
    int gm, x, y, gd = DETECT;
    // int tx,ty;
    int h,k,sx,sy;
    char path[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    initgraph(&gd, &gm, path);
    
    init();
    // printf("Enter the translation factor (tx,ty): ");
    // scanf("%d %d",&tx,&ty);
    // translation(tx,ty);
    printf("Enter the scaling factor (h,k,sx,sy): ");
    scanf("%d %d %d %d",&h,&k,&sx,&sy);
    scaling(h,k,sx,sy);
    
    getch();
    closegraph();
    
    return 0;
}