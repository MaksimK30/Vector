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
    void Assign(Vector<T> *newVector){
        if(size == 0){
            return;
        }

        for(int i = 0; i < size; i++){
            newVector->PushBack(internalArr[i]);
        }
    }

    //Удаляет вектор и переносит его элементы в новый вектор, начиная с определённого индекса
    void Assign(Vector<T> *newVector, int start){
        if(size == 0){
            return;
        }

        if(start < 0){
            throw std::out_of_range("Index out of range");
        }

        newVector->InsertArray(start, internalArr, size);
    }

    //Возвращает элемент в выбранной позиции
    T At(int position){
        if(position < 0 || position > size - 1){
            throw std::out_of_range("Index out of range");
        }

        return internalArr[position];
    }

    //Возвращает последний элемент
    T Back(){
        return size == 0 ? internalArr : internalArr[size - 1];
    }

    //Возвращает количество элементов, которое может быть добавлено без повторного выделения памяти
    int Capacity(){
        return capacity;
    }

    //Очищает вектор, выделяя новое место в памяти
    void Clear(){
        size = 0;
        delete [] internalArr;
        internalArr = new T[capacity]{};
    }

    //Проверяет пуст ли вектор
    bool Empty(){
        return size == 0;
    }

    //Возвращает первый элемент вектора
    T Front(){
        return size == 0 ? nullptr : internalArr[0];
    }

    //Вставляет элемент по указанному индексу
    void Insert(int index, T value){

        if(index < 0 || index > size - 1){
            throw std::out_of_range("Index out of range");
        }

        CheckCapacity(index);

        if(size < index){
            size = index + 1;
        }

        internalArr[index] = value;
    }

    //Вставляет элементы, начиная с указанного индекса
    void InsertArray(int index, T *values, int arrSize){
        int lastIndex = index + arrSize;

        CheckCapacity(lastIndex);

        for(int i = index, j = 0; i <= lastIndex; i++, j++){
            internalArr[i] = values[j];
        }

        if(size < lastIndex){
            size = lastIndex;
        }
    }

    //Удаляет элемент по указанному индексу
    void Erase(int index){

        if(size <= index || index < 0){
            throw std::out_of_range("Index out or range");
        }

        for(int i = index; i < size - 1; i++){
            internalArr[i] = internalArr[i + 1];
        }

        size--;
    }

    //Удаляет элементы, начиная с указанного индекса
    void Erase(int start, int end){

        if(size <= end || start < 0){
            throw std::out_of_range("Index out or range");
        }else if(start >= end){
            throw "Start index must be bigger, than end index";
        }

        for(int i = start, j = end; i < end; i++, j++){
            internalArr[i] = internalArr[j + 1];
        }

        size -= end - start + 1;
    }

    //Удаляет последний элемент вектора и возвращает его
    T PopBack(){
        return size == 0 ? throw std::out_of_range("Index out of range") : internalArr[size - 1];
        size--;
    }

    //Удаляет первый элемент вектора и возвращает его
    T PopFront(){
        return size == 0 ? throw std::out_of_range("Index out of range") : internalArr[0];
        size--;
    }

    //Вставляет элемент в конец
    void PushBack(T value){
        CheckCapacity(size + 1);

        internalArr[size] = value;
        size++;
    }

    //Вставляет элемент в начало
    void PushFront(T value){

        if (size != 0){            
            CheckCapacity(size + 1);

            for(int i = size - 1; i >= 0; i--){
                internalArr[i + 1] = internalArr[i];
            }
        }

        internalArr[0] = value;
        size++;
    }

    //Возвращает количество элементов в векторе
    int Size(){
        return size;
    }

    //Сократить размер выделенной памяти под количество элементов
    void ShrinkToFit(){
        capacity = size;
        T *newArr = new T[capacity]{};

        for(int i = 0; i < size; i++){
            newArr[i] = internalArr[i];
        }

        delete [] internalArr;
        internalArr = newArr;
    }

    ~Vector(){
        delete [] internalArr;
    }

private:
    int capacity;
    int size;
    T* internalArr;

    //Расширяет вектор при необходимости
    void CheckCapacity(int newSize){
        if(capacity < newSize){
            capacity = static_cast<int>(newSize * 1.5);

            T *newArr = new T[capacity]{};

            for(int i = 0; i < size; i++){
                newArr[i] = internalArr[i];
            }

            delete [] internalArr;
            internalArr = newArr;
        }
    }
};

#endif // VECTOR_H
