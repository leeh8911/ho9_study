#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#ifdef TEST_MODE
#include "Prob11651.h"
#include <time.h>
#endif

typedef struct tPOINT
{
	int x, y;
}POINT;

using namespace std;

int cmp_for_qsort(const void* first, const void* last)
{
	POINT p1, p2;
	p1 = *(POINT*)first;
	p2 = *(POINT*)last;
	if (p1.y == p2.y)
	{
		return p1.x > p2.x;
	}
	else
	{
		return p1.y > p2.y;
	}

}

#ifdef TEST_MODE
int BK_Prob_11651(void)
#else
int main(void)
#endif
{
	int n = 0;
	POINT* v2 = NULL;

#ifdef TEST_MODE
	n = 5;
	int arr_in[][2] = { {0, 4}, {1, 2}, {1, -1}, {2, 2}, {3, 3} };
	v2 = new POINT[n];
	for (int i = 0; i < n; i++)
	{
		POINT p;
		p.x = arr_in[i][0];
		p.y = arr_in[i][1];

		v2[i] = p;
	}
#else
	scanf("%d", &n);
	v2 = new POINT[n];
	POINT p;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &v2[i].x, &v2[i].y);
	}
#endif
	qsort(v2, n, sizeof(POINT), cmp_for_qsort);

	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", v2[i].x, v2[i].y);
	}
	return 0;
}