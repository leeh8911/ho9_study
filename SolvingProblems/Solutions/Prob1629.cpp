#include <iostream>
#include <string>

using namespace std;

uint64_t calc_power_and_mod(uint64_t a, uint64_t x, uint64_t D);

#ifdef TEST_MODE
int BK_Prob_1629(void)
#else
int main(void)
#endif
{
	uint64_t A, B, C;

#ifdef TEST_MODE
	A = 684564651;
	B = 564454531;
	C = 56416513;
#else
	cin >> A >> B >> C;
#endif

	uint64_t rest = calc_power_and_mod(A, B, C);

	cout << rest << endl;

	return 0;

}

uint64_t calc_power_and_mod(uint64_t a, uint64_t x, uint64_t D)
{
	uint64_t res;

	a = a % D;

	if (x == 0)
		res = 1;
	else if (x == 1)
		res = a;
	else if (x % 2 == 0)
	{
		uint64_t temp = calc_power_and_mod(a, x / 2, D);
		res = temp * temp;
	}
	else
	{
		res = calc_power_and_mod(a, x - 1, D) * a;
	}

	return res % D;
}