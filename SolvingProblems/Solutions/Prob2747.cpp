#include <iostream>

#ifdef TEST_MODE
#include "Prob2747.h"
#endif

using namespace std;


#ifdef TEST_MODE
int BK_Prob_2747(void)
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
	uint64_t iter = 0, k_2 = 0, k_1 = 0, temp;
	while (iter < n)
	{
		if (iter == 0)
		{
			k_1 = 0;
			k_2 = 1;
		}
		else if (iter > 0)
		{
			temp = k_2;
			k_2 = k_2 + k_1;
			k_1 = temp;
		}
		else
		{
			// do nothing
		}

		iter++;
	}

	cout << k_2 << endl;

	return 0;
}