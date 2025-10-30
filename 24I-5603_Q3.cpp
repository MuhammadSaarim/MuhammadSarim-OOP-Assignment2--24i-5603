#include <iostream>
using namespace std;

class Book {
public:
    int BookID;
    char Title[50];
    char Author[50];
    Book(int id, const char* t, const char* a) {
        BookID = id;
        int i = 0;
        while (t[i] != '\0') { Title[i] = t[i]; i++; }
        Title[i] = '\0';
        i = 0;
        while (a[i] != '\0') { Author[i] = a[i]; i++; }
        Author[i] = '\0';
    }
};

class Node {
public:
    Book* data;
    Node* next;
    Node* prev;
    Node(Book* b) {
        data = b;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    void addAtBeginning(Book* b) {
        Node* newNode = new Node(b);
        if (!head) head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void addAtEnd(Book* b) {
        Node* newNode = new Node(b);
        if (!tail) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void addAtPosition(Book* b, int pos) {
        if (pos <= 1) { addAtBeginning(b); return; }
        Node* temp = head;
        int i = 1;
        while (temp && i < pos - 1) { temp = temp->next; i++; }
        if (!temp || !temp->next) { addAtEnd(b); return; }
        Node* newNode = new Node(b);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    void deleteByID(int id) {
        Node* temp = head;
        while (temp && temp->data->BookID != id) temp = temp->next;
        if (!temp) return;
        if (temp == head) head = head->next;
        if (temp == tail) tail = tail->prev;
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp->data;
        delete temp;
    }
    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data->BookID << " - " << temp->data->Title << " by " << temp->data->Author << endl;
            temp = temp->next;
        }
    }
    void displayBackward() {
        Node* temp = tail;
        while (temp) {
            cout << temp->data->BookID << " - " << temp->data->Title << " by " << temp->data->Author << endl;
            temp = temp->prev;
        }
    }
    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp->data;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    DoublyLinkedList list;
    Book* b1 = new Book(1, "BookA", "AuthorA");
    Book* b2 = new Book(2, "BookB", "AuthorB");
    Book* b3 = new Book(3, "BookC", "AuthorC");
    Book* b4 = new Book(4, "BookD", "AuthorD");

    list.addAtEnd(b1);
    list.addAtEnd(b2);
    list.addAtEnd(b3);
    list.addAtPosition(b4, 2);

    cout << "List (Forward):" << endl;
    list.displayForward();

    cout << "\nList (Backward):" << endl;
    list.displayBackward();

    cout << "\nAfter deleting BookID 3:" << endl;
    list.deleteByID(3);
    list.displayForward();

    return 0;
}
