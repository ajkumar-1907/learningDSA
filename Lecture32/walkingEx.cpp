#include<iostream> 
using namespace std;

void reachHome(int src, int dest) {
    
    cout << "source " << src  << " destination " << dest << endl;
    //base case
    if(src == dest) {
        cout << "   Reached Destination " << endl;
        return ;
    }

    src++;


    reachHome(src, dest);

}

int main() {

    int dest = 10;
    int src = 1;

    cout << endl;

    reachHome(src, dest);


    return 0;
}