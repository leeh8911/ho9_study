# ho9_study

문제 풀이 : [백준 링크](https://www.acmicpc.net/)



##삼전 SW 역량 테스트 기출들

[문제집 링크](https://www.acmicpc.net/workbook/view/1152)

* 문제풀이
  * [이차원 배열과 연산](https://www.acmicpc.net/problem/17140) : 
    * 배열의 연산 방법을 R, C로 나눠서 해보려 했지만, 그렇게 하는 것 보다 transpose 함수를 활용하는 것이 더 빠르게 될 것같음!

## 1주차 스터디(2020-05-03)

- 다음 시간 -> *02. 정렬* 부터 시작합니다~
- 문제풀이
  - 최대공약수2609(수학1) O (c++ main함수의 return은 "0"이 정상임!!!)
  - 소수 구하기1929(수학1) O (동적할당 ㅇㅇ)
  - 곱셈1629(수학2) O (입/출력 숫자가 정수형 범주를 넘지 않기 위해 매 단계마다 mod연산)
  - 피보나치2747(수학2) O(재귀함수로는 못푸나?)



## 2주차 스터디(2020-05-09)

* 정렬
  * Bubble sort
  * Selection sort
  * Insertion sort
  * Heap sort
  * Merge sort
  * Quick sort
  * Radix sort
* 문제풀이
  * [수 정렬하기](https://www.acmicpc.net/problem/2750)
    * bubble, selection, insertion, merge, quick sort로 각각 풀어서 해결함
    * 완료
  * [수 정렬하기2](https://www.acmicpc.net/problem/2751)
    * 개빡치네.. 코드 리팩터링 다시 해봐야 할듯 ㅠㅜ
    * "수 정렬하기"문제에서 활용된 코드를 적용해보았지만, 메모리와 수행시간이 초과됨
    * 좌표 정렬하기2와 동일한 이슈(cin, cout -> scanf, printf)가 포함된 문제 였음
    * 거기에 추가로 merge sort할 때, 재귀함수가 제대로된 조건이 아니어서 무한 루프에 빠지고, 해당 상태에서 지속적으로 동적할당을 통해 메모리를 채워 메모리 이슈가 생겼음
    * 조건 수정(left>=right --> left > right)하고, 동정할당을 함수 내에서 하는게 아니라 메인함수에서 전역변수로 할당 해 놓고 시작하여 최대한 효율적으로 변경함!
    * 완료
  * [좌표 정렬하기2](https://www.acmicpc.net/problem/11651)
    * STL sort, qsort모두 적용해봤지만 시간 초과 뜸
    * 문제는 sort, qsort가 아니라 cin, cout이 문제임 (scanf, printf를 쓰는 습관 ㄱㄱ)
    * 완료
  * [나이순 정렬](https://www.acmicpc.net/problem/10814)
    * String과 Vector를 적절히 활용해야 함
    * 입력은 받기 어려우니(char -> string변환 필요) `std::cin`으로 받고, 속도가 빨라야 하기 때문에 출력은 `printf`로 한다.
  * [국영수](https://www.acmicpc.net/problem/10825)3
    * String 사전순으로 만들기를 고민해봐야 함
    * str1.compare(str2) < 0 --> str1이 str2보다 사전에서 먼저 나옴!(str.compare(str2) = 0이면 두 str은 서로 같음)
  * [수 정렬하기3](https://www.acmicpc.net/problem/10989)
  * [K번째 수](https://www.acmicpc.net/problem/11004)
  * [카드](https://www.acmicpc.net/problem/11652)
* 다음 시간 -> LinkedList!!