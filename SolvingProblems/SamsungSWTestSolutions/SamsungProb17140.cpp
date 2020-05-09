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

	int GetMaxRow();
	int GetMaxCol();

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
	cin >> i >> j >> k;
#endif
	tSPARSE_MATRIX_HANDLER mat(3, 3, ar_in);

	mat.Print();

	mat.Transpose();

	mat.Print();

	mat.Calculate();

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
	int max_row = this->GetMaxRow();
	int max_col = this->GetMaxCol();

	int** values = new int*[max_row];
	int** counts = new int*[max_row];
	for (int i = 0; i < max_row; i++)
	{
		values[i] = new int[max_col];
		counts[i] = new int[max_col];

		memset(values[i], 0, sizeof(int) * max_col);
		memset(counts[i], 0, sizeof(int) * max_col);
	}


	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < max_col; j++)
		{
			if (values[temp_mat->row][j] == 0)
			{
				values[temp_mat->row][j] = temp_mat->val;
				counts[temp_mat->row][j] = 1;
				break;
			}
			else if (values[temp_mat->row][j] == temp_mat->val)
			{
				counts[temp_mat->row][j] += 1;
				break;
			}
		}

		temp_mat = temp_mat->next_mat;
	}

	for (int row = 0; row < max_row; row++)
	{
		for (int col = 0; col < max_col; col++)
		{
		}
	}

#ifdef TEST_MODE
	cout << "/******ValueMatStart*******/" << endl;
	
	for (int row = 0; row < max_row; row++)
	{
		cout << "[";
		for (int col = 0; col < max_col; col++)
		{
			cout << values[row][col] << " ";
		}
		cout << "]" << endl;
	}
	cout << "/******ValueMatEnd*******/" << endl;
	cout << "/******CountMatStart*******/" << endl;
	for (int row = 0; row < max_row; row++)
	{
		cout << "[";
		for (int col = 0; col < max_col; col++)
		{
			cout << counts[row][col] << " ";
		}
		cout << "]" << endl;
	}
	cout << "/******CountMatEnd*******/" << endl;
#endif

}
	void tSPARSE_MATRIX_HANDLER::Print()
	{
		SPARSE_MATRIX* temp_mat = mat;
	int max_row = this->GetMaxRow(), max_col = this->GetMaxCol();


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


	int tSPARSE_MATRIX_HANDLER::GetMaxRow()
	{
		SPARSE_MATRIX* temp_mat = mat;
		int max_row = 0;

		for (int i = 0; i < this->length; i++)
		{
			if (max_row < temp_mat->row)
				max_row = temp_mat->row;

			temp_mat = temp_mat->next_mat;
		}

		return max_row + 1;
	}
	int tSPARSE_MATRIX_HANDLER::GetMaxCol()
	{
		SPARSE_MATRIX* temp_mat = mat;
		int max_col = 0;

		for (int i = 0; i < this->length; i++)
		{
			if (max_col < temp_mat->col)
				max_col = temp_mat->col;

			temp_mat = temp_mat->next_mat;
		}

		return max_col + 1;
	}
