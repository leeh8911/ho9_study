#include <iostream>
#include <cstring>

#ifdef TEST_MODE1
#include "Prob2751.h"
#include <stdlib.h>
#include <ctime>
#endif

#ifdef TEST_MODE1
void TestCaseGenerator(int* n, int* ar)
{
	for (int i = 0; i < *n; i++)
	{
		int val = rand() % 1000000;
		int flag = 0;

		do
		{
			for (int j = 0; j < i - 1; j++)
			{
				if (ar[j] == val || val == 0)
				{
					flag = 1;
					break;
				}
			}

			if (flag == 0)
			{
				ar[i] = val;
				break;
			}
			else
			{
				val = rand() % 1000000;
				flag = 0;
			}


		} while (1);
	}
}
#endif

using namespace std;

#ifdef TEST_MODE
int BK_Prob_2751(void)
#else
int main(void)
#endif
{
	int n = 0;
	int* ar = NULL;

	const int max_num = 2000001;
	const int invalid_num = -1000001;

#ifdef TEST_MODE1
	srand(time(0));
	n = rand()%max_num;

	ar = new int[n];
	TestCaseGenerator(&n, ar);
#else
	cin >> n;
	ar = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
#endif
	int* sort_ar = new int[max_num];
	memset(sort_ar, invalid_num, sizeof(int) * max_num);

	for (int i = 0; i < n; i++)
	{
		sort_ar[ar[i] - 1 + 1000001] = ar[i];
	}


	for (int i = 0; i < max_num; i++)
	{
		if (sort_ar[i] != invalid_num)
		{
			cout << sort_ar[i] << endl;
		}
	}
	delete[] ar;
	delete[] sort_ar;

	return 0;
}