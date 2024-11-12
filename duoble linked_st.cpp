#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node {
public:
    T Data;
    Node* next;
    Node* prev; // Added previous pointer to support backward traversal
};

template <class T>
class linkedlist {
public:
    Node<T>* head;

    linkedlist() {
        head = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    // Display the list from head to end
    void display() {
        Node<T>* temp = head;
        while (temp != NULL) {
            cout << temp->Data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display the list in reverse order from tail to head
    void displayReverse() {
        if (head == NULL) return; // Check if list is empty

        Node<T>* temp = head;
        
        // Move to the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Display nodes in reverse
        while (temp != NULL) {
            cout << temp->Data << " ";
            temp = temp->prev; // Move backward using prev pointer
        }
        cout << endl;
    }

    int count() {
        Node<T>* temp = head;
        int counter = 0;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool search(T key) {
        Node<T>* temp = head;
        while (temp != NULL) {
            if (temp->Data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Insert a node at the beginning
    void insert_Start(T value) {
        Node<T>* newNode = new Node<T>();
        newNode->Data = value;
        newNode->next = head;
        newNode->prev = NULL; // Previous pointer is NULL for new head node
        
        // If list is not empty, set previous of old head to newNode
        if (head != NULL) {
            head->prev = newNode;
        }
        
        head = newNode; // Update head to the new node
    }

    // Insert a new node before a specific item
    void insert_before(T item, T newvalue) {
        Node<T>* newnode = new Node<T>();
        newnode->Data = newvalue;

        if (head == NULL) {
            cout << "List is empty. Cannot insert before." << endl;
            return;
        }

        Node<T>* temp = head;
        
        // Traverse the list to find the specified item
        while (temp != NULL && temp->Data != item) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Item not found" << endl;
        } else {
            // Insert the new node before the found node
            newnode->next = temp;
            newnode->prev = temp->prev;
            
            // Update pointers for surrounding nodes
            if (temp->prev != NULL) {
                temp->prev->next = newnode;
            } else {
                head = newnode; // Update head if inserting at the start
            }
            temp->prev = newnode;
        }
    }

    // Append a node at the end
    void append(T value) {
        Node<T>* newNode = new Node<T>();
        newNode->Data = value;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL; // Set prev to NULL for the new head node
            head = newNode;
        } else {
            Node<T>* temp = head;
            
            // Traverse to the last node
            while (temp->next != NULL) {
                temp = temp->next;
            }
            
            // Link the new node at the end
            temp->next = newNode;
            newNode->prev = temp; // Set prev of new node to the last node
        }
    }

    // Delete a node with the specified value
    void Delete(T value) {
        












        
    }

    // Delete all nodes in the list
    void Delete_all() {
        Node<T>* temp = head;
        while (temp != NULL) {
            Node<T>* nextNode = temp->next;
            delete temp; // Free each node's memory
            temp = nextNode;
        }
        head = NULL; // Set head to NULL after deletion
        cout << "List is empty" << endl;
    }
};

int main() {
    linkedlist<int> lst;

    lst.isEmpty();
    lst.insert_Start(10);
    lst.insert_Start(20);
    lst.insert_Start(30);
    lst.display();

    cout << "Count = " << lst.count() << endl;

    if (lst.search(20)) {
        cout << "Found 20" << endl;
    } else {
        cout << "Not found 20" << endl;
    }

    lst.insert_before(20, 99);
    lst.display();

    lst.append(40);
    lst.display();

    lst.Delete(99);
    lst.display();

    lst.displayReverse();

    lst.Delete_all();
    lst.display();

    return 0;
}
