#include <iostream>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class definition
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Add data at the end
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

    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " > ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }

    // Insert at beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Search for a value
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

    // Delete a node by value
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

    // Reverse the linked list
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

// Main menu for user interaction
int main() {
    LinkedList list;
    int choice, data;

    do {
        cout << "\n--- Linked List CRUD Menu ---\n";
        cout << "1. Add data at the end\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Delete by Value\n";
        cout << "6. Reverse List\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to add at the end: ";
            cin >> data;
            list.append(data);
            break;
        case 2:
            cout << "Enter value to insert at beginning: ";
            cin >> data;
            list.insertAtBeginning(data);
            break;
        case 3:
            cout << "Linked List: ";
            list.display();
            break;
        case 4:
            cout << "Enter value to search: ";
            cin >> data;
            list.search(data);
            break;
        case 5:
            cout << "Enter value to delete: ";
            cin >> data;
            list.deleteNode(data);
            break;
        case 6:
            list.reverse();
            break;
        case 7:
            cout << "Exiting program. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
