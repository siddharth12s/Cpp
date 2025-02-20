#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Event
{
    double x, y1, y2, open;
    Event(double _x, double _y1, double _y2, double _open)
    {
        x = _x;
        y1 = _y1;
        y2 = _y2;
        open = _open;
    }
};


bool comp(Event &e1, Event &e2){
    return e1.x < e2.x;
}


int main()
{
    // your code goes here
    int t;
    cin >> t;
    vector<Event> v;
    while (t--)
    {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back(Event(x1, y1, y2, 0));
        v.push_back(Event(x2, y1, y2, 1));
    }

    multiset<double> y_coords;
    sort(v.begin(), v.end(), comp);
    double ans = 0;
    double left_x;
 
    for (auto i = 0; i < v.size(); i++)
    {

        if(i!=0){
            double min_y = *(y_coords.begin());
            double max_y = *(--y_coords.end());
            ans += (v[i].x - left_x) * (max_y - min_y);
        }

        if(v[i].open==0){
            y_coords.insert(v[i].y1);
            y_coords.insert(v[i].y2);
        }else{
            y_coords.erase(y_coords.find(v[i].y1));
            y_coords.erase(y_coords.find(v[i].y2));
        }

        left_x = v[i].x;
    }

    // for(auto x : v){
    //     cout << x.x << "<";
    // }

    // cout << ans << endl;
    std::cout << std::fixed << std::setprecision(2) << ans << endl;
    y_coords.clear();
    return 0;
}
