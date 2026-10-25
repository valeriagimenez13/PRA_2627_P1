
#ifndef LIST_LINKED_H
#define LIST_LINKED_H
#include<ostream>
#include<stdexcept>
#include "List.h"
#include "Node.h"


using namespace std;

template<typename T>
class ListLinked;

template<typename T>
ostream& operator<<(ostream &out, ListLinked<T> &list);

template <typename T>

class ListLinked : public List<T>{

	private:
		Node<T>* first;
		int n;
	public:
		//metodos que hereda por que List.h es una clase abstracta 

		void insert(int pos, T e) override;
		void append(T e) override;
		void prepend(T e) override;
		T remove(int pos) override;
		T get(int pos) override;
		int search(T e) override;
		bool empty() override;
		int size() override;

		//metodos de la propia clase
		ListLinked();
		~ListLinked() override;
		T operator[](int pos);
		friend ostream& operator<< <T>(ostream &out, ListLinked<T> &list);

};


//implementacion de los métodos

template <typename T>

ListLinked<T>::ListLinked(){

	first = nullptr;
	n=0;

}

template <typename T>

ListLinked<T>::~ListLinked() {

        //debo ir pasando de nodo en nodo y eliminandolos
	
	while(first!=nullptr){
	
		Node<T>* aux=first->next;
		delete first;
		first=aux;

	}

}

//Metodos virtuales heredados de la clase List.h

template <typename T>
void ListLinked<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n) {
        throw out_of_range("Posicion no valida");
    }

    if(pos == 0){
    
	    first = new Node<T>(e,first);

    }else{
    	
	// movemos el siguiente al siguiente e insertamos en la posicion
    	    Node<T>* actual = first;


	for (int i = 0; i < pos-1; i++) {
		actual=actual->next;
	}

	actual -> next = new Node<T>(e,actual->next); //creo el nodo con el elemento y la posicicon
	//primero se crea el nuevo apuntando al que apuntava el actual y luego cambia el que apunta el actual por el nuevo que apunta al que antes era el siguiente
    }

    n++;
}



template <typename T>
void ListLinked<T>::append(T e) {
    insert(n, e);
}



template <typename T>
void ListLinked<T>::prepend(T e) {
    insert(0, e);
}


template <typename T>
T ListLinked<T>::remove(int pos) {
    if (pos < 0 || pos >= n) {
        throw out_of_range("Posicion no valida");
    
    }
    Node<T>* eliminado;
    T dato;
    if(pos==0){
    
	    eliminado = first;
	    dato= eliminado->data;
	    first=first->next;
	    delete eliminado;
    }else{

	Node<T>* actual = first;
	
 	for (int i = 0; i < pos-1; i++) {
	actual=actual->next;
    	}

    	eliminado = actual->next;
    	dato = eliminado->data;
	actual->next=eliminado->next;
    	delete eliminado;
    }

    n--;

    return dato;
}


template <typename T>
T ListLinked<T>::get(int pos) {
    if (pos < 0 || pos >= n) {
        throw out_of_range("Posicion no valida");
    }

    Node<T>* actual = first;

    for(int i=0; i<pos; i++){
    
	actual = actual->next;

    }

    T dato = actual->data;

    return dato;
}


template <typename T>
int ListLinked<T>::search(T e) {

	Node<T>* actual=first;
	for (int i = 0; i < n; i++) {
		if (actual->data == e) {
		return i;
		}

		actual=actual->next;
	}

	return -1;
}


template <typename T>
bool ListLinked<T>::empty() {
    return n == 0;
}


template <typename T>
int ListLinked<T>::size() {
    return n;
}

//implemento ls métodos de la clase ListArray suyos

template <typename T>

T ListLinked<T>::operator[] (int pos) {

        if(pos<0 || pos>=n){

                throw std::out_of_range("Posicion invalida");

        }
	
	Node<T>* actual=first;

	for(int i=0;i<pos; i++){

		actual=actual->next;

	}

	T dato = actual->data;

        return dato;
}

template <typename T>

ostream& operator<<(ostream &out, ListLinked<T> &list){
	out<<"List => [";
	Node<T>* actual=list.first;

        for(int i=0; i<list.n; i++){ //me pasan la lisa ya como objeto
                out<<"\n "<<actual->data;
		actual=actual->next;
        }
	out << "\n]";
        return out;
}

#endif

