

// Implementation here
#include <iostream>
#include "../include/Stack.h"
#include "../include/CardTypes.h"

#include <vector>
using namespace std;
template <class T>
Stack<T>::Stack(){
	this->stack = std::vector<T>();

}

template <class T>
Stack<T>::Stack(std::vector<T> s){
	this->stack = s;

}
template <class T>
Stack<T> Stack<T>::push(T e){

	vector<T> Seq = vector<T>(stack);
	Seq.push_back(e);
	return Stack(Seq);
	
}

template <class T>
Stack<T> Stack<T>::pop(){
	vector<T> Seq = vector<T>(stack);
	Seq.pop_back();
	return Stack(Seq);
}

template <class T>
T Stack<T>::top(){
	return this->stack.back();
}

template <class T>
unsigned int Stack<T>::size(){
	return this->stack.size();
}

template <class T>
std::vector<T> Stack<T>::toSeq(){
	
	return this->stack;
}


template class Stack<CardT>;



