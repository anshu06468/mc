#include <graphics.h>
#include <math.h>
#include <iostream>
using namespace std;
void bezier (int x[4], int y[4])
{
    int gd = DETECT, gm;
	char CH[]="";
    int i;
    double t;

    initgraph (&gd, &gm, CH);

    for (t = 0.0; t < 1.0; t += 0.0005)
    {
        double xt = pow (1-t, 3) * x[0] + 3 * t * pow (1-t, 2) * x[1] + 3 * pow (t, 2) * (1-t) * x[2] + pow (t, 3) * x[3];

        double yt = pow (1-t, 3) * y[0] + 3 * t * pow (1-t, 2) * y[1] + 3 * pow (t, 2) * (1-t) * y[2] + pow (t, 3) * y[3];

        putpixel (xt, yt, WHITE);
    }

    for (i=0; i<4; i++)
        putpixel (x[i], y[i], YELLOW);

}

int main()
{
    int x[4], y[4];
    int i;

    printf ("Enter the x- and y-coordinates of the four control points.\n");
    for (i=0; i<4; i++)
        cin>>x[i]>>y[i];

    bezier (x, y);

    getch();
    closegraph();
    return 0;
}


