#pragma once
#ifndef SEQUENCE_H
#define SEQUENCE_H

template<typename Type>
class Sequence {
	//getters
	virtual Type GetFirst();
	virtual Type GetLast();
	virtual Type Get(int index);
	virtual Sequence<Type>* GetSubsequence(int startIndex, int endIndex);
	virtual int GetLength();
	//setters
	virtual void Append(Type item);
	virtual void Prepend(Type item);
	virtual void InsertAt(Type item, int index);
	virtual Sequence <Type>* Concat(Sequence <Type>* list);
	//destructor
	virtual ~Sequence() {}
};

#endif