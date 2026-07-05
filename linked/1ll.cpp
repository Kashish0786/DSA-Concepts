// head = 1st element , tail last element 
// node have two values: 1.data(int) 2. node* (ptr)
// functions 1.push_front 2.push_back 3.pop_front 4.pop_back 5.display 6.size 7.search 8.insert_at 9.delete_at

//dynamically delete krne ke liye ~node ~list me destructor baya delete krne ke liye
// LL implementation
#include <iostream>
using namespace std;

class Node {

public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

    //destructor
    ~Node(){
        // cout << "~Node with value " << data << " is deleted" << endl;
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    //destructor
    ~List() {
        // cout<< "List is deleted" << endl;
        if (head != NULL) {
            delete head;
            head = NULL;
        }
    }

//push front
    void push_front(int val){
        Node* newNode = new Node(val); //dynamic allocation both will work same but static will deleted after function call 
        // Node* newNode(val); //static allocation

        if (head == NULL){ //case 1
            head = tail = newNode;
        }else{ //case 2
            newNode->next = head;
            head = newNode;
        }
    }

//push back
        void push_back(int val){
        Node* newNode = new Node(val); //dynamic allocation both will work same but static will deleted after function call 

        if (head == NULL){ //case 1
            head = tail = newNode;
        }else{ //case 2
            tail->next = newNode;
            tail = newNode;
        }
    }
//print
        void printList (){
            Node* temp = head;

            while (temp != NULL){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }

//insert at given position
        void insert(int val, int pos){
            Node* newNode = new Node(val);
            Node* temp = head;

            for(int i=0; i<pos-1;i++){
                if(temp == NULL){
                    cout << "Position is invalid" << endl;
                    return;
                }
                temp=temp->next;
            }
            //temp is now at pos-1 prev/left
            newNode->next = temp->next;
            temp->next = newNode;
        }

//pop front
        void pop_front(){

            if (head == NULL){
                cout << "List is empty" << endl;
                return;
            }

            Node* temp = head;
            head = head->next;

            temp->next = NULL;
            delete temp;
        }

//pop back
        void pop_back(){

            if (head == NULL){
                cout << "List is empty" << endl;
                return;
            }

            Node* temp = head;

            // while (temp->next != tail) ayese bhi likh sakte
            while (temp->next->next != NULL){
                temp = temp->next;
            }

            temp->next = NULL; //temp = tail's previous node
            delete tail;
            tail = temp;
        }

//iterative search 
        int searchItr(int key){
            Node* temp = head;
            int idx =0;

            while(temp!= NULL){
                if(temp->data == key){
                    return idx;
                }
                temp = temp->next;
                idx++;
            }
            return -1; // key not found
        }

//recursive search
        int helper(Node* temp, int key){
            //BC
            if(temp== NULL){
                return -1; // key not found
            }
            if(temp->data == key){
                return 0; // key found at current index
            }
            int idx = helper(temp->next, key);
            if(idx == -1){
                return -1; // key not found in the rest of the list
            }
            return idx+1; // increment index for the current node
        }

        int searchRec(int key){
            return helper(head, key);
        }

//reverse linked list without using extra space
        void reverseList(){
            Node* prev = NULL;
            Node* curr = head;

            while(curr!= NULL){
                Node* next = curr->next;
                curr->next = prev;

                //update prev and curr
                prev = curr;
                curr = next;
            }
            head = prev;
        }
//imp
//find and remove Nth node from end

        int getsize(){
            int sz =0;
            Node* temp = head;

            while(temp!= NULL){
                sz++;
                temp = temp->next;
            }
            return sz;
        }
        void removeNthFromEnd(int n){
            // int size= this->size();
            int size= getsize();

            Node* prev = head;

            for(int i=0; i<(size-n); i++){ //i=size-n=>prev=>deletion node prev
                prev = prev->next;
            }

            Node* toDel = prev->next;
            cout<<"Deleting node with value: " << toDel->data << endl;
            prev->next = prev->next->next;
        }
};

int main() {
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();
    // 1->2->3->NULL

    // cout<<ll.searchItr(2)<<endl; //index 1 will be printed
    // cout<<ll.searchRec(2)<<endl; //index 1 will be printed
    
    // ll.reverseList();
    // ll.printList();
    // 3->2->1->NULL

    ll.removeNthFromEnd(2);
    ll.printList();
    // 1->2->NULL

    // ll.push_back(4);
    // ll.push_back(5);
    // ll.printList();
    // 1->2->3->4->5->NULL

    // ll.insert(100, 2);
    // ll.printList(); 
    // 1->2->100->3->4->5->NULL

    /* ll.insert(100, 25);
    ll.printList(); */
    // Position is invalid , if case will run and print the list as it is
    
    // ll.pop_front();
    // ll.printList();
    // 2->100->3->4->5->NULL

    // ll.pop_back();
    // ll.printList();
    // 2->100->3->4->NULL



    return 0;
}

