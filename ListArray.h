#ifndef LISTARRAY_H
#define LISTARRAY_H
#include<iostream>
#include "List.h"

using namespace std;

template <typename T>

class ListArray;

template<typename T> //LO pongo cada vez que declaro una clase genérica
ostream& operator<<(ostream &out, ListArray<T> &list); // funcion genérica que imprime listas de distintos tipos

template <typename T>

class ListArray : public List<T>{

        private:
                T*arr;
                int max;
                int n;
                static const int MINSIZE;
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
#endif
