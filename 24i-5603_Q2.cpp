#include <iostream>
using namespace std;

class Feature {
public:
    char Name[50];
    Feature(const char n[]) {
        int i = 0;
        while (n[i] != '\0') {
            Name[i] = n[i];
            i++;
        }
        Name[i] = '\0';
    }
    virtual void analyze() = 0;
    virtual ~Feature() {}
};

class LandFeature : public Feature {
public:
    LandFeature(const char n[]) : Feature(n) {}
    void analyze() {
        cout << Name << " - Land feature detected" << endl;
    }
};

class WaterFeature : public Feature {
public:
    WaterFeature(const char n[]) : Feature(n) {}
    void analyze() {
        cout << Name << " - Water feature detected" << endl;
    }
};

class Node {
public:
    int FeatureID;
    Feature* feature;
    Node* next;
    Node(int id, Feature* f) {
        FeatureID = id;
        feature = f;
        next = NULL;
    }
    ~Node() {
        delete feature;
    }
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() {
        head = NULL;
    }
    void insertAtEnd(int id, Feature* f) {
        Node* newNode = new Node(id, f);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    void deleteByID(int id) {
        if (!head)
            return;
        if (head->FeatureID == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next && current->next->FeatureID != id)
            current = current->next;
        if (current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
    void displayAll() {
        Node* temp = head;
        while (temp) {
            temp->feature->analyze();
            temp = temp->next;
        }
    }
    void reverseList() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    ~SinglyLinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtEnd(1, new LandFeature("Forest"));
    list.insertAtEnd(2, new WaterFeature("River"));
    list.insertAtEnd(3, new LandFeature("Desert"));
    list.insertAtEnd(4, new WaterFeature("Ocean"));

    cout << "All Features:" << endl;
    list.displayAll();

    cout << endl << "After deleting Feature ID 2:" << endl;
    list.deleteByID(2);
    list.displayAll();

    cout << endl << "After reversing list:" << endl;
    list.reverseList();
    list.displayAll();

    return 0;
}
