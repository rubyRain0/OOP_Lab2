#include "Matrix.h"

Matrix& Matrix::operator=(const Matrix& matrix)
{
	if (&matrix != this)
	{
		size = matrix.size;
		squareMatrix = new double* [size];
		for (size_t i = 0; i < size; i++)
		{
			squareMatrix[i] = new double[size];
		}
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				squareMatrix[i][j] = matrix.squareMatrix[i][j];
			}
		}
		return *this;
	}
}
Matrix Matrix::operator+(const Matrix& matrix)
{
	if (this->size == matrix.size)
	{
		Matrix result(matrix.size);
		for (size_t i = 0; i < matrix.size; i++)
		{
			for (size_t j = 0; j < matrix.size; j++)
			{
				result.squareMatrix[i][j] = this->squareMatrix[i][j] + matrix.squareMatrix[i][j];
				/*std::cout << result.squareMatrix[i][j] << ' ';*/
			}
		}
		return result;
	}
	else
	{
		std::cout << "Wrong size(s)...\n";
		exit(1);
	}
}
Matrix Matrix::operator-(const Matrix& matrix)
{
	if (this->size == matrix.size)
	{
		Matrix result(matrix.size);
		for (size_t i = 0; i < matrix.size; i++)
		{
			for (size_t j = 0; j < matrix.size; j++)
			{
				result.squareMatrix[i][j] = this->squareMatrix[i][j] - matrix.squareMatrix[i][j];
				/*std::cout << result.squareMatrix[i][j] << ' ';*/
			}
		}
		return result;
	}
	else
	{
		std::cout << "Wrong size(s)...\n";
		exit(1);
	}
}
Matrix Matrix::operator*(const Matrix& matrix)
{
	if (this->size == matrix.size)
	{
		Matrix result(matrix.size);
		for (size_t i = 0; i < matrix.size; i++)
		{
			for (size_t j = 0; j < matrix.size; j++)
			{
				for (size_t k = 0; k < matrix.size; k++) 
					result.squareMatrix[i][j] += this->squareMatrix[i][k] * matrix.squareMatrix[k][j];
				/*std::cout << result.squareMatrix[i][j] << ' ';*/
			}
		}
		return result;
	}
	else 
	{
		std::cout << "Wrong size(s)...\n";
		exit(1);
	}
}
bool Matrix::operator<(const Matrix& matrix)
{
	if (this->size < matrix.size) return true;
	return false;
}
bool Matrix::operator>(const Matrix& matrix)
{
	if (this->size > matrix.size) return true;
	return false;
}
bool Matrix::operator<=(const Matrix& matrix)
{
	if (this->size <= matrix.size) return true;
	return false;
}
bool Matrix::operator>=(const Matrix& matrix)
{
	if (this->size >= matrix.size) return true;
	return false;
}
void operator<<(std::ostream& output, const Matrix& matrix)
{
	for (size_t i = 0; i < matrix.size; i++)
	{
		for (size_t j = 0; j < matrix.size; j++)
		{
			output << matrix.squareMatrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}
void operator>>(std::istream& input, const Matrix& matrix)
{
	for (size_t i = 0; i < matrix.size; i++)
	{
		for (size_t j = 0; j < matrix.size; j++)
		{	
			std::cout << "Enter element [" << i + 1 << "][" << j + 1 << "]\n";
			input >> matrix.squareMatrix[i][j];
		}
	}
}