#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define l_size 6
#define c_size 20
# define q_size 11

class hashtable{                                //Linear Probing (without replacement)
public:
int htable[l_size];
hashtable(){
for(int i=0;i<l_size;i++)htable[i]=-1;
}
int hashfn(int);
void insertfn(int);
void disp( );
void search(int);
};

int hashtable::hashfn(int key){
return key % l_size;
}

void hashtable::insertfn(int key){
int index=hashfn(key);
int idx=index;
while(htable[idx]!=-1){
idx=(idx+1)%l_size;
if(idx==index){
cout<<"Table is full..."<<endl;
return;
}
}
htable[idx]=key;
cout<<"The key ("<<key<<") inserted at position "<<idx<<endl;
}

void hashtable::disp(){
cout<<"\nHash Table: "<<endl;
for(int i=0;i<l_size;i++){
cout<<htable[i]<<" "<<endl;
}
cout<<endl;
}

void hashtable::search(int key){
int index=hashfn(key);
int idx=index;
while(htable[idx]!=key){
idx=(idx+1)%l_size;
if(idx==index){
cout<<"Not found in table..."<<endl;
return;
}
}
cout<<"Key found at position: "<<idx<<endl;
}

class node{                         //Separate Chaining (using Linked List)
public:
int k;
node*next;
node(){
next=NULL;
}
};

class htable_chain{
public:
node *c_htable[c_size];
htable_chain(){
for(int i=0;i<c_size;i++) c_htable[i]=NULL;
}
int c_hashfn(int);
void insertfn(int);
void disp();
void search(int);

};

int htable_chain::c_hashfn(int key){
return key%c_size;
}

void htable_chain::insertfn(int key){
    int index=c_hashfn(key);
    node *temp=new node;
    node* p;
    temp->k=key;
    if(c_htable[index]==NULL)
        c_htable[index]=temp;
    else{
        p=c_htable[index];
        while(p->next!=NULL) p=p->next;
        p->next=temp;
    }
}

void htable_chain::disp(){
    cout<<"\nHashtable using separate chaining without replacement using linked list:\n";
    cout<<"Index\tValues"<<endl;

    for(int i=0;i<c_size;i++) {
        cout<<i<<"\t";
        node *p=c_htable[i];

        if (p==NULL) 
            cout<<"NULL";
        else {
            while (p!=NULL) {
                cout<<p->k;
                if(p->next!=NULL)
                    cout<<" -> ";
                p=p->next;
            }
        }
        cout<<endl;
    }
}

void htable_chain::search(int key) {
    int index=key%c_size;
    node *p=c_htable[index];
    int position=0; // To track node position in chain

    while (p!=NULL) {
        if (p->k==key) {
            cout<<"\nKey "<<key<<" found at index "<<index<<" (position "<<position<<" in chain)"<<endl;
            return; 
        }
        p=p->next;
        position++;
    }

    cout<<"\nKey "<<key<<" not found in the hashtable.\n";
}


class quadratic_hash{                       //Quadratic Probing (without replacement)
	public:
		int hashtable[q_size];
		quadratic_hash(){
			for(int i=0;i<q_size;i++)
			hashtable[i]=-1;   
		}
		int hashfn(int key);
		void insertfn(int key);	
		void search(int key);
		void display();
	
};

int quadratic_hash::hashfn(int key){
	return key%q_size;
}

void quadratic_hash::insertfn(int key) {
        int original_index=hashfn(key);
        for (int i=0;i<q_size;++i) {
            int index=(original_index+i*i)%q_size;

            if (hashtable[index]==key){
                cout<<"Key "<<key<<" already present at index "<<index<<" (probe i="<<i<<")"<<endl;
                return;
            }
            if (hashtable[index]==-1) {
                hashtable[index]=key;
                cout<<"Inserted key "<<key<<" at index "<<index<<" (probe i="<<i<<")"<<endl;
                return;
            }
        }
        cout<<"Hashtable is full..."<<endl;
}

void quadratic_hash::search(int key) {
        int original_index=hashfn(key);

        for(int i=0;i<q_size; ++i){
            int index=(original_index+i*i)%q_size;
            if(hashtable[index]==key) {
                cout<<"Key "<<key<<" found at index "<<index<<" (probe i="<<i<<")"<<endl;
                return;
            }
            if(hashtable[index]==-1){ 
                cout<<"Key "<<key<<" not found (stopped at empty slot index "<<index<<")"<<endl;
                return;
            }
        }
        cout<<"Key "<<key<<" not found in the hashtable after full probing"<<endl;
}

void quadratic_hash::display(){
	cout<<" hashtable using quadratic probing without replacement : "<<endl;
	cout<<"Index\tValue"<<endl;
	for(int i=0;i<q_size;i++){
		cout<<i<<"  \t "<<hashtable[i]<<endl;
	}
}


int main(int argc, char** argv) {
hashtable ht;
htable_chain hc;
quadratic_hash hq;
int ch,ch1,ch2;
int key;

do{
    cout<<"\n   ** HASHING MENU **"<<endl;
    cout<<"1. Linear Probing (without replacement)"<<endl;
    cout<<"2. Separate Chaining (using Linked List)"<<endl;
    cout<<"3. Quadratic Probing (without replacement)"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch1;
    switch(ch1){
        case 1:   //Linear Probing (without replacement)
            do{
                cout<<"\n--- Linear Probing Menu ---"<<endl;
                cout<<"1. Insert Key"<<endl;
                cout<<"2. Search Key"<<endl;
                cout<<"3. Display Table"<<endl;
                cout<<"4. Back to Main Menu"<<endl;
                cout<<"Enter your choice: ";
                cin>>ch2;
                switch(ch2){
                    case 1:
                        
                        cout<<"Enter key to insert: ";
                        cin>>key;
                        ht.insertfn(key);
                        break;

                    case 2:
                        
                        cout<<"Enter key to search: ";
                        cin>>key;
                        ht.search(key);
                        break;
                    
                    case 3:
                        ht.disp();
                        break;

                    case 4:
                        cout<<"Returning to main menu..."<<endl;
                        break;

                    default:
                        cout<<"Invalid choice."<<endl;
                }
            }while(ch2!=4);
            break;

        case 2:   //Separate Chaining (using Linked List)
            do{
                cout<<"\n--- Separate Chaining Menu ---"<<endl;
                cout<<"1. Insert Key"<<endl;
                cout<<"2. Search Key"<<endl;
                cout<<"3. Display Table"<<endl;
                cout<<"4. Back to Main Menu"<<endl;
                cout<<"Enter your choice: ";
                cin>>ch2;
                switch(ch2){
                    case 1:{
                        //int data[c_size] = {33,56,78,12,10,67,89,99,100,23,45,71,39,62,59,90,91,20,75,66};
                        //for (int i=0;i<c_size;i++)
                        cout<<"Enter key to insert: ";
                        cin>>key;
                        hc.insertfn(key);
                        //cout<<"Loaded 20 student marks into hash table."<<endl;
                        break;
                    }
                    case 2:
                        
                        cout<<"Enter key to search: ";
                        cin>>key;
                        hc.search(key);
                        break;

                    case 3:
                        hc.disp();
                        break;

                    case 4:
                        cout<<"Returning to main menu..."<<endl;
                        break;
                    
                    default:
                        cout<<"Invalid choice."<<endl;
                }
            }while(ch2!=4);
            break;

        case 3:   //Quadratic Probing (without replacement)
            do{
                cout<<"\n--- Quadratic Probing Menu ---"<<endl;
                cout<<"1. Insert Key"<<endl;
                cout<<"2. Search Key"<<endl;
                cout<<"3. Display Table"<<endl;
                cout<<"4. Back to Main Menu"<<endl;
                cout<<"Enter your choice: ";
                cin>>ch2;
                switch(ch2){
                    case 1:{
                        //int data[q_size]={25,15,10,5,11,19,16,36,42,28,32};
                        //for(int i=0;i<q_size;i++)
                        cout<<"Enter key to insert: ";
                        cin>>key;
                        hq.insertfn(key);
                        //cout<<"Loaded 11 mango categories into hash table."<<endl;
                        break;
                    }

                    case 2:
                        int key;
                        cout<<"Enter key to search: ";
                        cin>>key;
                        hq.search(key);
                        break;

                    case 3:
                        hq.display();
                        break;

                    case 4:
                        cout<<"Returning to main menu..."<<endl;
                        break;
                    
                    default:
                        cout<<"Invalid choice."<<endl;

                }
            }while(ch2!=4);
            break;

        case 4:
            cout<<"Exiting program..."<<endl;
            return 0;

        default:
            cout<<"Invalid choice."<<endl;
    }
    cout<<"Do you want to continue? (1/0) : ";
    cin>>ch;
}while(ch==1);

return 0;
}
