#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    bool open;
    int x, y1, y2;

    Edge(int _x, int _y1, int _y2, bool op)
    {
        x = _x;
        y1 = _y1;
        y2 = _y2;
        open = op;
    }

    bool operator<(const Edge &e) const
    {
        return x < e.x;
    }
};

int sum[100005] = {0};

int counter[100005] = {0};

void update(int v, int l, int r, int y1, int y2, vector<int> &y_coords, bool open)
{

    if (y_coords[r] < y1 or y_coords[l] > y2)
    {
        return;
    }

    int vertex = 2 * v;
    int mid = l + (r - l) / 2;

    if (y1 <= y_coords[l] && y_coords[r] <= y2)
    {

        counter[v] += open ? 1 : -1;
        if (counter[v])
        {
            sum[v] = y_coords[r] - y_coords[l];
        }
        else
        {
            sum[v] = sum[vertex] + sum[vertex + 1];
        }

        return;
    }

    if (l + 1 >= r)
        return;

    update(vertex, l, mid, y1, y2, y_coords, open);
    update(vertex + 1, mid + 1, r, y1, y2, y_coords, open);

    if (counter[v])
        sum[v] = y_coords[r] - y_coords[l];
    else
        sum[v] = sum[vertex] + sum[vertex + 1];
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    vector<Edge> edges;
    set<int> unique_y_coords;

    // edges.clear();

    while (t--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        edges.push_back(Edge(x1, y1, y2, true));
        edges.push_back(Edge(x2, y1, y2, false));

        unique_y_coords.insert(y1);
        unique_y_coords.insert(y2);
    }

    // Sorted y coords for range query of height of rectangle
    vector<int> y_coords(unique_y_coords.begin(), unique_y_coords.end());

    // sort edges according to x coords
    sort(edges.begin(), edges.end());

    // for(auto e : edges){
    //     cout << e.x << endl;
    // }

    update(1, 1, y_coords.size()-1, edges[0].y1, edges[0].y2, y_coords, edges[0].open);

    int area = 0;
    for (auto i = 1; i < edges.size(); i++)
    {
        area += sum[1] * edges[i].x - edges[i - 1].x;
        update(1, 1, y_coords.size()-1, edges[i].y1, edges[i].y2, y_coords, edges[i].open);
    }

    cout << area;

    return 0;
}
