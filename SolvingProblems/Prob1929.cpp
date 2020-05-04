#include <iostream>
#include <string>

#define MAX_NUMBER (1000000U)
using namespace std;

inline void generate_cand_nums(int* cand_nums)
{
	int* temp = cand_nums;
	for (int i = 1; i <= MAX_NUMBER; i++)
	{
		*temp = i;
		temp++;
	}
}

inline void remove_cand_nums_multiple_of_num(int num, int* cand_nums)
{
	int* temp = cand_nums + (num - 1);
	int count = num;
	while (count < MAX_NUMBER)
	{
		*temp = 0;

		temp += num;
		count += num;

	}
}
#ifdef TEST_MODE
int BK_Prob_1929(void)
#else
int main(void)
#endif
{
	int start_num, end_num, count = 0;
	int *cand_nums = new int[MAX_NUMBER];
	string results;

	cin >> start_num >> end_num;

	generate_cand_nums(cand_nums);

	if (end_num > MAX_NUMBER)
	{
		return 1;
	}
	for (int i = 1; i < MAX_NUMBER; i++)
	{
		int num = cand_nums[i];

		if (num != 0)
		{
			if (start_num <= num && num <= end_num)
			{
				results += to_string(num);
				results.push_back('\n');
			}
			remove_cand_nums_multiple_of_num(num, cand_nums);
		}
	}

	cout << results << endl;

	delete[] cand_nums;

	return 0;
}

