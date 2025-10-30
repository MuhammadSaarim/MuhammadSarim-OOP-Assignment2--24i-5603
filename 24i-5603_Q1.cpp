#include <iostream>
using namespace std;

void ChangeLocation(char *arr, int b1, int b2) {
    if (b1 >= b2)
        return;
    char temp = arr[b1];
    arr[b1] = arr[b2];
    arr[b2] = temp;
    ChangeLocation(arr, b1 + 1, b2 - 1);
}

int main() {
    char letters[8] = {'C', 'O', 'M', 'P', 'U', 'T', 'E', 'R'};
    int start = 2;
    int end = 6;
    ChangeLocation(letters, start, end);
    for (int i = 0; i < 8; i++)
        cout << letters[i] << " ";
    return 0;
} 