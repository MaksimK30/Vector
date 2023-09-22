#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
template <class T>
class Vector
{
public:
    Vector(){
        size = 0;
        capacity = 10;
        internalArr = new T[capacity]{};
    }

    //Удаляет вектор и переносит его элементы в новый вектор
    void Assign(Vector<T> const & newVector){

    }

    //Возвращает указатель на элемент в выбранной позиции
    T* At(int const position){
        if(position < 0 || position > size - 1){
            return nullptr;
        }

        return &internalArr[position];
    }

    //Возвращает ссылку на последний элемент
    T* Back(){
        return size == 0 ? &internalArr[0] : &internalArr[size - 1];
    }

    //Возвращает количество элементов, которое может быть добавлено//без повторного выделения памяти

    int Capacity(){
        return capacity;
    }

    //Очищает вектор
    void Clear(){
        size = 0;
        capacity = 10;
        internalArr = new T[capacity]{};
    }

    //Проверяет пуст ли вектор
    bool Empty(){
        return size == 0 ? true : false;
    }

    //Возвращает первый элемент вектора
    T* Front(){
        return size == 0 ? nullptr : &internalArr[0];
    }

    //Вставляет элемент в указанную позицию
    void Insert(int const position, T const value){

    }

    //Вставляет элементы, начиная с указанной позиции
    void Insert(int const position, T const * values[]){

    }

    //Удаляет элемент в указанной позиции
    void Erase(int const position){

    }

    //Удаляет элементы, начиная с указанной позиции
    void Erase(int const start, int const end){

    }

    //Удаляет последний элемент вектора и возвращает его
    T PopBack(){
        return size == 0 ? throw std::out_of_range("Index out of range") : internalArr[size - 1];
    }

    //Удаляет первый элемент вектора и возвращает его
    T PopFront(){
        return size == 0 ? throw std::out_of_range("Index out of range") : internalArr[0];
    }


    //Вставляет элемент в конец
    void PushBack(T const value){
        CheckCapacity(size + 1);
        internalArr[size == 0 ? 0 : size] = value;
        size++;
    }

    //Вставляет элемент в начало
    void PushFront(T const value){

        if (size != 0){
            CheckCapacity(size + 1);
            for(int i = size - 1; i >= 0; i--){
                internalArr[i + 1] = internalArr[i];
            }
        }
        internalArr[0] = value;
        size++;}

    //Возвращает количество элементов в векторе
    int Size(){
        return size;
    }


private:
    int capacity;
    int size;
    T* internalArr;

    //Расширяет вектор при необходимости
    void CheckCapacity(int newSize){
        if(capacity < newSize){
            capacity = static_cast<int>(capacity * 1.5);
        }
    }
};

#endif // VECTOR_H
