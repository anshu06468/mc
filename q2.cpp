#include <iostream>
#include <graphics.h>
using namespace std;
// prototype
void drawCircle(int x, int y, int xc, int yc);

int main()
{
    // detect and store the graphics driver preset value if present
    int gd = DETECT, gm;
    int r, xc, yc, pk, x, y;
    char CH[]="";

    initgraph(&gd, &gm, CH);

    cout << "Enter the center co-ordinates\n";
    cin >> xc >> yc;

    cout << "Enter the radius of circle\n";
    cin >> r;

    pk = 1 - r;
    x = 0;
    y = r;

    while (x < y)
    {
        drawCircle(x, y, xc, yc);
        delay(100);
        ++x;
        if (pk < 0)
            pk = pk + (2 * x) + 1;
        else
        {
            --y;
            pk = pk + (2 * x) + 1 - (2 * y);
        }
    }

    closegraph();
}

// definition
void drawCircle(int x, int y, int xc, int yc)
{
    putpixel(x + xc, y + yc, GREEN);
    putpixel(-x + xc, y + yc, GREEN);
    putpixel(x + xc, -y + yc, GREEN);
    putpixel(-x + xc, -y + yc, GREEN);
    putpixel(y + xc, x + yc, GREEN);
    putpixel(y + xc, -x + yc, GREEN);
    putpixel(-y + xc, x + yc, GREEN);
    putpixel(-y + xc, -x + yc, GREEN);
}
