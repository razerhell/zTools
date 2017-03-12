#ifndef ZUTILS_H
#define ZUTILS_H

#include <iostream>
#include <vector>
#include <fstream>

// 交换变量
template <typename T>
void zSwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

// 分配1维数组
template <typename T>
T * zAlloc(T *&p, int n1)
{
	p = new T[n1];
	return p;
}

// 释放1维数组
template <typename T>
void zFree1(T *&p)
{
	delete[] p;
	p = NULL;
}

// 为1维数组填充指定数值
template <typename T>
void zMemset1(T * &p, const T&v, int n1)
{
	for (int i = 0; i < n1; ++i) p[i] = v;
}

// 1维数组拷贝
template <typename T>
void zMemcpy1(T *&dst, const T *&src, int n1)
{
	for (int i = 0; i < n1; ++i) dst[i] = src[i];
}

// 分配2维数组
template <typename T>
T ** zAlloc2(T **&p, int n2, int n1)
{
	int i;

	p = new T *[n2];
	if (NULL == p) return NULL;

	p[0] = new T [n1 * n2];
	if (NULL == p[0])
	{
		delete[] p;
		p = NULL;
		return NULL;
	}

	for (i = 0; i < n2; ++i)
		p[i] = p[0] + n1 * i;

	return p;
}

// 释放2维数组
template <typename T>
void zFree2(T **&p)
{
	delete[] p[0];
	delete[] p;
	p = NULL;
}

// 2维数组填充指定数值
template <typename T>
void zMemset2(T **&p, const const T &v, int n2, int n1)
{
	int i, j;
	
	for (i = 0; i < n2; ++i)
		for (j = 0; j < n1; ++j)
			p[i][j] = v;
}

// 2维数组拷贝
template <typename T>
void zMemcpy(T **&dst, const T **&src, int n2, int n1)
{
	int i, j;
	for (i = 0; i < n2; ++i)
		for (j = 0; j < n1; ++j)
			dst[i][j] = src[i][j];
}

// 分配3维数组
template <typename T>
T*** zAlloc3(T ***&p, int n3, int n2, int n1)
{
	int i, j;

	p = new T **[n3];
	if (NULL == p) return NULL;

	p[0] = new T *[n3 * n2];
	if (NULL == p[0])
	{
		delete[] p;
		p = NULL;
		return NULL;
	}

	p[0][0] = new T *[n3 * n2 * n1];
	if (NULL == p[0][0])
	{
		delete[] p[0];
		delete[] p;
		p = NULL;
	}

	for (i = 0; i < n3; ++i)
	{
		p[i] = p[0] + n2 * i;
		for (j = 0; j < n2; ++j)
			p[i][j] = p[0][0] + n1 * (j + n2 * i);
	}

	return p;
}

// 释放3维数组
template <typename T>
void zFree3(T ***& p)
{
	delete[] p[0][0];
	delete[] p[0];
	delete[] p;
	p = NULL;
}

// 3维数组填充指定数值
template <typename T>
void zMemset3(T ***& p, const T & v, int n3, int n2, int n1)
{
	int i, j, k;
	
	for (i = 0; i < n3; ++i)
		for (j = 0; j < n2; ++j)
			for (k = 0; k < n1; ++k)
				p[i][j][k] = v;
}

// 3维数组拷贝
template <typename T>
void zMemcpy3(T ***& dst, const T ***& src, int n3, int n2, int n1)
{
	int i, j, k;

	for (i = 0; i < n3; ++i)
		for (j = 0; j < n2; ++j)
			for (k = 0; k < n1; ++k)
				dst[i][j][k] = src[i][j][k];
}

template <typename T>
bool zReadFile(char * fileName, std::vector<T> &data)
{
	std::ifstream in(fileName);
	if (!in.is_open()) return false;

	if (!in.eof())
	{
		T temp;
		in >> temp;
		data.append(temp);
	}

	return true;
}

#endif
