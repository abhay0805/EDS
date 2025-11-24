#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, curr_size, capacity;

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        curr_size = 0;
    }

    bool isFull() {
        return curr_size == capacity;
    }

    bool isEmpty() {
        return curr_size == 0;
    }

    // Enqueue 
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        curr_size++;
        cout << value << " inserted into queue.\n";
    }

    // Dequeue 
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }
        cout << arr[front] << " removed from queue.\n";
        front = (front + 1) % capacity;
        curr_size--;
    }

    // Dequeue from rear 
    void dequeueFromRear() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue from rear.\n";
            return;
        }
        cout << arr[rear] << " removed from rear.\n";
        rear = (rear - 1 + capacity) % capacity;
        curr_size--;
    }

    // Enqueue at front 
    void enqueueAtFront(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue at front.\n";
            return;
        }
        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        curr_size++;
        cout << value << " inserted at front.\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Circular Queue Elements: ";
        int temp = front;
        for (int i = 0; i < curr_size; i++) {
            cout << arr[temp] << " ";
            temp = (temp + 1) % capacity;
        }
        cout << endl;
    }
};

// =================== MAIN =======================
int main() {
    int size;
    cout << "Enter queue capacity: ";
    cin >> size;

    CircularQueue q(size);

    int mode;
    cout << "\nSelect Mode:\n";
    cout << "1. Input Restricted Circular Queue\n";
    cout << "2. Output Restricted Circular Queue\n";
    cout << "Enter your choice: ";
    cin >> mode;

    int choice, value;

    do {
        cout << "\n========= MENU =========\n";
        cout << "1. Enqueue (insert at rear)\n";
        cout << "2. Enqueue at front\n";
        cout << "3. Dequeue (from front)\n";
        cout << "4. Dequeue from rear\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            if (mode == 1)
                cout << "? Input Restricted Mode: Cannot enqueue at front!\n";
            else {
                cout << "Enter value to enqueue at front: ";
                cin >> value;
                q.enqueueAtFront(value);
            }
            break;

        case 3:
            q.dequeue();
            break;

        case 4:
            if (mode == 2)
                cout << " Output Restricted Mode: Cannot dequeue from rear!\n";
            else
                q.dequeueFromRear();
            break;

        case 5:
            q.display();
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

