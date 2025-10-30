#include <iostream>
using namespace std;

void PrintPattern(int n, int i = 1) {
    if (i > n)
        return;
    int x = n - i + 1;
    for (int j = 1; j <= i; j++) {
        if (j < i)
            cout << 1 << " ";
        else
            cout << x << " ";
    }
    cout << endl;
    PrintPattern(n, i + 1);
}

int main() {
    int n = 4;
    PrintPattern(n);
    return 0;
}
