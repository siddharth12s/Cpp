// #include <bits/stdc++.h>
// #include <iomanip>
// // using namespace std;

// struct Point
// {
//     int x;
//     int y;
// };

// int orientation(Point p1, Point p2, Point p3)
// {

//     int val = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);

//     if (val == 0)
//     {
//         return 0; // for collinear
//     }

//     return val > 0 ? 1 : -1; // 1 for clockwise -1 for counter clockwise
// }

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

// std::pair<int,std::vector<int>> convexHull(Point points[], int n)
// {
//     std::vector<int> hull;

//     if (n < 3)
//     {
//         // std::cout << 0;
//     }

//     int min_index = 0;

//     for (auto i = 0; i < n; i++)
//     {
//         if (points[i].x < points[min_index].x)
//         {
//             min_index = i;
//         }
//     }

//     // std::swap(points[0], points[min_index]);

//     int p = min_index, q;

//     do
//     {
//         hull.push_back(p + 1);

//         q = (p + 1) % n; // circular indexing (finding next point after p)
//         for (int i = 0; i < n; i++)
//         {

//             if (orientation(points[p], points[i], points[q]) == -1)
//             {
//                 q = i;
//             }
//         }

//         p = q;

//     } while (p != min_index);

//     // std::cout << std::setprecision(4);
//     auto circum = circumference(hull, points);
//     // std::cout << 0.0 << std::endl;
//     // std::cout << circum << std::endl;
//     // // std::cout << circum << std::endl;
//     // std::cout << circum << std::endl;

//     std::cout << std::fixed << std::setprecision(2) << circum << std::endl;

//     for (int i = 0; i < hull.size(); i++)
//         std::cout << hull[i] << " ";

//     return {circum, hull};
// }

// int main()
// {
//     // your code goes here
//     int t;
//     std::cin >> t;
//     while (t--)
//     {
//         int n;
//         std::cin >> n;
//         Point points[n];

//         std::cout << std::setprecision(4);

//         for (auto i = 0; i < n; i++)
//         {
//             std::cin >> points[i].x >> points[i].y;
//         }

//         auto ans = convexHull(points, n);
//         std::cout << std::endl<<std::endl;
//         // std::cout << ans.first << std::endl;
//         // std::cout << std::fixed << std::setprecision(4) << ans.first << std::endl;

//         // for(auto x : ans.second){
//         //     std::cout << x << " ";
//         // }
//     }


//     return 0;
// }

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define si(a) scanf("%d",&a)
#define sd(a) scanf("%lf",&a)
#define FOR(i,j) for(int i=0;i<j;i++)
#define FORR(i,j,k) for(int i=j;i<k;i++)
using namespace std;
struct node
{
	double x,y;
}points[100005];
stack<node> s;
node p0;
map <pair<double,double> ,int> m;
vector<pair<double,double> > v;
void Swap(node &p,node &q)
{
		node tmp;
		tmp = p;
		p = q;
		q = tmp;
}
void findmin(int n)
{
	int l=0;
	p0 = points[0];
	FORR(i,1,n)
	{
		if(p0.y > points[i].y || (p0.y == points[i].y && p0.x > points[i].x ))
		{
			p0 = points[i];
			l = i;		
		}
	}
	if(l != 0)
	Swap(points[0],points[l]);
	//cout << points[0].x << points[0].y;
}
node nextToTop(stack<node>&s)
{
	node p1 = s.top();
	s.pop();
	node p2 = s.top();
	s.push(p1);
	return p2;
}
double dist(node p,node q)
{
	return (q.x-p.x)*(q.x-p.x) + (q.y-p.y)*(q.y-p.y);
}
int orientation(node p,node q,node r)
{
	int ans = (q.y-p.y)*(r.x-q.x) - (r.y - q.y)*(q.x-p.x);
	if( ans == 0) // colinear
		return 0;
	return ans < 0 ? 2 : 1; // anticlock / clockwise
}
int compare(const void *vp1,const void *vp2)
{
	node *p1 = (node *)vp1;
	node *p2 = (node *)vp2;
	int orient = orientation(p0,*p1,*p2);
	if(orient == 0) // colinear
		return (dist(p0,*p2) > dist(p0,*p1)) ? -1 : 1;
	return (orient == 2) ? -1 : 1;
} 	 	
void convexHull(int n)
{
	qsort(&points[1],n-1,sizeof(node),compare);
	//FORR(i,0,n)
	//	cout << points[i].x << " " << points[i].y << endl;
	int m =1;
	// taking only one points on colinear points i.e. farthest one
	FORR(i,1,n)
	{
		while(i<n-1 && !orientation(p0,points[i],points[i+1]))
			i++;
		points[m++] = points[i];
	}
	s.push(points[0]);
	s.push(points[1]);
	if(m>2)
	s.push(points[2]);
	else
		return;
	FORR(i,3,m)
	{
		while(orientation(nextToTop(s),s.top(),points[i]) != 2)
			s.pop();
		s.push(points[i]);
	}
}
int main()
{
	int t,n;
	double x0,y0,i0,j0;
	si(t);
	while(t--)
	{
		v.clear();
		m.clear();
		si(n);
		int c=0;
		FORR(i,0,n)
		{
			sd(x0);sd(y0);
			if(m.find(mp(x0,y0)) == m.end())
				{
					m[mp(x0,y0)] = i+1;
					points[c].x = x0;
					points[c++].y = y0;
				}
		}
		n=c;
		findmin(n);
		if(n == 1)
		{
			printf("0.00\n1\n\n");
			continue;
		}
		//cout << points[0].x << points[0].y;
		convexHull(n);
		double d = 0;
		c=0;
		while(!s.empty())
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
		printf("%.2f\n",d);
		for(int i=c-1;i>-1;i--)
		{
			printf("%d ",m[mp(points[i].x,points[i].y)]);
		}
		cout << endl << endl;
	}
	return 0;
}