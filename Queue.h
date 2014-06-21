#pragma once
#include<cstddef>
#include<utility>

template<typename Element>
struct Node
{
	Element data;
	Node* next;
};
template<typename Element>
class Queue
{
public:
	Queue();
	~Queue();
	Queue& enQueue(Element data);
	Queue& deQueue(Element data);
	Queue& getHead(Element data);
	void traveQueue(void(*vi)(Element));
	inline bool isEmpty(){
		return HEAD == nullptr;
	}
	inline int getSize(){
		return size;
	}
	Queue& clear(); 
private:
	Node<Element>* addtopool();
	Node<Element>* getfrompool();
	Node<Element>* HEAD;
	Node<Element>* TAIL;
	int size;
	Node<Element>*Pool;
};


using namespace std;

template<typename Element>
Queue<Element>::Queue()
{
	HEAD = TAIL = nullptr;
	size = 0;
}
template<typename Element>
Queue<Element>::~Queue()
{
	Node<Element>* p = HEAD;
	while (size>1)
	{
		HEAD = HEAD->next;
		delete p;
		p = HEAD
	}
	delete p;
	size = 0;
	HEAD = TAIL = nullptr;
}


template<typename Element>
Queue<Element>& Queue<Element>::enQueue(Element data){
	Node<Element>* temp = new Node<Element>;
	temp.data = data;
	if (this->isEmpty())
	{
		temp->next = HEAD->next;
		HEAD->next = temp;
		TAIL = HEAD;
	}
	else
	{
		TAIL->next = temp;
		temp = TAIL;
	}
	++size;
}

template<typename Element>
Queue<Element>& Queue<Element>::deQueue(Element data){
	if (this->isEmpty())
	{
		throw{
			;
		}
	}
	else
	{
		data = HEAD->next->data;
		Node<Element>*p = HEAD->next;
		HEAD->next = p->next;
		delete p;
	}
	--size;
	if (size == 0)
	{
		HEAD = TAIL = nullptr;
	}
}

template<typename Element>
Queue<Element>& Queue<Element>::getHead(Element data){
	if (this->isEmpty())
	{
		throw{
			;
		}
	}
	else
	{
		data = HEAD->next->data;
	}
}
int main(){
	return 0;
}