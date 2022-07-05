#pragma once
#include "SortedMap.h"

//DO NOT CHANGE THIS PART
class SMIterator{
	friend class SortedMap;
private:
	const SortedMap& map;
	SMIterator(const SortedMap& mapionar);

	//TODO - Representation
public:
	unsigned int current;
	void first();
	void next();
	bool valid() const;
    TElem getCurrent() const;
};

