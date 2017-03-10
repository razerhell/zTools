#ifndef ZMATRIX_H
#define ZMATRIX_H

template <typename T>
class ZMatrix
{
private:
	size_t mRowSize;
	size_t mColSize;

protected:
	T ** data;

public:
	ZMatrix();

};

#include "zmatrix.inl"

#endif
