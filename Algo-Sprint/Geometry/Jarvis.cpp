#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

int orientation(Point p1, Point p2, Point p3)
{
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);

    if (val == 0)
        return 0;

    return val > 0 ? 1 : 2;
}

void convex_hull_jarvis(Point points[], int n)
{
    if (n < 3)
        return;

    int l = 0;

    for (auto i = 1; i < n; i++)
    {
        if (points[i].x < points[l].x)
        {
            l = i;
        }
    }

    int p = l, q;

    vector<Point> hull;
    do
    {
        hull.push_back(points[p]);

        q = (p + 1) % n;
        for (auto i = 0; i < n; i++)
        {
            if (orientation(points[p], points[i], points[q]) == 2)
            {
                q = i;
            }
        }
        p = q;
    } while (p != l);

    for (auto i = 0; i < hull.size(); i++)
    {
        cout << hull[i].x << "," << hull[i].y << endl;
    }
}

int main()
{
    // your code goes here
    Point points[] = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};
    int n = sizeof(points) / sizeof(points[0]);
    convex_hull_jarvis(points, n);
    return 0;

    return 0;
}
