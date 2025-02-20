#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct Rectangle
{
    int x1, y1, x2, y2;
};

struct SegmentTreeNode
{
    int y_start, y_end, count; // count: number of active rectangles in the interval
};

void buildTree(std::vector<SegmentTreeNode> &tree, const std::vector<Rectangle> &rectangles, int node, int low, int high)
{
    if (low > high)
        return;

    tree[node].y_start = rectangles[low].y1;
    tree[node].y_end = rectangles[high].y2;
    tree[node].count = 0;

    if (low != high)
    {
        int mid = low + (high - low) / 2;
        buildTree(tree, rectangles, 2 * node, low, mid);
        buildTree(tree, rectangles, 2 * node + 1, mid + 1, high);
    }
}

void update(std::vector<SegmentTreeNode> &tree, int node, int y, int low, int high, int delta)
{
    if (y >= tree[node].y_start && y < tree[node].y_end)
    {
        tree[node].count += delta;
    }

    if (low != high)
    {
        int mid = low + (high - low) / 2;
        if (y <= mid)
        {
            update(tree, 2 * node, y, low, mid, delta);
        }
        else
        {
            update(tree, 2 * node + 1, y, mid + 1, high, delta);
        }
    }
}

int query(const std::vector<SegmentTreeNode> &tree, int node, int y1, int y2)
{
    if (y2 < tree[node].y_start || y1 > tree[node].y_end)
        return 0;

    if (y1 <= tree[node].y_start && y2 >= tree[node].y_end)
    {
        return (tree[node].y_end - tree[node].y_start + 1) * tree[node].count;
    }

    int mid = tree[node].y_start + (tree[node].y_end - tree[node].y_start) / 2;
    return query(tree, 2 * node, y1, y2) + query(tree, 2 * node + 1, y1, y2);
}

int calculateUnionArea(const std::vector<Rectangle> &rectangles)
{
    // Sort rectangles by y1 (bottom left corner y-coordinate)
    std::vector<Rectangle> sorted_rectangles = rectangles;
    std::sort(sorted_rectangles.begin(), sorted_rectangles.end(),
              [](const Rectangle &a, const Rectangle &b)
              { return a.y1 < b.y1; });

    // Build segment tree based on sorted y-coordinates
    int n = sorted_rectangles.size();
    std::vector<SegmentTreeNode> tree(4 * n);
    buildTree(tree, sorted_rectangles, 1, 0, n - 1);

    int total_area = 0;
    for (const Rectangle &rect : sorted_rectangles)
    {
        // Update the segment tree for the active area of the current rectangle
        update(tree, 1, rect.y1, 0, n - 1, 1);
        update(tree, 1, rect.y2, 0, n - 1, -1);

        // Query the current total active area and accumulate
        total_area += query(tree, 1, 0, INT_MAX); // Query for all remaining y-coordinates
    }

    return total_area;
}

int main()
{
    std::vector<Rectangle> rectangles = {
        {
            1,
            3,
            4,
            5,
        },
        {3, 1, 7, 4},
        {5, 3, 8, 6}};

    int union_area = calculateUnionArea(rectangles);
    std::cout << "Area of the union of rectangles: " << union_area << std::endl;

    return 0;
}
