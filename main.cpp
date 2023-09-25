#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    Vector<int> v;
    cout << v.Back() << endl;
    for(int i = 0; i < 20; i++){
        v.PushBack(i + 1);
    }

    for(int i = 0; i < v.Size(); i++){
        cout << *v.At(i) << " idx = " << i << endl;
    }

    cout << v.Size() << endl << v.Capacity() << endl;
    cout << *v.Front() << endl;

    return 0;
}
