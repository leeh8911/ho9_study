#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

#ifdef TEST_MODE
#include "Prob10814.h"
#include <time.h>
#endif

using namespace std;

typedef struct tPERSON
{
	int age;
	string name;
	int number;
}PERSON;

inline bool cmp(const PERSON first, const PERSON last)
{
	if (first.age == last.age)
	{
		return first.number < last.number;
	}
	else
	{
		return first.age < last.age;
	}
}

#ifdef TEST_MODE
int BK_Prob_10814(void)
#else
int main(void)
#endif
{

	int n = 0;

#ifdef TEST_MODE1
	n = 3;
	vector <PERSON> v(n);

	v[0] = { 21, "Junkyun", 0 };
	v[1] = { 21, "Dohyun", 1 };
	v[2] = { 20, "Sunyoung", 2 };
#else
	cin >> n;
	vector <PERSON> v(n);

	for (int i = 0; i < n; i++)
	{
		PERSON p;

		cin >> p.age >> p.name;
		p.number = i;

		v[i] = p;
	}
	
#endif

	sort(v.begin(), v.end(), cmp);


	for (int i = 0; i < n; i++)
	{
		printf("%d %s\n", v[i].age, v[i].name.c_str());
	}

	return 0;
}