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

using namespace std;

typedef struct tUNIQUE_SET
{
	int val;
	int count;
}UNIQUE_SET;

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

	sort(unique_arr.begin(), unique_arr.end(), cmp_sort_10989);

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