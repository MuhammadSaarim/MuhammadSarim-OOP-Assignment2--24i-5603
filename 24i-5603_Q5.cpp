#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char d) {
        data = d;
        next = NULL;
    }
};

class LinkedListStack {
    Node* top;
public:
    LinkedListStack() {
        top = NULL;
    }
    void push(char val) {
        Node* temp = new Node(val);
        temp->next = top;
        top = temp;
    }
    void pop() {
        if (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    bool empty() {
        return top == NULL;
    }
    char peek() {
        return top ? top->data : '\0';
    }
    ~LinkedListStack() {
        while (!empty())
            pop();
    }
};

class ArrayStack {
    char* arr;
    int top;
    int capacity;
public:
    ArrayStack(int size) {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }
    void push(char val) {
        if (top < capacity - 1)
            arr[++top] = val;
    }
    void pop() {
        if (top >= 0)
            top--;
    }
    bool empty() {
        return top == -1;
    }
    char peek() {
        return top >= 0 ? arr[top] : '\0';
    }
    ~ArrayStack() {
        delete[] arr;
    }
};

void IterativeChangeLocation(char* Array, int b1, int b2) {
    ArrayStack s(b2 - b1 + 1);
    for (int i = b1; i <= b2; i++)
        s.push(Array[i]);
    for (int i = b1; i <= b2; i++) {
        Array[i] = s.peek();
        s.pop();
    }
}

void IterativePattern(int n) {
    LinkedListStack s;
    for (int i = 1; i <= n; i++) {
        int x = n - i + 1;
        for (int j = 1; j <= i; j++) {
            if (j < i)
                cout << 1 << " ";
            else
                cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    char word[] = {'C', 'O', 'M', 'P', 'U', 'T', 'E', 'R'};
    int b1 = 2, b2 = 6;
    IterativeChangeLocation(word, b1, b2);
    for (int i = 0; i < 8; i++)
        cout << word[i];
    cout << endl;
    int n = 4;
    IterativePattern(n);
    return 0;
}
