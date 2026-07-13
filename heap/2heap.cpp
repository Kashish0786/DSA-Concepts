
/* 
for 0-base indexing
parent to child
index i(parent) 
left child = 2*i+1
right child = 2*i+2

child to parent
child index = x
parent index = (x-1)/2

for 1-base index
parent to child
index i(parent) 
left child = 2*i
right child = 2*i+1

child to parent
child index = x
parent index = x/2
*/

// push o(logn)

#include <iostream>
#include<string>
#include<vector>

using namespace std;

class Heap {
    vector<int>vec;
public:
//max heap , for min heap only change this vec[x] >vec[par]) to vec[x] < vec[par])
    void push(int val){
        //step 1
        vec.push_back(val);

        //step 2 - fix heap
        int x = vec.size()-1; //child
        int par = (x-1)/2;

        while(par >=0 && vec[x] >vec[par]){ //o (log n)
            swap(vec[x], vec[par]);
            x=par;
            par=(x-1)/2;
        }
    }

    void heapify(int i) { //i=par
        if(i >= vec.size()){
            return;
        }
        int left = 2*i+1;
        int right = 2*i+2;

        int maxIdx =i;
        if(left <vec.size() && vec[left]>vec[maxIdx]){
            maxIdx=left;
        }
        if(right<vec.size() && vec[right]>vec[maxIdx]){
            maxIdx=right;
        }
        swap(vec[i], vec[maxIdx]);
        if(maxIdx != i) {
            //swaping with child node
            heapify(maxIdx);
        }

    }

    void pop(){
        //1. swap (root, last) o(1)
        swap(vec[0], vec[vec.size()-1]);

        //2. delete o(1)
        vec.pop_back();

        //3. fix o(logn)
        heapify(0);
    }

    int top(){ //o(1)
        return vec[0]; //highest priority element
    }

    bool empty(){
        return vec.size() == 0;
    }
};

int main(){
    Heap heap;

    heap.push(50);
    heap.push(10);
    heap.push(100);

    while(!heap.empty()){
        cout<<"top : "<<heap.top()<<endl; //100,50,10
        heap.pop();
    }

    return 0;
}
