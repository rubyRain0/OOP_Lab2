#include "Matrix.h"

int main()
{
	Matrix matrixA(3);
	Matrix matrixB(3);
	Matrix matrixC(3);

	std::cin >> matrixA;
	std::cin >> matrixB;

	matrixC = matrixA - matrixB; // + - *
	std::cout << matrixC;
	matrixC = matrixA + matrixB; // + - *
	std::cout << matrixC;
	matrixC = matrixA * matrixB; // + - *
	std::cout << matrixC;

	std::cout << (matrixA > matrixC); // > < >= <=

	std::cin.get();
}