#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;



template <class T>
class Stack
{
private:

	T* MyStack;
	int sommet;
	int capacity;
public:
	Stack();
	~Stack();
	bool isEmpty();
	bool isFull();
	void resize();
	void Push(T object);
	T Pop();
	int Size();
	void AfficherStack();

};





template<class T>
inline Stack<T>::Stack():sommet(-1),capacity(2)
{
	this->MyStack = new T[2];
}

template<class T>
inline Stack<T>::~Stack()
{
	delete[] MyStack;
}

template<class T>
inline bool Stack<T>::isEmpty()
{
	if (sommet == -1)
	{
		throw underflow_error("Stack is empty");
	}
	return false;
}

template<class T>
inline bool Stack<T>::isFull()
{
	if (sommet == capacity)
		throw overflow_error("Stack is full");

	return false;
}

template<class T>
inline void Stack<T>::resize()
{

	T* Temp = new T[this->capacity];
	this->capacity *= 2;
	int k = 0;
	T* newStack = new T[this->capacity];

	for (int i = sommet - 1; i >=0; i--)

		Temp[k++] = MyStack[i];

	k = 0;
	for (int i = sommet - 1; i>=0; i--)
		newStack[k++]=Temp[i];

		
	delete[] Temp;
	delete[] MyStack;
	MyStack = newStack;

}

template<class T>
inline void Stack<T>::Push(T object)
{

	try
	{
		isFull();
	}
	catch (overflow_error e)
	{
		resize();
	}
	this->MyStack[++this->sommet]= object;

}


template<class T>
inline T Stack<T>::Pop()
{
	
	try
	{
		isEmpty();
		
		return this->MyStack[this->sommet--];
	}
	catch (underflow_error e)
	{
		cout << "Stack is Empty" << endl;
	}
}

template<class T>
inline int Stack<T>::Size()
{
	return sommet+1;
}


template<class T>
inline void Stack<T>::AfficherStack()
{
	try
	{
		isEmpty();
		for (int i = this->sommet; i >= 0; i--)
		{

			cout << this->MyStack[i] << " ";
		}

	}
	catch (const std::underflow_error e)
	{
		cout << e.what() << " Stack is Empty  " << endl;
	}
}
