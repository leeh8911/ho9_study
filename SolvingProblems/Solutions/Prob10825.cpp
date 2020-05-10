#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

#ifdef TEST_MODE
#include "Prob10825.h"
#include <time.h>
#endif

using namespace std;

struct STUDENT
{
	string name;
	int korean_score;
	int english_score;
	int math_score;
};


inline bool cmp(const STUDENT first, const STUDENT last)
{
	if (first.korean_score== last.korean_score)
	{
		if (first.english_score == last.english_score)
		{
			if (first.math_score == last.math_score)
			{
				return first.name.compare(last.name) < 0;
			}
			else
			{
				return (first.math_score > last.math_score);
			}
		}
		else
		{
			return  (first.english_score < last.english_score);
		}
	}
	else
	{
		return (first.korean_score > last.korean_score);
	}
}

#ifdef TEST_MODE
int BK_Prob_10825(void)
#else
int main(void)
#endif
{
	int n = 0;

#ifdef TEST_MODE
	n = 12;
	STUDENT p[12] = {{"Junkyu"	,50, 60, 100,  },
	{"Sangkeun",80, 60, 50 ,},
	{"Sunyoung",80, 70, 100, },
	{"Soong"	,50, 60, 90 ,},
	{"Haebin"	,50, 60, 100, },
	{"Kangsoo"	,60, 80, 100, },
	{"Donghyuk",80, 60, 100, },
	{"Sei"		,70, 70, 70 ,},
	{"Wonseob"	,70, 70, 90 ,},
	{"Sanghyun",70, 70, 80 ,},
	{"nsj"		,80, 80, 80 ,},
	{"Taewhan"	,50, 60, 90 ,}};

	vector <STUDENT> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = p[i];
	}
#else
	cin >> n;
	vector <STUDENT> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].name >> v[i].korean_score >> v[i].english_score >> v[i].math_score;
	}
	
#endif
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		printf("%s\n", v[i].name.c_str());
	}
	return 0;
}