#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void printList(Node* head) {
    if (head == nullptr) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

Node* searchValue(Node* head, int x) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    do {
        if (temp->data == x) return temp;
        temp = temp->next;
    } while (temp != head);
    return nullptr;
}

void updateLastNode(Node* head, Node* target) {
    if (head == nullptr || target == nullptr) return;
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = target;
}

int main() {
    Node* head = nullptr;
    int n, data, x;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values for the list: ";
    for (int i = 0; i < n; ++i) {
        cin >> data;
        insertEnd(head, data);
    }

    cout << "Original List: ";
    printList(head);

    cout << "Enter value to search: ";
    cin >> x;

    Node* foundNode = searchValue(head, x);
    if (foundNode != nullptr) {
        updateLastNode(head, foundNode);
        cout << "Updated List: ";
        printList(head);
    } else {
        cout << "Value not found in the list." << endl;
    }

    if (head != nullptr) {
        Node* current = head;
        Node* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }

    return 0;
}


