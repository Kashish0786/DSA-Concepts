#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
//pq for obj
//pq for pair see fro, chatgpt
class Student {
public: 
    string name;
    int marks;

    Student (string name, int marks){
        this->name = name;
        this->marks = marks;
    }
    //operator overloading "<"
    //max heap on basis of marks 
    // for min heao change sign return this->marks<obj.marks; to this return this->marks>obj.marks;
    bool operator<(const Student &obj) const {
        return this->marks<obj.marks;
    }
};
int main(){
    priority_queue<Student>pq;

    pq.push(Student("aman", 85));
    pq.push(Student("kash", 95));
    pq.push(Student("bhumi", 65));

    while(!pq.empty()){
        cout<<"top = "<<pq.top().name<<"," <<pq.top().marks<<endl;
        pq.pop();
    }

    return 0;
}