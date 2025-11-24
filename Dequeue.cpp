#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 10

// Product class to store product details
class Product {
public:
    string name;
    int quantity;
    float price;
};

class Deque {
    Product dq[MAX_SIZE]; // ? Array of objects
    int front, rear, size;

public:
    Deque(int s) {
        front = -1;
        rear = 0;
        size = s;
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    // Enqueue at front
    void enqueueFront(string pname, int qty, float pr) {
        if (isFull()) {
            cout << "?? Stock Full! Cannot add more products.\n";
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0)
            front = size - 1;
        else
            front = front - 1;

        dq[front].name = pname;
        dq[front].quantity = qty;
        dq[front].price = pr;

        cout << "? Product added at FRONT: " << pname << endl;
    }

    // Enqueue at rear
    void enqueueRear(string pname, int qty, float pr) {
        if (isFull()) {
            cout << "?? Stock Full! Cannot add more products.\n";
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == size - 1)
            rear = 0;
        else
            rear = rear + 1;

        dq[rear].name = pname;
        dq[rear].quantity = qty;
        dq[rear].price = pr;

        cout << "? Product added at REAR: " << pname << endl;
    }

    // Dequeue from front
    void dequeueFront() {
        if (isEmpty()) {
            cout << "? No product to remove.\n";
            return;
        }

        cout << "??? Product removed from FRONT: " << dq[front].name << endl;

        if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;
        else
            front = front + 1;
    }

    // Dequeue from rear
    void dequeueRear() {
        if (isEmpty()) {
            cout << "? No product to remove.\n";
            return;
        }

        cout << "??? Product removed from REAR: " << dq[rear].name << endl;

        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = size - 1;
        else
            rear = rear - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "?? No products available in D-Mart.\n";
            return;
        }

        cout << "\n===== ?? D-MART PRODUCT LIST =====\n";
        cout << "Product Name\tQuantity\tPrice\n";
        cout << "----------------------------------------\n";

        int i = front;
        while (true) {
            cout << dq[i].name << "\t\t" << dq[i].quantity << "\t\t" << dq[i].price << endl;
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << "----------------------------------------\n";
    }
};

// ====================== MAIN FUNCTION ======================
int main() {
    int dequeType;
    cout << "====== ?? D-MART PRODUCT MANAGEMENT SYSTEM ======\n";
    cout << "Select Deque Type:\n1. Input Restricted Deque\n2. Output Restricted Deque\nEnter choice: ";
    cin >> dequeType;

    Deque dq(5);
    int choice;
    string pname;
    int qty;
    float pr;

    do {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Enqueue at Front\n";
        cout << "2. Enqueue at Rear\n";
        cout << "3. Dequeue from Front\n";
        cout << "4. Dequeue from Rear\n";
        cout << "5. Display Products\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (dequeType == 1) {
                    cout << "?? Not allowed in Input Restricted Deque!\n";
                    break;
                }
                cout << "Enter Product Name: ";
                cin >> pname;
                cout << "Enter Quantity: ";
                cin >> qty;
                cout << "Enter Price: ";
                cin >> pr;
                dq.enqueueFront(pname, qty, pr);
                break;

            case 2:
                cout << "Enter Product Name: ";
                cin >> pname;
                cout << "Enter Quantity: ";
                cin >> qty;
                cout << "Enter Price: ";
                cin >> pr;
                dq.enqueueRear(pname, qty, pr);
                break;

            case 3:
                dq.dequeueFront();
                break;

            case 4:
                if (dequeType == 2) {
                    cout << "?? Not allowed in Output Restricted Deque!\n";
                    break;
                }
                dq.dequeueRear();
                break;

            case 5:
                dq.display();
                break;

            case 6:
                cout << "? Exiting System...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

