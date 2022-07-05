#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;

SortedMap::SortedMap(Relation r) {
	first = nullptr;
	this->rel = r;
}

TValue SortedMap::add(TKey k, TValue v) {
	if (this->isEmpty())
	{
		this->first = new Node;
		this->first->next = nullptr;
		this->first->data = std::make_pair(k, v);
		return NULL_TVALUE;
	}
	Node* aux = first;
	while (aux != nullptr)
	{
		if (k == aux->data.first)
		{
			TValue old = aux->data.second;
			aux->data.second = v;
			return old;
		}
		if (this->rel(k,aux->data.first)) //??????
		{
			Node* p = new Node;
			TElem data = std::make_pair(k, v);
			p->data = data;
			p->next = aux->next;
			aux->next = p;
			break;
		}
	}
	return NULL_TVALUE;
}

TValue SortedMap::search(TKey k) const {
	//TODO - Implementation
	Node* aux = first;
	while (aux != nullptr)
	{
		if (aux->data.first == k)
			return aux->data.second;
		aux = aux->next;
	}
	return NULL_TVALUE;
}

TValue SortedMap::remove(TKey k) {
	Node* aux = first;
	Node* prev = first;
	if (this->size() == 1 && this->first->data.first == k)
	{
		this->first = nullptr;
	}
	while (aux != nullptr)
	{
		if (k == aux->data.first)
		{
			TValue data = aux->data.second;
			prev->next = aux->next;
			delete aux;
			return data;
		}
		prev = aux;
		aux = aux->next;
	}
	return NULL_TVALUE;
}

int SortedMap::size() const {
	int k = 0;
	Node* aux = first;
	while (aux != nullptr)
	{
		k++;
		aux = aux->next;
	}
	return k;
}

bool SortedMap::isEmpty() const {
	return this->size() == 0 ? true : false;
}

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

SortedMap::~SortedMap() {
	delete this->first;
}


TElem SortedMap::getElement(unsigned int c) const
{
	Node* aux;
	aux = first;
	if(c < this->size())
		for (unsigned int i = 0; i < c; i++)
		{
			aux = aux->next;
		}
	return aux->data;
}
