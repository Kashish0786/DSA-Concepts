#include <iostream>
#include<queue>
using namespace std;
// pq in stl priority_queue<int>pq; push,pop,top
// parent>=child (max heap) 
int main(){
    //without greater max heap, with greater min heap
    // same implementation for string priority_queue<string>st (max heap),priority_queue<string, vector<string>, greater<string>>st; (min heap)
    priority_queue<int, vector<int>, greater<int>>pq;

    pq.push(5);
    pq.push(10);
    pq.push(9);
    pq.push(7);
    pq.push(3);

    while(!pq.empty()){
        cout<<"top : "<<pq.top()<<endl;
        pq.pop();
    }

    return 0;
}

