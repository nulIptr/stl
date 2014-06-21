#pragma once
#include<iostream>
#include<memory>




#define MAX 3
//typedef int Element;
template<typename Element>
class STACK
{
public:
	STACK();
	~STACK();
	bool Is_Empty();
	bool ViewStack(Element& e);
	bool Push(Element e);
	bool Pop(Element& e);
	bool ClearStack();
	inline int GetLenth(){
		return Top - Base;
	}
private:
	Element* Base;
	Element* Top;
	int size;
	bool Is_Full();

};

template<typename Element>
STACK::STACK()
{
	Element* p = new Element[MAX];
	Base = Top = p;
	size = MAX;
}

template<typename Element>
STACK::~STACK()
{
	delete[]Base;
	Base = Top = NULL;
	size = 0;
}

template<typename Element>
bool STACK::Is_Empty(){
	return Top == Base;
}

template<typename Element>
bool STACK::Is_Full(){
	return Top - Base == size;
}

template<typename Element>
bool STACK::Push(Element e){
	*(Top++) = e;
	if (Is_Full())
	{
		Element*p = new Element[size + MAX];
		memcpy(p, Base, size*sizeof(Element));
		delete[]Base;
		Base = p;
		Top = Base + size;
		size += MAX;
		return true;
	}
	return true;
}

template<typename Element>
bool STACK::Pop(Element& e){
	e = *(--Top);
	return true;
}

template<typename Element>
bool STACK::ClearStack(){
	Top = Base;
	return true;
}

template<typename Element>
bool STACK::ViewStack(Element& e){
	e = *(Top - 1);
	return true;
}
