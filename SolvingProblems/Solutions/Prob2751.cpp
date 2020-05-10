#include <iostream>
#include <string.h>
#include <stdlib.h>

#ifdef TEST_MODE
#include "Prob2751.h"
#endif

using namespace std;

int* sort_ar;

#define SWAP(a, b) \
do{\
int temp = a;\
a = b;\
b = temp;\
}while(0);

static void CustomBubbleSort(int* ar, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (ar[i] > ar[j])
			{
				SWAP(ar[i], ar[j]);
			}
		}
	}
}

static void CustomSelectionSort(int* ar, int n)
{
	int min_index = 0;
	for (int i = 0; i < n; i++)
	{
		min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (ar[j] < ar[min_index])
			{
				min_index = j;
			}
		}

		SWAP(ar[i], ar[min_index]);
	}
}

static void CustomInsertionSort(int* ar, int n)
{
	int target = 0;
	int i, j;
	for (i = 1; i < n; i++)
	{
		target = ar[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (ar[j] > target)
			{
				ar[j + 1] = ar[j];
			}
			else
			{
				break;
			}
		}

		ar[j + 1] = target;
	}
}

static void MergeTwoArea(int* ar, int left, int mid, int right)
{
	int front_index = left, rear_index = mid + 1, i;

	int start_index = left;

	while (front_index <= mid && rear_index <= right)
	{
		if (ar[front_index] <= ar[rear_index])
		{
			sort_ar[start_index] = ar[front_index++];
		}
		else
		{
			sort_ar[start_index] = ar[rear_index++];
		}
		start_index++;
	}

	if (front_index > mid)
	{
		for (i = rear_index; i <= right; i++, start_index++)
		{
			sort_ar[start_index] = ar[i];
		}
	}
	else
	{
		for (i = front_index; i <= mid; i++, start_index++)
		{
			sort_ar[start_index] = ar[i];
		}
	}
	for (i = left; i <= right; i++)
	{
		ar[i] = sort_ar[i];
	}
}

static void CustomMergeSort(int* ar, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;

		CustomMergeSort(ar, left, mid);
		CustomMergeSort(ar, mid + 1, right);

		MergeTwoArea(ar, left, mid, right);
	}
}


static inline int Partition(int* ar, int left, int right)
{
	int pivot_index = left;
	int pivot = ar[pivot_index];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{

		while (pivot > ar[low] && low <= right)
		{
			low++;
		}

		while (pivot < ar[high] && high >= (left + 1))
		{
			high--;
		}
		if (low <= high)
		{
			SWAP(ar[low], ar[high]);
		}
	}
	SWAP(ar[pivot_index], ar[high]);
	return high;
}

static inline void CustomQuickSort(int* ar, int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(ar, left, right);
		CustomQuickSort(ar, left, pivot - 1);
		CustomQuickSort(ar, pivot + 1, right);
	}
}



#ifdef TEST_MODE
int BK_Prob_2751(void)
#else
int main(void)
#endif
{
	int n = 0;
	int* ar = NULL;

#ifdef TEST_MODE
	n = 5;
	int in_ar[] = { 5, 2, 3, 4, 1 };
	ar = new int[n];

	for (int i = 0; i < n; i++)
	{
		ar[i] = in_ar[i];
	}
#else
	cin >> n;
	ar = new int[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ar[i]);
	}
#endif

	//CustomBubbleSort(ar, n);

	//CustomSelectionSort(ar, n);

	//CustomInsertionSort(ar, n);

	sort_ar = new int[n];
	CustomMergeSort(ar, 0, n - 1);

	//CustomQuickSort(ar, 0, n - 1);


	for (int i = 0; i < n; i++)
	{
		printf("%d\n", ar[i]);
	}

	delete[] ar;
	delete[] sort_ar;
	return 0;
}