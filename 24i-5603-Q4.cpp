#include <iostream>
using namespace std;

class Customer {
public:
    int id;
    char name[50];
    int tickets;
    Customer* next;

    Customer(int i, const char* n, int t) {
        id = i;
        int k = 0;
        while (n[k] != '\0') {
            name[k] = n[k];
            k++;
        }
        name[k] = '\0';
        tickets = t;
        next = NULL;
    }
};

class Queue {
    Customer* front;
    Customer* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int id, const char* name, int tickets) {
        Customer* temp = new Customer(id, name, tickets);
        if (!rear) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (!front)
            return;
        Customer* temp = front;
        front = front->next;
        if (!front)
            rear = NULL;
        delete temp;
    }

    void display() {
        Customer* curr = front;
        while (curr) {
            cout << curr->id << " " << curr->name << " " << curr->tickets << endl;
            curr = curr->next;
        }
    }

    ~Queue() {
        while (front)
            dequeue();
    }
};

class PriorityQueue {
    Customer* front;

public:
    PriorityQueue() {
        front = NULL;
    }

    void enqueue(int id, const char* name, int tickets) {
        Customer* temp = new Customer(id, name, tickets);
        if (!front || tickets > front->tickets) {
            temp->next = front;
            front = temp;
            return;
        }
        Customer* curr = front;
        while (curr->next && curr->next->tickets >= tickets)
            curr = curr->next;
        temp->next = curr->next;
        curr->next = temp;
    }

    void dequeue() {
        if (!front)
            return;
        Customer* temp = front;
        front = front->next;
        delete temp;
    }

    void display() {
        Customer* curr = front;
        while (curr) {
            cout << curr->id << " " << curr->name << " " << curr->tickets << endl;
            curr = curr->next;
        }
    }

    ~PriorityQueue() {
        while (front)
            dequeue();
    }
};

int main() {
    Queue q;
    q.enqueue(1, "Ali", 2);
    q.enqueue(2, "Sara", 4);
    q.enqueue(3, "Hamza", 1);
    cout << "Normal Queue:" << endl;
    q.display();

    q.dequeue();
    cout << "After Dequeue:" << endl;
    q.display();

    PriorityQueue pq;
    pq.enqueue(1, "Ali", 2);
    pq.enqueue(2, "Sara", 4);
    pq.enqueue(3, "Hamza", 1);
    cout << "Priority Queue:" << endl;
    pq.display();

    pq.dequeue();
    cout << "After Priority Dequeue:" << endl;
    pq.display();

    return 0;
}
