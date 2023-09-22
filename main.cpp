#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    Vector<int> v;
    cout << ((v.At(-4) != nullptr) ? v.At(-4) : 0 ) << " " << ((v.At(0) != nullptr) ? *v.At(0) : 0 ) << " " << ((v.At(2) != nullptr) ? *v.At(2) : 0 ) << endl;
    cout << v.Capacity() << endl;
    v.PushBack(4);
    v.PushBack(5);
    v.PushBack(6);
    v.PushBack(7);
    v.PushBack(8);
    v.PushBack(9);
    v.PushBack(10);
    v.PushBack(11);
    v.PushBack(12);
    v.PushBack(13);
    v.PushBack(14);
    v.PushBack(15);
    cout << ((v.At(-4) != nullptr) ? v.At(-4) : 0 ) << " " << ((v.At(0) != nullptr) ? *v.At(0) : 0 ) << " " << ((v.At(2) != nullptr) ? *v.At(2) : 0 ) << endl;
    cout << v.Capacity() << endl;
    return 0;
}
