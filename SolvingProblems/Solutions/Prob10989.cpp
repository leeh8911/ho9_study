#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <memory.h>

#ifdef TEST_MODE
#include "Prob10989.h"
#include <time.h>
#endif

#define SWAP(a, b) \
do{\
UNIQUE_SET temp = a;\
a = b;\
b = temp;\
}while(0);

using namespace std;

typedef struct tUNIQUE_SET
{
	int val;
	int count;
}UNIQUE_SET;


static inline int Partition(vector <UNIQUE_SET> vec, int left, int right)
{
	int pivot_index = left;
	UNIQUE_SET pivot = vec.at(pivot_index);
	int low = left + 1;
	int high = right;

	while (low <= high)
	{

		while (pivot.val > vec.at(low).val && low <= right)
		{
			low++;
		}

		while (pivot.val < vec.at(pivot_index).val && high >= (left + 1))
		{
			high--;
		}
		if (low <= high)
		{
			SWAP(vec[low], vec[high]);
		}
	}
	SWAP(vec[pivot_index], vec[high]);
	return high;
}

static inline void CustomQuickSort(vector <UNIQUE_SET> vec, int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(vec, left, right);
		CustomQuickSort(vec, left, pivot - 1);
		CustomQuickSort(vec, pivot + 1, right);
	}
}

inline int cmp_sort_10989(UNIQUE_SET first, UNIQUE_SET last)
{
	return first.val < last.val;
}

inline void make_unique_arr(int val, vector <UNIQUE_SET> &unique_arr)
{
	UNIQUE_SET temp;
	int add_flag = 0;
	int m = unique_arr.size();
	for(int j = 0; j < m; j++)
	{
		if (unique_arr[j].val == val)
		{
			unique_arr[j].count+= 1;
			add_flag = 1;
			break;
		}
	}

	if (add_flag == 0)
	{
		temp.val = val;
		temp.count = 1;
		unique_arr.push_back(temp);
		m = unique_arr.size();
	}
	return;
}

#ifdef TEST_MODE
int BK_Prob_10989(void)
#else
int main(void)
#endif
{
	int n = 0;
	vector <UNIQUE_SET> unique_arr;
	int val;

#ifdef TEST_MODE
	n = 100;
	int arr_in[] = { 5,2,3,1,4,2,3,5,1,7, 5,2,3,1,4,2,3,5,1,7,5,2,3,1,4,2,3,5,1,7,5,2,3,1,4,2,3,5,1,7,5,2,3,1,4,2,3,5,1,7,5,2,3,1,4,2,3,5,1,7,5,2,3,1,4,2,3,5,1,7,5,2,3,1,4,2,3,5,1,7,5,2,3,1,4,2,3,5,1,7,5,2,3,1,4,2,3,5,1,7 };
	for (int i = 0; i < n; i++)
	{
		make_unique_arr(arr_in[i], unique_arr);
	}
#else
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		make_unique_arr(val, unique_arr);
	}
#endif

	CustomQuickSort(unique_arr, 0, unique_arr.size());
	int m = unique_arr.size();
	string s;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < unique_arr[i].count; j++)
		{
			char c[50] = { 0 };
			sprintf(c, "%d\n", unique_arr[i].val);
			s += c;
		}
	}

	printf("%s", s.c_str());

	unique_arr.clear();

	return 0;
}