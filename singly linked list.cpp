#include<iostream>
#include<string.h>
using namespace std;

class Node{
    public:
        int prn;
        int TrainNumber;
        string clas;
        string name;
        Node* next;

        Node(int p,int t,string c,string n){
            prn=p;
            TrainNumber=t;
            clas=c;
            name=n;
            next=NULL;
        }
};

class LL{
    public:
    Node* head;
    Node* tail;

    LL(){
        head=tail=NULL;
    }

    void Insert_front(int p,int t,string c,string n){
        Node* newNode=new Node(p,t,c,n);
        if(head==NULL){
            head=tail=newNode;
            return;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }


    void Print(Node* h){
        if(h==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=h;
        while(temp!=NULL){
            cout<<"PRN:"<<temp->prn<<" "
                <<"Train Number:"<<temp->TrainNumber<<" "
                <<"Class:"<<temp->clas<<" "
                <<"Name:"<<temp->name<<" ";
            temp=temp->next;
        }  
    }

    void Sort(){
        if(head==NULL||head->next==NULL){
            return;
        }
        Node* h1;
        Node* h2;
        for(h1=head;h1->next!=NULL;h1=h1->next){
            for(h2=h1->next;h2!=NULL;h2=h2->next){
                if(h1->prn > h2->prn){
                    swap(h1->prn,h2->prn);
                    swap(h1->TrainNumber,h2->TrainNumber);
                    swap(h1->clas,h2->clas);
                    swap(h1->name,h2->name);
                }
            }
        }
    }

    void Delete(int pos) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        // Case 1: delete head
        if (pos == 0) {
            Node* temp = head;
            head = head->next;
            if (head == NULL) tail = NULL;
            delete temp;
            return;
        }

        // Case 2: delete at other position
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp->next == NULL) {
                cout << "Invalid Position" << endl;
                return;
            }
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        if (nodeToDelete == NULL) {
            cout << "Invalid Position" << endl;
            return;
        }

        temp->next = nodeToDelete->next;
        if (nodeToDelete == tail) {
            tail = temp;
        }
        delete nodeToDelete;
    }


    void Update(Node* h,int prn){
        Node* temp=h;
        while(temp!=NULL && temp->prn!=prn){
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"PRN not found!"<<endl;
            return;
        }

        int p,t;
        string c,n;
        cout<<"Enter the class"<<endl;
        cin>>c;
        cout<<"Enter the name of the passanger"<<endl;
        cin>>n;
        temp->clas=c;
        temp->name=n;
    }    
};

int main(){
    LL L1,L2,obj;
    Node* mergedHead=NULL;

    int m=1;
    while(m==1){
        int ch;
        cout<<"1. Create first list"<<endl;
        cout<<"2. Create second list"<<endl;
        cout<<"3. Delete from first list"<<endl;
        cout<<"4. Delete from second list"<<endl;
        cout<<"5. Update first list"<<endl;
        cout<<"6. Update second list"<<endl;
        cout<<"7. sort first list"<<endl;
        cout<<"0. Exit "<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;

        switch(ch){
            case 0:
                m=0;
                break;

            case 1:{
                int n;
                cout<<"Enter number of nodes to insert: ";
                cin>> n;
                while(n--){
                    int pr,tr;
                    string cl,nm;
                    cout<<"Enter PRN: "; cin>>pr;
                    cout<<"Enter Train Number: "; cin>>tr;
                    cout<<"Enter Class: "; cin>>cl;
                    cout<<"Enter Name: "; cin>>nm;
                    L1.Insert_front(pr,tr,cl,nm);
                }
                obj.Print(L1.head);
                break;
            }

            case 2:{
                int n;
                cout<<"Enter number of nodes to insert: ";
                cin>> n;
                while(n--){
                    int pr,tr;
                    string cl,nm;
                    cout<<"Enter PRN: "; cin>>pr;
                    cout<<"Enter Train Number: "; cin>>tr;
                    cout<<"Enter Class: "; cin>>cl;
                    cout<<"Enter Name: "; cin>>nm;
                    L2.Insert_front(pr,tr,cl,nm);
                }
                
                obj.Print(L2.head);
                break;
            }

            case 3:{
                int p;
                cout<<"Enter position to delete: ";
                cin>>p;
                L1.Delete(p);
                obj.Print(L1.head);
                break;
            }

            case 4:{
                int p;
                cout<<"Enter position to delete: ";
                cin>>p;
                L2.Delete(p);
                obj.Print(L2.head);
                break;
            }

            case 5:{
                 int x;
                cout<<"Enter PRN to update in first list: ";
                cin>>x;
                obj.Update(L1.head,x);
                obj.Print(L1.head);
                break;
            }

            case 6:{
                int x;
                cout<<"Enter PRN to update in second list: ";
                cin>>x;
                obj.Update(L2.head,x);
                obj.Print(L2.head);
                break;
            }

            case 7:{
                L1.Sort();
                L2.Sort();
                cout<<"sorted first linked list"<<endl;
                obj.Print(L1.head);
                cout<<"sorted second linked list"<<endl;
                obj.Print(L2.head);
                
                break;
            }
        }
    }
    return 0;
}

