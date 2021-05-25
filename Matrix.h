#pragma once
#include <iostream>

class Matrix
{
private:

	int** matrix;
	int x;
	int y;


	bool check_quadro();
	void alloc();

public:

	Matrix();
	
	Matrix(int _x, int _y);

	Matrix(int _x);

	Matrix(const Matrix& a);

	~Matrix();

	void showme();

	int get_el(int _x, int _y);

	int sizex();

	int sizey();

	void set_el(int _x, int _y, int el);

	Matrix operator =(Matrix a);

	Matrix operator +(Matrix a);

	Matrix operator -(Matrix a);

	Matrix operator *(Matrix a);

	Matrix operator *(int a);

	inline int& operator()(int x, int y) { return matrix[x][y]; };

	friend std::ostream& operator<<(std::ostream& output, const Matrix& a);

	friend std::istream& operator>>(std::istream& input, Matrix& a);
};

