#define _CRT_SECURE_NO_WARNINGS                       // C
#include <stdio.h>
							// 구조체
int main()
{
	// 학생 관리 프로그램 (100명) 
	char name1[20];
	char tel1[20];
	int age1;
	// 일반 변수로 관리하기에는 불편 (300개 필요)

	// 일반 변수가 힘드니깐 배열
	char name[100][20];
	char tel[100][20];
	int age[100];
	// 배열을 사용하면 일반 변수를 사용하는것보다
	// 개수는 많이 줄지만 프로그래밍을 하기에는 불편하다

	// 1명의 학생 정보를 가지는 틀(구조,모형)
	struct student { // 객체지향에서는 class 객체, 구조체의 정의
		char name[20];
		char tel[20];
		int age;
	};
	// 1명의 학생정보를 사용하는 프로그램
	struct student st; // 구조체 변수명 st

	// 1000명의 학생정보를 사용하는 프로그램
	struct student arr[1000]; 

	


}