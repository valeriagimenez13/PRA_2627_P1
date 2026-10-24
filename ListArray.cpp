#include "ListArray.h"
#include <iostream>
#include<stdexcept> //por la excepcion

using namespace std;

template<typename T>
const int ListArray<T>::MINSIZE = 2;

template <typename T> //Como ListArray.h declara una clase genérica, los métodos que implemente también lo serán

ListArray<T>::ListArray(){

        max=MINSIZE;
        n=0; // la lista empieza sin elementos
        arr = new T[max]; //creo un puntero al array con el nuevo array inicializado con la capacidad maxima del array = MINSIZE.Y ademas, la lista empieza sin elementos

}

template <typename T>

ListArray<T>::~ListArray() {

        //Como he creado el objeto vector en memoria dinámica, entonces si elimino el array  solo elimno el array, devo usar el destructor para liberar espacio de memoria que he usado para guardar el array

        delete[] arr;

}


template <typename T>
void ListArray<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n) {
        throw out_of_range("Posicion no valida");
    }

    // Si el array está lleno, duplicamos su capacidad
    if (n == max) {
        resize(max * 2);
    }

    // Desplazamos los elementos para dejar hueco
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = e;
    n++;
}


// Añadir un elemento al final
template <typename T>
void ListArray<T>::append(T e) {
    insert(n, e);
}

// Añadir un elemento al principio
template <typename T>
void ListArray<T>::prepend(T e) {
    insert(0, e);
}

// Eliminar y devolver el elemento de una posición
template <typename T>
T ListArray<T>::remove(int pos) {
    if (pos < 0 || pos >= n) {
        throw out_of_range("Posicion no valida");
    }

    T eliminado = arr[pos];

    // Desplazamos los elementos hacia la izquierda
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    return eliminado;
}

// Consultar el elemento de una posición
template <typename T>
T ListArray<T>::get(int pos) {
    if (pos < 0 || pos >= n) {
        throw out_of_range("Posicion no valida");
    }

    return arr[pos];
}

// Buscar un elemento y devolver su posición
template <typename T>
int ListArray<T>::search(T e) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == e) {
            return i;
        }
    }

    return -1;
}

// Comprobar si la lista está vacía
template <typename T>
bool ListArray<T>::empty() {
    return n == 0;
}

// Devolver el número de elementos
template <typename T>
int ListArray<T>::size() {
    return n;
}



template <typename T>

T ListArray<T>::operator[] (int pos) {

        if(pos<0 || pos>=n){

                throw std::out_of_range("POsicion no valida");

        }

        return arr[pos];
}

template <typename T>

ostream& operator<<(ostream &out, ListArray<T> &list){

        for(int i=0; i<list.n; i++){ //me pasan la lisa ya como objeto

                out<<list.arr[i];

        }

	return out;

}

template <typename T>

void ListArray<T>::resize(int new_size){

        T* new_arr = new T[new_size];//Creo un nuevo array para hacerlo con el nuevo tamaño

        for(int i=0; i<n; i++){

                new_arr[i]=arr[i];

        }

        delete[] arr; //para librerar la memoria del array anterior pero no la variable
        arr=new_arr; // sustituyo ls variable arr por el nuevo vector
        max=new_size; //ahora el tamaño maximo será el del array nuevo
}


template class ListArray<int>; //el programa de prueba utiliza int, asi que pongo eso para que me funcione

template ostream& operator<< <int>(ostream&, ListArray<int>&);
