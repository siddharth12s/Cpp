#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;

    bool operator==(Point const &t) const
    {
        return x == t.x && y == t.y;
    }
};

struct point_hash
{
    // template<class T1, class t2>
    std::size_t operator()(const struct Point &t) const
    {
        using std::hash;
        return (hash<int>()(t.x) ^ (hash<int>()(t.y) << 1));
    }
};

Point p0;

int orientation(Point p1, Point p2, Point p3)
{
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);

    if (val == 0)
        return 0;

    return val > 0 ? 1 : -1;
}

int dist(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool acw(Point a, Point b, Point c, bool include_collinear)
{
    int orient = orientation(a, b, c);

    return orient < 0 || (include_collinear && orient == 0);
}

bool collinear(Point a, Point b, Point c)
{
    return orientation(a, b, c) == 0;
}

bool compare(Point &p1, Point &p2)
{

    int orient = orientation(p0, p1, p2);

    if (orient == 0)
    {
        return dist(p0, p1) < dist(p0, p2);
    }

    return orient < 0;
}

void convex_hull(vector<Point> p, int n, bool include_collinear, vector<Point> &hull)
{
    p0 = *min_element(p.begin(), p.end(), [&](Point a, Point b)
                      { return make_pair(a.y, a.x) < make_pair(b.y, b.x); });

    sort(p.begin(), p.end(), compare);

    int i = p.size() - 1;
    if (include_collinear)
    {
        while (i >= 0 && collinear(p0, p[i], p.back()))
        {
            i--;
        }
        reverse(p.begin() + i + 1, p.end());
    }

    vector<Point> v;
    for (auto i = 0; i < n; i++)
    {
        while (v.size() >= 1 && !acw(v[v.size() - 2], v.back(), p[i], include_collinear))
        {
            v.pop_back();
        }
        v.push_back(p[i]);
    }

    if (include_collinear == false && v.size() == 2 && v.back() == v[0])
    {
        v.pop_back();
    }

    hull = v;
}

double circumference(vector<Point> &hull)
{

    Point p = hull[0];

    double circum = 0;

    for (auto i = 1; i < hull.size(); i++)
    {
        double dist = sqrt((hull[i].x - p.x) * (hull[i].x - p.x) + (hull[i].y - p.y) * (hull[i].y - p.y));

        p = hull[i];
        circum += dist;
    }
    int n = hull.size();
    circum += sqrt((hull.back().x - hull[0].x) * (hull.back().x - hull[0].x) + (hull.back().y - hull[0].y) * (hull.back().y - hull[0].y));
    return double(circum);
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<Point> p(n);
        unordered_map<Point, int, point_hash> m;
        for (auto i = 0; i < n; i++)
        {
            cin >> p[i].x >> p[i].y;
        }

        for (auto i = 0; i < n; i++)
        {
            m[p[i]] = i;
        }

        // for(auto X : m){
        //     cout << "(" << X.first.x << "," << X.first.y << ")---->" << X.second << endl;
        // }

        vector<Point> hull;
        convex_hull(p, p.size(), false, hull);

        // for(auto x : p){
        //     cout << x.x << "," << x.y << endl;
        // }

        double circum = circumference(hull);
        std::cout << std::fixed << std::setprecision(2) << circum << std::endl;

        // cout << "hull" << endl;
        for (auto x : hull)
        {
            auto idx = m[x];
            cout << idx + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
