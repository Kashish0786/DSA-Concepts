#include<iostream>
#include<list>
#include<iterator>
using namespace std;
// push front = head ki value , push back = tail next ki val deta h
// front=head ki val , back = tail ki val deta h 


void printList(list<int>ll){
     list<int> ::iterator itr;
    for(itr=ll.begin(); itr!=ll.end(); itr++){
        cout<<(*itr)<<"->";
    }
    cout<<endl;
}

//list in stl
int main(){
    list<int>ll;

    ll.push_front(2);
    ll.push_front(1); //1,2

    ll.push_back(3); //1,2,3
    ll.push_back(4); //1,2,3,4

   printList(ll);
   cout<<ll.size()<<endl;

   cout<<"head=" <<ll.front()<<"\n";
   cout<<"tail= "<<ll.back()<<"\n";

   ll.pop_front();
   printList(ll);

   ll.pop_back();
   printList(ll);
    return 0;
}