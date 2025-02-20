#include<bits/stdc++.h> 
using namespace std;


// struct Event{
//     int open;
//     int x, ymin, ymax;

//     Event(int _x,int _ymin, int _ymax, int _open){
//         x = _x;
//         ymin = _ymin;
//         ymax = _ymax;
//         open = _open;
//     }

//     bool operator < (const Event &e) const {
//         return x < e.x;
//     }
// };

// struct Node {
//     int cnt;
//     int total;
// };


// class Segment_Tree
// {
// private:
//     vector<Node> tree;
//     vector<int> count;
//     vector<int> active_y_coords;

//     void build(int start, int end, int node){
//         if(start == end){
//             tree[node] = {0,0};
//             return;
//         }
//         int mid = start + (end - start) / 2;
//         build(start, mid, node * 2);
//         build(mid + 1, end, node * 2 + 1);
//     }


//     void update(int node,int start,int end, int l, int r,int val){
//         if(r<start or l>end){
//             return;
//         }

//         if(start<=l and r<=end){
//             tree[node].cnt += val;
//         }else{
//             int mid = start + (end - start) / 2;
//             update(node * 2, start, mid, l, r, val);
//             update(node * 2 + 1, mid + 1, end, l, r, val);

//         }

//         if(tree[node].cnt>0){
//             tree[node].total = active_y_coords[end + 1] - active_y_coords[start];
//         }else{
//             tree[node].total = tree[node * 2].total + tree[node * 2 + 1].total;
//         }
//     }

// public:
//     Segment_Tree(){
//     }
//     Segment_Tree(vector<int>& activey_coords) : active_y_coords(activey_coords) {
//         int n = activey_coords.size();
//         tree.resize(4 * n);
//         count.resize(n, 0);
//     }

//     void update(int l, int r, int val) {
//         update(1, 0, active_y_coords.size() - 2, l, r - 1, val);
//     }

//     int query() {
//         return tree[1].total;
//     }
// };

// int main(){

//     int t;
//     cin >> t;
//     vector<Event> event;
//     set<int> unique_y_coords;

//     // edges.clear();

//     while (t--)
//     {
//         int x1, y1, x2, y2;
//         cin >> x1 >> y1 >> x2 >> y2;

//         event.push_back(Event(x1, y1, y2, 1));
//         event.push_back(Event(x2, y1, y2, -1));

//         unique_y_coords.insert(y1);
//         unique_y_coords.insert(y2);
//     }

//     sort(event.begin(), event.end());

//     // Sorted y coords for range query of height of rectangle
//     vector<int> y_coords(unique_y_coords.begin(), unique_y_coords.end());

//     Segment_Tree  st_obj(y_coords);

//     long long area = 0;
//     int prevX = event[0].x;

//     for (const auto& e : event) {
//         area += st_obj.query() * (e.x - prevX);
//         prevX = e.x;
//         int idx1 = lower_bound(y_coords.begin(), y_coords.end(), e.ymin) - y_coords.begin();
//         int idx2 = lower_bound(y_coords.begin(), y_coords.end(), e.ymax) - y_coords.begin();
//         st_obj.update(idx1, idx2, e.open);
//     }

//     cout<< area<<endl;
//     return 0;
// }

#include <vector>

struct Rectangle {
  int x1, y1, x2, y2;
};

struct SegmentTreeNode {
  int y_start, y_end, count; // count: number of active rectangles in the interval
  SegmentTreeNode* left;
  SegmentTreeNode* right;
};

SegmentTreeNode* buildTree(const std::vector<Rectangle>& rectangles, int low, int high) {
  if (low > high) return nullptr;

  SegmentTreeNode* node = new SegmentTreeNode();
  node->y_start = rectangles[low].y1;
  node->y_end = rectangles[high].y2;
  node->count = 0;

  if (low == high) {
    // Leaf node, represents a single rectangle
    node->left = node->right = nullptr;
  } else {
    int mid = low + (high - low) / 2;
    node->left = buildTree(rectangles, low, mid);
    node->right = buildTree(rectangles, mid + 1, high);
  }

  return node;
}

void update(SegmentTreeNode* node, int y, int delta) {
  if (!node) return;

  if (y >= node->y_start && y < node->y_end) {
    node->count += delta;

    // Propagate the change if the entire interval is active/inactive
    if (node->count == node->y_end - node->y_start + 1) {
      update(node->left, node->left->y_start, delta);
      update(node->right, node->right->y_start, delta);
    } else if (node->count == 0) {
      update(node->left, node->left->y_start, -delta);
      update(node->right, node->right->y_start, -delta);
    }
  }
}

int query(SegmentTreeNode* node, int y1, int y2) {
  if (!node || y2 < node->y_start || y1 > node->y_end) return 0;

  if (y1 <= node->y_start && y2 >= node->y_end) {
    return (node->y_end - node->y_start + 1) * node->count;
  }

  return query(node->left, y1, y2) + query(node->right, y1, y2);
}

int calculateUnionArea(const std::vector<Rectangle>& rectangles) {
  // Sort rectangles by y1 (bottom left corner y-coordinate)
  std::vector<Rectangle> sorted_rectangles = rectangles;
  std::sort(sorted_rectangles.begin(), sorted_rectangles.end(), 
           [](const Rectangle& a, const Rectangle& b) { return a.y1 < b.y1; });

  // Build segment tree based on sorted y-coordinates
  SegmentTreeNode* root = buildTree(sorted_rectangles, 0, sorted_rectangles.size() - 1);

  int total_area = 0;
  for (const Rectangle& rect : sorted_rectangles) {
    // Update the segment tree for the active area of the current rectangle
    update(root, rect.y1, 1);
    update(root, rect.y2, -1);

    // Query the current total active area and accumulate
    total_area += query(root, 0, INT_MAX); // Query for all remaining y-coordinates
  }

  return total_area;
}

int main() {
  std::vector<Rectangle> rectangles = {
      {1, 1, 4, 4},
      {2, 3, 5, 5},
      {3, 0, 5, 6}
  };

  int union_area = calculateUnionArea(rectangles);
  printf("Area of the union of rectangles: %d\n", union_area);

  return 0;
}
