#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    Vector<int> v;
    v.PushFront(4);
    v.PushFront(3);
    v.PushBack(5);
    v.PushFront(2);
    v.PushFront(1);

    for(int i = 0; i < v.Size(); i++){
        cout << *v.At(i) << endl;
    }

    return 0;
}
