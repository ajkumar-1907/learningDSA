#include<iostream>
#include<vector>
using namespace std;

int main() {
    

    vector<int> v;

    vector<int> a(5, 1);
    cout<<"Print a : ";
    for(int i: a){
        cout<<i<<" ";
    }cout <<endl;

    vector<int> last(a);
    cout<<"Print last : ";
    for(int i: last){
        cout<<i<<" ";
    }cout <<endl;
    

    cout<<"Capacity : "<<v.capacity() <<endl;

    v.push_back(1);
    cout<<"Capacity : "<<v.capacity() <<endl;

    v.push_back(2);
    cout<<"Capacity : "<<v.capacity() <<endl;

    v.push_back(3);
    cout<<"Capacity : "<<v.capacity() <<endl;
    cout<<"Size : "<<v.size() <<endl;

    v.push_back(4);
    cout<<"Capacity : "<<v.capacity() <<endl;
    cout<<"Size : "<<v.size() <<endl;

    cout<<"Element at 2nd index : "<<v.at(2) <<endl;

    cout<<"Front : "<<v.front() <<endl;
    cout<<"Back : "<<v.back() <<endl;

    cout<<"Before PoP : "<<endl;
    for(int i: v){
        cout<<i<<" ";

    }cout <<endl;

    v.pop_back();

    cout<<"After POP : "<<endl;
    for(int i: v){
        cout<<i<<" ";
    }cout <<endl;

    cout<<"Before clear Size : "<<v.size()<<endl;
    v.clear();
    cout<<"After Clear Size : "<<v.size()<< endl;

}