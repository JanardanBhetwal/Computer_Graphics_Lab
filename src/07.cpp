#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

void liang_barsky(float x1, float y1, float x2, float y2, float xmin, float ymin, float xmax, float ymax) {
    int i;
    float dx, dy, p[4], q[4], t1 = 0, t2 = 1,t;
    dx = x2 - x1;
    dy = y2 - y1;
    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;
    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;

    for (i = 0; i < 4; i++) {
        if (p[i] == 0) {
            // Line is parallel to the clipping boundary
            if (q[i] < 0) {
                printf("Line is outside the window");
                return;
            }
        } else {
             t = q[i] / p[i];
            if (p[i] < 0) {
                if (t > t1) t1 = t;
            } else {
                if (t < t2) t2 = t;
            }
        }
    }

    if (t1 > t2) {
        printf("Line is outside the window");
        return;
    }

    setcolor(RED);
    rectangle(xmin, ymin, xmax, ymax);
    setcolor(WHITE);
    line(x1+t1*dx, y1+t1*dy, x1+t2*dx, y1+t2*dy);
}

int main() {
    int gm, x, y, gd = DETECT;
    float x1 = 100, y1 = 150, x2 = 400, y2 = 250, xmin = 50, ymin = 50, xmax = 300, ymax = 300;
    char path[] = "C:\\MinGW\\lib\\libbgi.a"; // Ensure the correct path to libbgi.a
    initgraph(&gd, &gm, path);
    
    liang_barsky(x1, y1, x2, y2, xmin, ymin, xmax, ymax);
    
    getch();
    closegraph();
    
    return 0;
}
