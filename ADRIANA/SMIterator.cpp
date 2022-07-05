#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){
	this->current = 0;
}

void SMIterator::first(){
	this->current = 0;
}

void SMIterator::next(){
	if (this->current < this->map.size())
		this->current++;
	else
		throw(std::exception());
}

bool SMIterator::valid() const{
	if (this->current >= 0 && this->current < this->map.size())
		return true;
	return false;
}

TElem SMIterator::getCurrent() const{
	if (this->valid())
		return this->map.getElement(this->current);
	throw(std::exception());
}


