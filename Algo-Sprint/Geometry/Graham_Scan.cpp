#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
};

// In graham scan we have prev,curr,next and if orientation of this is not counter clockwise we remove curr.

// returning prev
Point next_to_top(stack<Point> &s)
{

    Point p = s.top();
    s.pop();
    Point res = s.top();
    s.push(p);
    return res;
}

int orientation(Point p1, Point p2, Point p3)
{
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);

    if (val == 0)
    {
        return 0; // collinear
    }

    return val > 0 ? 1 : -1; // clockwise for 1 and counter clockwise -1
}

Point p0;

bool distance(Point p1, Point p2)
{

    int dist_p1 = (p0.x - p1.x) * (p0.x - p1.x) + (p0.y - p1.y) * (p0.y - p1.y);
    int dist_p2 = (p0.x - p2.x) * (p0.x - p2.x) + (p0.y - p2.y) * (p0.y - p2.y);

    return dist_p2 > dist_p1;
}

static int comparator(Point p1, Point p2)
{
    int orient = orientation(p0, p1, p2);

    // If collinear
    if (orient == 0)
    {
        // return distance(p1, p2) == 1? -1 : 1; // the farthest point will be evaluated first
        return !distance(p1, p2);
    }

    // Sort by counter clockwise orientation
    if (orient == -1)
    {
        return -1;
    }

    // For clockwise
    return 1;
}

void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// double circumference(std::vector<int> hull, Point points[])
// {

//     Point p = points[hull[0] - 1];

//     double circum = 0;

//     for (auto i = 1; i < hull.size(); i++)
//     {
//         double dist = sqrt((points[hull[i] - 1].x - p.x) * (points[hull[i] - 1].x - p.x) + (points[hull[i] - 1].y - p.y) * (points[hull[i] - 1].y - p.y));

//         p = points[hull[i] - 1];
//         circum += dist;
//     }
//     int n = hull.size();
//     circum += sqrt((points[hull[n - 1] - 1].x - points[hull[0] - 1].x) * (points[hull[n - 1] - 1].x - points[hull[0] - 1].x) + (points[hull[n - 1] - 1].y - points[hull[0] - 1].y) * (points[hull[n - 1] - 1].y - points[hull[0] - 1].y));

//     return double(circum);
// }

void convex_hull(Point points[], int n)
{

    int ymin = points[0].y, min=0;

    for (auto i = 1; i < n; i++)
    {

        if (points[i].y < ymin|| (ymin == points[i].y && points[i].x < points[min].x))
        {
            ymin = points[i].y;
            min = i;
        }
    }

    // vector<int> hull;
    swap(points[0], points[min]);
    // hull.push_back(min);
    p0 = points[0];
    // cout << p0.x << p0.y;
    sort(points+1, points + n, comparator);

    // for (auto i = 0; i < n;i++)
    // {
    //     cout << points[i].x << "," << points[i].y << endl;
    // }

    // int m = 1;


    // for (auto i = 1; i < n; i++)
    // {

    //     while (i < n - 1 and orientation(p0, points[i], points[i + 1]) == 0)
    //     {
    //         i++;
    //     }

    //     points[m] = points[i]; // updating points array.
    //     m++;
    // }

    // for(auto x : hull){
    //     cout << x << ",";
    // }

    // if (m < 3)
    //     return;

    // stack<Point> s;
    // s.push(points[0]);
    // s.push(points[1]);
    // s.push(points[2]);

    // for (auto i = 3; i < m; i++)
    // {

    //     while (s.size() > 1 and orientation(next_to_top(s), s.top(), points[i]) != 2)
    //     {
    //         s.pop(); // remove the point which is causing orientation to not be counter clockwise
    //     }

    //     s.push(points[i]);
    // }

    // while (!s.empty())
    // {
    //     Point p = s.top();
    //     std::cout << "(" << p.x << ", " << p.y << ")" << endl;
    //     s.pop();
    // }

    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != -1) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    for (auto p : hull) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }
}

int main()
{
    // your code goes here
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        Point points[n];

        // std::cout << std::setprecision(4);

        for (auto i = 0; i < n; i++)
        {
            std::cin >> points[i].x >> points[i].y;
        }

        convex_hull(points, n);
        std::cout << std::endl;
        // std::cout << ans.first << std::endl;
        // std::cout << std::fixed << std::setprecision(4) << ans.first << std::endl;

        // for(auto x : ans.second){
        //     std::cout << x << " ";
        // }
    }

    return 0;
}
