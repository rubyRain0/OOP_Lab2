#pragma once
#include <iostream>

class Matrix
{	
	int size;
	double** squareMatrix;
public:
	Matrix(int n)
	{
		/*std::cout << "Constructor\n";*/
		this->size = n;
		squareMatrix = new double* [size];
		for (size_t i = 0; i < size; i++)
		{
			squareMatrix[i] = new double [size];
		}
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				squareMatrix[i][j] = 0;
			}
		}
	};
	Matrix(const Matrix& obj)
	{	
		/*std::cout << "Copy constructor.\n";*/
		this->size = obj.size;
		this->squareMatrix = new double* [obj.size];
		for (size_t i = 0; i < obj.size; i++)
		{
			this->squareMatrix[i] = new double [obj.size];
		}
		for (size_t i = 0; i < obj.size; i++)
		{
			for (size_t j = 0; j < obj.size; j++)
			{
				this->squareMatrix[i][j] = obj.squareMatrix[i][j];
			}
		}

	};
	Matrix& operator=(const Matrix& matrix);
	Matrix operator+(const Matrix& matrix);
	Matrix operator-(const Matrix& matrix);
	Matrix operator*(const Matrix& matrix);
	bool operator<(const Matrix& matrix);
	bool operator>(const Matrix& matrix);
	bool operator<=(const Matrix& matrix);
	bool operator>=(const Matrix& matrix);
	friend void operator<<(std::ostream& output, const Matrix& matrix);
	friend void operator>>(std::istream& input, const Matrix& matrix);
	~Matrix()
	{	
		/*std::cout << "Destructor.\n";*/
		for (size_t i = 0; i < size; i++)
		{
			delete squareMatrix[i];
		}
		delete squareMatrix;
	};
};