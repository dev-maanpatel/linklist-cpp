#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addAtStart(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " > ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }

    void search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Element found: " << key << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Element not found: " << key << endl;
    }

    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            cout << "Deleted: " << key << endl;
            return;
        }

        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Element not found: " << key << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Deleted: " << key << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        cout << "Linked list reversed." << endl;
    }
};

int main() {
    LinkedList list;
    int choice, data;

    do {
        cout << "\n--- Linked List CRUD Menu ---\n";
        cout << "1. Add Data\n";
        cout << "2. Add at Start\n";
        cout << "3. Add at End\n";
        cout << "4. Display\n";
        cout << "5. Search\n";
        cout << "6. Delete\n";
        cout << "7. Reverse\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to add: ";
            cin >> data;
            list.append(data);
            break;
        case 2:
            cout << "Enter value to add at start: ";
            cin >> data;
            list.addAtStart(data);
            break;
        case 3:
            cout << "Enter value to add at end: ";
            cin >> data;
            list.append(data);
            break;
        case 4:
            cout << "Linked List: ";
            list.display();
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> data;
            list.search(data);
            break;
        case 6:
            cout << "Enter value to delete: ";
            cin >> data;
            list.deleteNode(data);
            break;
        case 7:
            list.reverse();
            break;
        case 8:
            cout << "Exiting program. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
