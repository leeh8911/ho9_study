#include <iostream>

#ifdef TEST_MODE
#include "SamsungProb17140.h"
#endif

using namespace std;

enum CALCULATE_TYPE
{
	CALCULATE_TYPE_R = 0U,
	CALCULATE_TYPE_C,
};
struct ARRAY_SIZE
{
	int row;
	int col;
};
struct CALCULATOR_OUT
{
	int value;
	int count;
};

void get_column_to_row(int** ar_in, struct ARRAY_SIZE ar_in_size, int target_column, int* vec_out)
{
	for (int i = 0; i < ar_in_size.col; i++)
	{
		vec_out[i] = ar_in[i][target_column];
	}
}

void count_value(int* vec_in, int vec_size, struct CALCULATOR_OUT* out, int *num_of_out)
{
	const int max_out_size = vec_size * 2;
	*num_of_out = 0;

	for (int i = 0; i < vec_size; i++)
	{
		int value = vec_in[i];
		if (value == 0)
		{
			continue;
		}
		for (int j = 0; j < max_out_size; j++)
		{
			CALCULATOR_OUT* temp = &out[j];
			if (temp->value == value)
			{
				// count up!
				temp->count++;
				break;
			}
			else if (temp->value == 0)
			{
				// fill value
				temp->value = value;
				temp->count = 1;
				(*num_of_out)++;
				break;
			}
		}
	}

	//sorting
	for (int i = 0; i < *num_of_out; i++)
	{

	}
}

void calculate(int** ar_in, struct ARRAY_SIZE ar_in_size, int** ar_out, struct ARRAY_SIZE *ar_out_size)
{
	enum CALCULATE_TYPE type;
	int* row_vec = NULL;

	int vec_size = 0;
	int iter_num = 0;


	if (ar_in_size.row >= ar_in_size.col)
	{
		type = CALCULATE_TYPE_R;
	}
	else
	{
		type = CALCULATE_TYPE_C;
	}


	switch (type)
	{
	case(CALCULATE_TYPE_C):
		vec_size = ar_in_size.col;
		row_vec = (int*)malloc(sizeof(int) * ar_in_size.col);
		iter_num = ar_in_size.row;
		break;
	case(CALCULATE_TYPE_R):
		vec_size = ar_in_size.row;
		row_vec = (int*)malloc(sizeof(int) * ar_in_size.row);
		iter_num = ar_in_size.col;
		break;
	default:
		break;
	}

	int count = 0;
	while (count<iter_num)
	{
		switch (type)
		{
		case(CALCULATE_TYPE_C):
			get_column_to_row(ar_in, ar_in_size, count, row_vec);
			break;
		case(CALCULATE_TYPE_R):
			row_vec = ar_in[count];
			break;
		default:
			break;
		}

		const int max_out_size = vec_size * 2;
		int out_size = 0;
		if (max_out_size != 0)
		{
			CALCULATOR_OUT* out = (CALCULATOR_OUT*)malloc(sizeof(CALCULATOR_OUT) * max_out_size);
			memset(out, 0, sizeof(CALCULATOR_OUT) * max_out_size);
			count_value(row_vec, vec_size, out, &out_size);
		}
		count++;
	}

	free(row_vec);
}

#ifdef TEST_MODE
int Samsung_Prob_17140(void)
#else
int main(void)
#endif
{
	uint64_t n, res = 0;

#ifdef TEST_MODE
	n = 17;
#else
	cin >> n;
#endif
	return 0;
}