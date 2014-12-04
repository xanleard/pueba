#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int >mi_cola;
    mi_cola.push(10);
        mi_cola.push(20);
        mi_cola.push(30);


        while (!mi_cola.empty()){
            cout<<mi_cola.front()<<endl;
            mi_cola.pop();
        }
    return 0;
}
