
#ifndef NODE_H
#define NODE_H
#include<ostream>

using namespace std;

template<typename T>
class Node; //cabecera para poder poner la cabecera del operador friend

template<typename T>
ostream& operator<<(ostream &out, const Node<T> &node);//cabecera operador 

template<typename T>

class Node{

	public:
		//Atributos publicos
		T data;
		Node<T>* next; //puntero al siguiente
		
		//metodos (constructor y el que imprime por pantalla)
		Node(T data, Node<T>* next=nullptr);
		friend ostream& operator<< <T>(ostream &out, const Node<T> &node); //imprime el nodo por pantallla

};

//implementacion de los metodos

template <typename T>
Node<T>::Node (T data, Node<T>* next){

	this->data = data; //gardo en data de mi clase el data qeu recibo
	this->next = next;

}


template <typename T>
ostream& operator<<(ostream &out, const Node<T> &node){

        out<<node.data; //imprime el dato del nodo
        return out;


}

#endif
