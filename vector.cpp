#include "vector.h"

template <class T>
Vector<T>::Vector()
{
    size = 0;
    capacity = 10;
    internalArr = new T[capacity]{};
}

//Удаляет вектор и переносит его элементы в новый вектор
template <class T>
void Vector<T>::Assign(Vector<T> const & newVector){

}

//Возвращает ссылку на элемент в выбранной позиции
template <class T>
T& Vector<T>::At(int const position){

}

//Возвращает ссылку на последний элемент
template <class T>
T& Vector<T>::Back(){

}

//Возвращает количество элементов, которое может быть добавлено
//без повторного выделения памяти
template <class T>
int Vector<T>::Capacity(){
    return capacity;
}

//Очищает вектор
template <class T>
void Vector<T>::Clear(){
    size = 0;
    capacity = 10;
    internalArr = new T[capacity]{};
}

//Проверяет пуст ли вектор
template <class T>
bool Vector<T>::Empty(){
    return size == 0 ? true : false;
}

//Возвращает первый элемент вектора
template <class T>
T& Front(){

}

//Вставляет элемент в указанную позицию
template <class T>
void Vector<T>::Insert(int const position, T const value){

}

//Вставляет элементы, начиная с указанной позиции
template <class T>
void Vector<T>::Insert(int const position, T const * values[]){

}

//Удаляет элемент в указанной позиции
template <class T>
void Vector<T>::Erase(int const position){

}

//Удаляет элементы, начиная с указанной позиции
template <class T>
void Vector<T>::Erase(int const start, int const end){

}

//Удаляет элементы в указанном диапазоне(включительно)
template <class T>
T Vector<T>::PopBack(){

}

//Вставляет элемент в конец
template <class T>
void Vector<T>::PushBack(T const & value){

}

//Вставляет элемент в начало
template <class T>
void Vector<T>::PushFront(T const & value){

}

//Возвращает количество элементов в векторе
template <class T>
int Vector<T>::Size(){
    return size;
}

