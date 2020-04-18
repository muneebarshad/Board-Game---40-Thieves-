/**
 * \file Stack.h
 * \author Muneeb Arshad
 * \Working parteners : Harshil Modi and Mariana Marilies 
 * \brief Creates a stack of generic type T.
 */



#ifndef A3_STACK_H_
#define A3_STACK_H_
#include <vector>
#include <iostream>

template<class T>


class Stack{
	private:
		/**
		* \brief Creates a vector stack.
		*/
		//std::vector<T> stack;
		std::vector<T> stack;
		

	public:
		/**
		* \brief default constructor for the stack. Not used in the specification.
		*/
		Stack();

		/**
		* \param Takes input a vector list s.
		* \brief Constructs a stack of a Generic type T
		*/
		Stack(std::vector<T> s);

		/**
		* \param Takes input an item of type T
		* \brief Adds the item T in the stack and returns the stack back.
		*/		
		Stack push(T e);

		/**
		* \brief Removes the top element of type T from the stack
		*/	
		Stack pop();

		/**
		* \return Returns the top element of type T from the stack.
		*/
		T top();


		/**
		* \brief Returns the size of the stack.
		*/
		unsigned int size();

		/**
		* \brief Returns back the vector list of items in the stack.
		*/
		std::vector<T> toSeq();





};
#endif
