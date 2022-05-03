#pragma once
#ifndef SEQUENCE_H
#define SEQUENCE_H

template<typename Type>
class Sequence {
public:
	//getters
	virtual Type GetFirst() const;
	virtual Type GetLast() const;
	virtual Type Get(int index) const;
	virtual Sequence<Type>* GetSubsequence(int startIndex, int endIndex) const;
	virtual int GetLength() const;
	//setters
	virtual void Append(Type item);
	virtual void Prepend(Type item);
	virtual void InsertAt(Type item, int index);
	virtual Sequence <Type>* Concat(Sequence <Type>* list);
	//destructor
	virtual ~Sequence() {}
};

#endif