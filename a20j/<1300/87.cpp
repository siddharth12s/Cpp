#include <bits/stdc++.h>
using namespace std;


int maxRibbonPieces(int n, int a, int b, int c) {
    if (n == 0) {
        return 0;
    }

    if (n < 0) {
        return -1; // Invalid cut
    }

    int pieces = -1;

    int cutA = maxRibbonPieces(n - a, a, b, c);
    int cutB = maxRibbonPieces(n - b, a, b, c);
    int cutC = maxRibbonPieces(n - c, a, b, c);

    if (cutA >= 0) pieces = max(pieces, 1 + cutA);
    if (cutB >= 0) pieces = max(pieces, 1 + cutB);
    if (cutC >= 0) pieces = max(pieces, 1 + cutC);

    return pieces;
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int result = maxRibbonPieces(n, a, b, c);

    if (result < 0) {
        cout << "0\n"; // No valid cut found
    } else {
        cout << result << endl;
    }

    return 0;
}
