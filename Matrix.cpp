#include "Matrix.h"
#include <iostream>


bool Matrix::check_quadro()
{
	if (x == y)
		return true;
	else
		return false;
}

void Matrix::alloc()
{
	matrix = new int* [x];
	for (int i = 0; i < x; i++)
		matrix[i] = new int[y];
}

Matrix::Matrix()
{
	x = 0;
	y = 0;
	matrix = nullptr;
}

Matrix::Matrix(int _x, int _y)
{
	std::cout << _x << _y << "_x_y\n\n";
	x = _x;
	y = _y;
	alloc();
}

Matrix::Matrix(int _x)
{
	x = _x;
	y = _x;
	alloc();
}

Matrix::Matrix(const Matrix& a)
{
	x = a.x;
	y = a.y;
	alloc();
	
	for (int i = 0; i < a.x; i++)
	{
		for (int j = 0; j < a.y; j++)
			matrix[i][j] = a.matrix[i][j];
	}
}



Matrix::~Matrix()
{
	std::cout << "destructor \n\n" << x << y << std::endl << std::endl;
	if (x > 0)
	{

		for (int i = 0; i < x; i++)
			delete[]matrix[i];
		if (y > 0)
			delete[]matrix;
	}
}

void Matrix::showme()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << "A[" << i << "][" << j << "] = " << matrix[i][j] << std::endl;
		}
	}
}

int Matrix::get_el(int _x, int _y)
{
	return matrix[_x][_y];
}

int Matrix::sizex()
{
	return x;
}

int Matrix::sizey()
{
	return y;
}

void Matrix::set_el(int _x, int _y, int el)
{
	if (_x < x && _y < y)
		matrix[_x][_y] = el;
	else
		std::cout << "Incorrect input\n";
}

Matrix Matrix::operator=(Matrix a)
{
	if (this == &a)
		return *this;

	if (x != a.x || y != a.y)
	{
		for (int i = 0; i < x; i++)
			delete[] matrix[i];

		delete[]matrix;
		x = a.x;
		y = a.y;
		alloc();
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			matrix[i][j] = a.matrix[i][j];
	}
	return *this;
}

Matrix Matrix::operator+(Matrix a)
{
	if (x == a.x && y == a.y)
	{
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
				matrix[i][j] = matrix[i][j] + a.matrix[i][j];
		}
		return *this;
	}
	else
	{
		std::cout << "Different size";
		return 0;
	}
}

Matrix Matrix::operator-(Matrix a)
{
	if (x == a.x && y == a.y)
	{
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
				matrix[i][j] = matrix[i][j] - a.matrix[i][j];
		}
		return *this;
	}
	else
	{
		std::cout << "Different size";
		return 0;
	}
}

Matrix Matrix::operator*(Matrix a)
{
	Matrix tmp(x, a.y);
	if (y != a.x)
	{
		std::cout << "Multiplication is impossible";
		return 0;
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < a.y; j++)
		{
			tmp(i, j) = 0;
			for (int k = 0; k < y; k++)
				tmp.matrix[i][j] = tmp.matrix[i][j] + (matrix[i][k] * a.matrix[k][j]);
		}
	}
	std::cout << tmp.matrix[1][2];
	return tmp;
}

Matrix Matrix::operator*(int a)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			matrix[i][j] *= a;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& output, const Matrix& a)
{
	for (int i = 0; i < a.x; i++)
	{
		for (int j = 0; j < a.y; j++)
		{
			output << "A[" << i << "][" << j << "] = " << a.matrix[i][j] << std::endl;
		}
	}
	return output;
}

std::istream& operator>>(std::istream& input, Matrix& a)
{
	for (int i = 0; i < a.x; i++)
	{
		for (int j = 0; j < a.y; j++)
		{
			std::cout << "A[" << i << "][" << j << "] = ";
			input >> a.matrix[i][j];
		}
	 }
	return input;
}
