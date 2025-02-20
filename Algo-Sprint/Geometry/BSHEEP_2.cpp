#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;

    // bool operator==(Point const &t) const
    // {
    //     return x == t.x && y == t.y;
    // }
};

Point p0;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

Point next_to_top(stack<Point> &s)
{
    Point tmp = s.top();
    s.pop();
    Point res = s.top();
    s.push(tmp);
    return res;
}
int orientation(Point a, Point b, Point c)
{
    int val = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);

    if (val == 0)
    {
        return 0;
    }

    return val > 0 ? 1 : 2;
}

int dist(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool compare(Point &p1, Point &p2)
{

    int o = orientation(p0, p1, p2);
    if (o == 0)
        return (dist(p0, p2) > dist(p0, p1)) ? -1 : 1;

    return o == 2 ? -1 : 1;
}

void swap(vector<Point> &points, int x, int xmin)
{
    Point tmp = points[xmin];
    points[xmin] = points[x];
    points[x] = tmp;
}

stack<Point> convex_hull(vector<Point> &points, int n)
{

    int ymin = 0, min_index = 0;

    for (auto i = 1; i < n; i++)
    {

        if (ymin > points[i].y || (ymin == points[i].y && points[i].x < points[min_index].x))
        {
            ymin = points[i].y;
            min_index = i;
        }
    }

    swap(points, 0, min_index);
    p0 = points[0];

    sort(points.begin() + 1, points.end(), compare);


    int m = 1;
    for (auto i = 1; i < n; i++)
    {
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
        {
            i++;
        }
        points[m] = points[i];
        m++;
    }

    stack<Point> s;
    s.push(points[0]);
    s.push(points[1]);

    if (m > 2)
    {
        s.push(points[2]);
    }
    // else
    // {
    //     stack<Point> tmp;
    //     return tmp;
    // }

    for (auto i = 3; i < m; i++)
    {
        while (s.size()>1 && orientation(next_to_top(s), s.top(), points[i]) != 2)
        {
            s.pop();
        }
        s.push(points[i]);
    }

    return s;
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
        vector<Point> points;
        unordered_map<pair<int,int>, int, pair_hash> m;

        if (n == 1)
        {
            cout << "0.00" << endl;
            cout << "1" << endl;
            continue;
        }
        for (auto i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            Point p;
            p.x = x;
            p.y = y;
            points.push_back(p);
        }

        for (auto i = 0; i < n; i++)
        {
            auto p = make_pair(points[i].x, points[i].y);
            m[p] = i + 1;
        }

        stack<Point> s = convex_hull(points, n);

        // while (s.size() > 0)
        // {
        //     auto p = s.top();
        //     cout << m[{p.x,p.y}] << " ";
        //     s.pop();
        // }
        int c = 0;
        int d = 0;
        while (!s.empty())
        {
			points[c] = s.top();
			s.pop();
			if(c>0)
			{
				d += sqrt(dist(points[c],points[c-1]));
			} 
			c++;
		}
        d += sqrt(dist(points[0],points[c-1]));
        for(int i=c-1;i>-1;i--)
		{
			printf("%d ",m[make_pair(points[i].x,points[i].y)]);
		}
		cout << endl << endl;
    }

    return 0;
}
