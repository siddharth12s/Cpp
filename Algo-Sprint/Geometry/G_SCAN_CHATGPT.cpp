#include<bits/stdc++.h> 
using namespace std;

struct Point{
  int x, y;

  bool operator == (Point const& t) const {
        return x == t.x && y == t.y;
    }
};

Point p0;

int orientation(Point p1, Point p2, Point p3)
{
  int val = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);

  if(val==0)
    return 0;

  return val > 0 ? 1 : -1;
}

int dist(Point p1, Point p2){
  return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}

bool cw(Point a, Point b, Point c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}

bool collinear(Point a, Point b, Point c) { return orientation(a, b, c) == 0; }

bool compare(Point &p1, Point &p2){
  int orient = orientation(p0, p1, p2);
  if(orient==0){
    return dist(p0, p1) <= dist(p0, p2);
  }

  return orient < 0;
}

void swap(Point &p1, Point &p2){
  Point temp = p2;
  p2 = p1;
  p1 = temp;
}

void convex_hull(vector<Point> &points,int n, bool include_collinear=false){

   p0 = *min_element(points.begin(), points.end(), [](Point a, Point b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });


  // Find bottomost y point
  // int ymin = points[0].y, min_index = 0;
  // for (auto i = 1; i < n;i++){

  //   if(ymin>points[i].y || (ymin==points[i].y && points[i].x<points[min_index].x)){
  //     ymin = points[i].y;
  //     min_index = i;
  //   }
  // }

  //  swap(points[0], p0);
   // Point p0 = points[0];
   sort(points.begin(), points.end(), compare);

   if (include_collinear)
   {
     int i = (int)points.size() - 1;
     while (i >= 0 && collinear(p0, points[i], points.back()))
       i--;
     reverse(points.begin() + i + 1, points.end());
  }


    vector<Point> st;
    for (auto i = 0; i < n;i++){
      while (st.size() > 1 && !cw(st[st.size()-2], st.back(), points[i],include_collinear))
            st.pop_back();
        st.push_back(points[i]);
    }

    if (include_collinear == false && st.size() == 2 && st[0] == st[1])
        st.pop_back();

    points = st;
}

// struct pt {
//     double x, y;
//     bool operator == (pt const& t) const {
//         return x == t.x && y == t.y;
//     }
// };

// int orientation(pt a, pt b, pt c) {
//     double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
//     if (v < 0) return -1; // clockwise
//     if (v > 0) return +1; // counter-clockwise
//     return 0;
// }

// bool cw(pt a, pt b, pt c, bool include_collinear) {
//     int o = orientation(a, b, c);
//     return o < 0 || (include_collinear && o == 0);
// }
// bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

// void convex_hull(vector<pt>& a, bool include_collinear = false) {
//     pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
//         return make_pair(a.y, a.x) < make_pair(b.y, b.x);
//     });
//     sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
//         int o = orientation(p0, a, b);
//         if (o == 0)
//             return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
//                 < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
//         return o < 0;
//     });
//     if (include_collinear) {
//         int i = (int)a.size()-1;
//         while (i >= 0 && collinear(p0, a[i], a.back())) i--;
//         reverse(a.begin()+i+1, a.end());
//     }

//     vector<pt> st;
//     for (int i = 0; i < (int)a.size(); i++) {
//         while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
//             st.pop_back();
//         st.push_back(a[i]);
//     }

//     if (include_collinear == false && st.size() == 2 && st[0] == st[1])
//         st.pop_back();

//     a = st;
// }

int main()  
{
  // your code goes here
  int t;
  cin>>t;
while(t--)
{
    int n;
        std::cin >> n;
        vector<Point> points(n);

        // std::cout << std::setprecision(4);

        for (auto i = 0; i < n; i++)
        {
            std::cin >> points[i].x >> points[i].y;
        }

        convex_hull(points,n, true);
        for(auto x : points){
          cout << x.x << "," << x.y << endl;
        }
        std::cout << std::endl;
    
}

  return 0;
}
