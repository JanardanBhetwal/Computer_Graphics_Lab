#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>

using namespace std;

void drawAxes() {
    int midx = getmaxx() / 2;
    int midy = getmaxy() / 2;
    line(0, midy, getmaxx(), midy); // X-axis
    line(midx, 0, midx, getmaxy()); // Y-axis
}

void draw3DBar(int l, int t, int r, int b, int depth, int topflag) {
    bar3d(l, t, r, b, depth, topflag);
}

void translate3DBar(int l, int t, int r, int b, int depth, int topflag, int tx, int ty) {
    draw3DBar(l + tx, t + ty, r + tx, b + ty, depth, topflag);
}

void scale3DBar(int l, int t, int r, int b, int depth, int topflag, float sx, float sy) {
    draw3DBar(l * sx, t * sy, r * sx, b * sy, depth, topflag);
}

void rotate3DBar(int l, int t, int r, int b, int depth, int topflag, float angle) {
    angle = (angle * 3.14159) / 180;
    int l1 = l * cos(angle) - t * sin(angle);
    int t1 = t * cos(angle) + l * sin(angle);
    int r1 = r * cos(angle) - b * sin(angle);
    int b1 = b * cos(angle) + r * sin(angle);
    draw3DBar(l1, t1, r1, b1, depth, topflag);
}

void shear3DBar(int l, int t, int r, int b, int depth, int topflag, int shx, int shy) {
    int l1 = l + shx * t;
    int t1 = t + shy * l;
    int r1 = r + shx * b;
    int b1 = b + shy * r;
    draw3DBar(l1, t1, r1, b1, depth, topflag);
}

void reflect3DBar(int l, int t, int r, int b, int depth, int topflag) {
    // Reflect about the x-axis
    int midy = getmaxy() / 2;
    int midx=getmaxx()/2;
    int new_l = midx - (l - midx);
    int new_r = midx - (r - midx);

    draw3DBar(new_l,t,new_r,b, depth, topflag);
}


int main() {
    int choice;
    do {
        cout << "Enter 1. for translation" << endl;
        cout << "Enter 2. for scaling" << endl;
        cout << "Enter 3. for rotation" << endl;
        cout <<"Enter 4. for shear" << endl;
        cout <<"Enter 5. for reflection" << endl;
        cout << "Enter 6. for exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;

        int gm, x, y, gd = DETECT;
            char path[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    initgraph(&gd, &gm, path);

        drawAxes();

        int midx = getmaxx() / 2;
        int midy = getmaxy() / 2;
        int l = midx + 50, t = midy - 70, r = midx + 100, b = midy - 20, depth = 50, topflag = 1;

        draw3DBar(l, t, r, b, depth, topflag);

        switch (choice) {
            case 1: {
                int tx, ty;
                cout << "Enter the translating factors" << endl;
                cin >> tx >> ty;
                translate3DBar(l, t, r, b, depth, topflag, tx, ty);
                break;
            }
            case 2: {
                float sx, sy;
                cout << "Enter the scaling factors" << endl;
                cin >> sx >> sy;
                scale3DBar(l, t, r, b, depth, topflag, sx, sy);
                break;
            }
            case 3: {
                float angle;
                cout << "Enter the angle" << endl;
                cin >> angle;
                rotate3DBar(l, t, r, b, depth, topflag, angle);
                break;
            }
            case 4: {
                int shx, shy;
                cout << "Enter the shearing factors" << endl;
                cin >> shx >> shy;
                shear3DBar(l, t, r, b, depth, topflag, shx, shy);
                break;
            }
            // implement reflection about x-axis only
            case 5: {
                reflect3DBar(l, t, r, b, depth, topflag);
                break;
            }

            default:
                cout << "Invalid choice!" << endl;
        }

        getch();
        cleardevice();
    } while (choice != 6);
closegraph();
    return 0;
}
