#include <iostream>
#include <vector>

using namespace std;

class Nodo
{
public:
    int num;
    vector<Nodo*>hijos;

    Nodo(int num)
    {
        this->num = num;
    }

    void imprimir()
    {
        cout<<num<<endl;
        for(int i=0;i<hijos.size();i++)
            hijos[i]->imprimir();
    }

    void sumar(){

    }
};

int main()
{
    Nodo*n1 = new Nodo(1);
    Nodo*n2 = new Nodo(2);
    Nodo*n3 = new Nodo(3);
    Nodo*n4 = new Nodo(4);
    Nodo*n5 = new Nodo(5);
    Nodo*n6 = new Nodo(6);
    Nodo*n7 = new Nodo(7);

    n1->hijos.push_back(n2);
    n1->hijos.push_back(n3);
    n1->hijos.push_back(n4);

    n2->hijos.push_back(n5);

    n4->hijos.push_back(n6);
    n4->hijos.push_back(n7);

    n4->imprimir();

    return 0;
}
