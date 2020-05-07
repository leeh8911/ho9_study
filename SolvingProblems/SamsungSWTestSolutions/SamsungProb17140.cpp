#include <iostream>

#ifdef TEST_MODE
#include "SamsungProb17140.h"
#endif

typedef struct tSPARSE_MATRIX
{
	int row;
	int col;
	int val;
	tSPARSE_MATRIX* next_mat;
	tSPARSE_MATRIX* prev_mat;
}SPARSE_MATRIX;

typedef class tSPARSE_MATRIX_HANDLER
{
public:
	int length;
	SPARSE_MATRIX* mat;

	tSPARSE_MATRIX_HANDLER(int row_num, int col_num, int* ar_in[3]);
	~tSPARSE_MATRIX_HANDLER();
	void Transpose();
	void Print();
	void Calculate();
private:

}SPARSE_MATRIX_HANDLER;

using namespace std;
#ifdef TEST_MODE
int Samsung_Prob_17140(void)
#else
int main(void)
#endif
{
#ifdef TEST_MODE
	int i = 1, j = 2, k = 2;
	int** ar_in = (int**)malloc(sizeof(int) * 3);
	for (int row = 0; row < 3; row++)
	{
		ar_in[row] = (int*)malloc(sizeof(int) * 3);
	}
	int temp_ar[3][3] = { {1, 2, 1},
	{2, 1, 3},
	{3, 3, 3}};

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			ar_in[row][col] = temp_ar[row][col];
		}
	}
#else
	int i, j, k;
	int ar_in[3][3];
	cin >> i >> j >> k >> endl;
#endif
	tSPARSE_MATRIX_HANDLER mat(3, 3, ar_in);

	mat.Print();

	mat.Transpose();

	mat.Print();

	return 0;
}




tSPARSE_MATRIX_HANDLER::tSPARSE_MATRIX_HANDLER(int row_num, int col_num, int* ar_in[3])
{
	this->mat = new SPARSE_MATRIX;
	memset(this->mat, 0, sizeof(SPARSE_MATRIX));
	this->length = 0;
	SPARSE_MATRIX* cur_mat = this->mat;

	for (int i = 0; i < row_num; i++)
	{
		for (int j = 0; j < col_num; j++)
		{
			this->length++;
			cur_mat->col = j;
			cur_mat->row = i;
			cur_mat->val = ar_in[i][j];
			if (i == row_num - 1 && j == col_num - 1)
			{
				//
			}
			else
			{
				cur_mat->next_mat = new SPARSE_MATRIX;
				memset(cur_mat->next_mat, 0, sizeof(SPARSE_MATRIX));
				SPARSE_MATRIX* temp_mat = cur_mat;
				cur_mat = cur_mat->next_mat;
				cur_mat->prev_mat = temp_mat;
			}
		}
	}
}

tSPARSE_MATRIX_HANDLER::~tSPARSE_MATRIX_HANDLER()
{

}

void tSPARSE_MATRIX_HANDLER::Transpose()
{
	SPARSE_MATRIX* temp_mat = mat;
	int temp_val = 0;
	for (int i = 0; i < this->length; i++)
	{
		temp_val = temp_mat->col;
		temp_mat->col = temp_mat->row;
		temp_mat->row = temp_val;

		temp_mat = temp_mat->next_mat;
	}
}


void tSPARSE_MATRIX_HANDLER::Calculate()
{
	SPARSE_MATRIX* temp_mat = mat;

}
	void tSPARSE_MATRIX_HANDLER::Print()
	{
		SPARSE_MATRIX* temp_mat = mat;
	int max_row = 0, max_col = 0;

	for (int i = 0; i < this->length; i++)
	{
		if (max_row < temp_mat->row)
			max_row = temp_mat->row;

		if (max_col < temp_mat->col)
			max_col = temp_mat->col;

		temp_mat = temp_mat->next_mat;
	}
	max_row += 1;
	max_col += 1;

	int** ar = (int**)malloc(sizeof(int) * max_row);
	for (int i = 0; i < max_row; i++)
	{
		ar[i] = (int*)malloc(sizeof(int) * max_col);
		memset(ar[i], 0, sizeof(int) * max_col);
	}

	temp_mat = mat;
	for (int i = 0; i < this->length; i++)
	{
		ar[temp_mat->row][temp_mat->col] = temp_mat->val;

		temp_mat = temp_mat->next_mat;
	}

	cout << "/************/" << endl;
	for (int row = 0; row < max_row; row++)
	{
		cout << ar[row][0] << ar[row][1] << ar[row][2] << endl;
	}
	cout << "/************/" << endl;
}