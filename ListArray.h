#ifndef LISTARRAY_H
#define LISTARRAY_H
#include<iostream>
#include "List.h"

using namespace std;

template <typename T>
class ListArray;

template <typename T>
ostream& operator<<(ostream &out, ListArray<T> &list);

template <typename T>
class ListArray : public List<T>{

        private:
                T*arr;
                int max;
                int n;
                static const int MINSIZE = 2;//lo declaro ya aquí
        public:
                ListArray();
                ~ListArray() override;

		//declaro los métodos virtuales de la clase List<T> ya que son
		//virtuales y deben existir aquí 
		void insert(int pos, T e) override;
		void append(T e) override;
		void prepend(T e) override;
		T remove(int pos) override;
		T get(int pos) override;
		int search(T e) override;
		bool empty() override;
		int size() override;

                T operator[] (int pos);
                friend ostream& operator<< <T>(ostream &out, ListArray<T> &list);
                void resize(int new_size);

};


//AHORA en el mismo documento hago la implementacion


template <typename T> 

ListArray<T>::ListArray(){

        max=MINSIZE;
        n=0; 
        arr = new T[max]; //creo vector memoria dinamica

}

template <typename T>

ListArray<T>::~ListArray() {

        delete[] arr;

}

//Metodos virtuales heredados de la clase List.h

template <typename T>
void ListArray<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n) {
        throw out_of_range("Posicion no valida");
    }

    // Si el array está lleno
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



template <typename T>
void ListArray<T>::append(T e) {
    insert(n, e);
}



template <typename T>
void ListArray<T>::prepend(T e) {
    insert(0, e);
}


template <typename T>
T ListArray<T>::remove(int pos) {
    if (pos < 0 || pos >= n) {
        throw out_of_range("Posicion no valida");
    }

    T eliminado = arr[pos];

    
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    return eliminado;
}


template <typename T>
T ListArray<T>::get(int pos) {
    if (pos < 0 || pos >= n) {
        throw out_of_range("Posicion no valida");
    }

    return arr[pos];
}


template <typename T>
int ListArray<T>::search(T e) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == e) {
            return i;
        }
    }

    return -1;
}


template <typename T>
bool ListArray<T>::empty() {
    return n == 0;
}


template <typename T>
int ListArray<T>::size() {
    return n;
}

//implemento ls métodos de la clase ListArray suyos

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


#endif
