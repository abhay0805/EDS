#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node * pre;
    Node(int val){
        data = val;
        next = pre = NULL;
    }
};

class D_LList{
public:
    Node * head;
    Node * tail;
    D_LList(){
        head = tail = NULL;
    }

    void Print(Node* h){
        Node* temp = h;
        while(temp != NULL){
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void push_front(int val){
        Node * newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->pre = newNode;
            head = newNode;
        }
        cout << "After push_front: ";
        Print(head);
    }

    void push_back(int val){
        Node * newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->pre = tail;
            tail->next = newNode;
            tail = newNode;
        }
        cout << "After push_back: ";
        Print(head);
    }

    void pop_front(){
        if(head == NULL){
            return;
        }
        Node * temp = head;
        head = head->next;
        if(head != NULL){
            head->pre = NULL;
            temp->next = NULL;
            delete temp;
        }
        cout << "After pop_front: ";
        Print(head);
    }

    void pop_back(){
        if(head == NULL){
            return;
        }
        Node * temp = tail;
        tail = tail->pre;
        if(tail != NULL){
            tail->next = NULL;
        }
        delete temp;
        cout << "After pop_back: ";
        Print(head);
    }

    void Sort(){
        if (head == NULL || head->next == NULL) {
            return;
        }
        Node* i;
        Node* j;
        for (i = head; i->next != NULL; i = i->next) {
            for (j = i->next; j != NULL; j = j->next) {
                if (i->data > j->data) {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
        cout << "After sort: ";
        Print(head);
    }

    void Delete(int val) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == val) { // head case
            pop_front();
            return;
        }

        if (tail->data == val) { // tail case
            pop_back();
            return;
        }

        Node* temp = head->next;
        while (temp != NULL && temp->data != val) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Value not found in list" << endl;
            return;
        }

        temp->pre->next = temp->next;
        if (temp->next != NULL) {
            temp->next->pre = temp->pre;
        }

        delete temp;
        cout << "After delete(" << val << "): ";
        Print(head);
    }

    Node* Merge(Node* h1,Node* h2){
        if(h1 == NULL || h2 == NULL){
            return h1 == NULL ? h2 : h1;
        }

        if(h1->data <= h2->data){
            h1->next = Merge(h1->next,h2);
            return h1;
        }else{
            h2->next = Merge(h1,h2->next);
            return h2;
        }
    }
};

int main(){
    D_LList L1, L2, L3, obj;
    int ch,val;

    do {
        cout<<"1. Insert into first linked list"<<endl;
        cout<<"2. Insert into second linked list"<<endl;
        cout<<"3. Sort first linked list"<<endl;
        cout<<"4. Sort second linked list"<<endl;
        cout<<"5. Merge first and second linked list"<<endl;
        cout<<"6. Delete value from list"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch){
            case 1:{
                int n;
                cout<<"Enter how many nodes you want to enter: ";
                cin>>n;
                while(n--){
                    cout<<"Enter value: ";
                    cin>>val;
                    L1.push_back(val);
                }
                break;
            }

            case 2:{
                int m;
                cout<<"Enter how many nodes you want to enter: ";
                cin>>m;
                while(m--){
                    cout<<"Enter value: ";
                    cin>>val;
                    L2.push_back(val);
                }
                break;
            }

            case 3:
                L1.Sort();
                break;

            case 4:
                L2.Sort();
                break;

            case 5:
                L1.Sort();
                L2.Sort();
                L3.head = obj.Merge(L1.head,L2.head);
                cout<<"After merge: ";
                obj.Print(L3.head);
                break;

            case 6:{
                int v;
                cout<<"Enter from which list you want to delete (1/2/3): ";
                cin>>v;
                cout<<"Enter the value you want to delete: ";
                cin>>val;
                if(v==1) L1.Delete(val);
                else if(v==2) L2.Delete(val);
                else if(v==3) L3.Delete(val);
                else cout<<"Invalid list choice"<<endl;
                break;
            }

            case 0:
                break;

            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(ch!=0);

    return 0;
}

