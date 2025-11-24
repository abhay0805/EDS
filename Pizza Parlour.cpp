#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int orderID;
    int numOfPizzas;
    string pizzaType;
    string pizzaSize;
    Node* next;

    Node(int id, int num, const string& type, const string& size) {
        orderID = id;
        numOfPizzas = num;
        pizzaType = type;
        pizzaSize = size;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;
    Node* tail;

    CircularLinkedList() {
        head = tail = NULL;
    }

    void push_back(int id, int num, const string& type, const string& size) {
        Node* newNode = new Node(id, num, type, size);

        if (!head) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void pop_front() {
        if (!head) {
            cout << "There are no orders left." << endl;
            return;
        }

        if (head == tail) {
            cout << "Order number " << head->orderID << " has been served." << endl;
            delete head;
            head = tail = NULL;
        } else {
            cout << "Order number " << head->orderID << " has been served." << endl;
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    void printOrders() {
        if (!head) {
            cout << "There are no orders remaining." << endl;
            return;
        }

        Node* temp = head;
        cout << "Order ID   Number of Pizzas   Type of Pizza   Size of Pizza" << endl;

        do {
            cout << temp->orderID << "          "
                 << temp->numOfPizzas << "                "
                 << temp->pizzaType << "          "
                 << temp->pizzaSize << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void replaceOrder(int id, int newNum, const string& newType, const string& newSize) {
        if (!head) {
            cout << "No orders to replace." << endl;
            return;
        }

        Node* temp = head;
        bool found = false;

        do {
            if (temp->orderID == id) {
                temp->numOfPizzas = newNum;
                temp->pizzaType = newType;
                temp->pizzaSize = newSize;
                cout << "Order ID " << id << " has been updated successfully." << endl;
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != head);

        if (!found) {
            cout << "Order ID " << id << " not found." << endl;
        }
    }
};

int main() {
    CircularLinkedList orders;
    int orderNumber = 1;
    int choice;
    int m;
    cout<<"HOW MANY ORDER YOU WANT TO PLACE TODAY"<<endl;
    cin>>m;
    int b=0;

    do {
        cout << "\n======= Pizza Parlour System =======\n";
        cout << "1. Place a Pizza Order\n";
        cout << "2. Serve the Pizza Order\n";
        cout << "3. Show All Remaining Orders\n";
        cout << "4. Replace an Existing Order\n";  
        cout << "0. Exit the Program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
            	if(b<m){
					
	                int quantity;
	                string type, size;
	
	                cout << "Enter the number of pizzas you want: ";
	                cin >> quantity;
	
	                cout << "Enter the type of pizza: ";
	                cin >> type;
	
	                cout << "Enter the size of pizza: ";
	                cin >> size;
	
	                orders.push_back(orderNumber, quantity, type, size);
	                cout << "Your order has been placed with Order ID: " << orderNumber << endl;
	                orderNumber++;
	                b++;
	                break;
	            }else{
	            	cout<<"out of stock"<<endl;
				}
			}

            case 2:
                orders.pop_front();
                break;

            case 3:
                cout << "\nRemaining Orders:\n";
                orders.printOrders();
                break;

            case 4: {
                int id, quantity;
                string type, size;

                cout << "Enter the Order ID to replace: ";
                cin >> id;

                cout << "Enter the new number of pizzas: ";
                cin >> quantity;

                cout << "Enter the new type of pizza: ";
                cin >> type;

                cout << "Enter the new size of pizza: ";
                cin >> size;

                orders.replaceOrder(id, quantity, type, size);
                break;
            }

            case 0:
                cout << "The program has ended." << endl;
                break;

            default:
                cout << "Please enter a valid choice." << endl;
        }

    } while (choice != 0);

    return 0;
}

