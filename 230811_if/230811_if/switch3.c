#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	char sel;
	printf("M 오전, A 오후, E 저녁 \n");
	printf("입력:");
	scanf("%c", &sel);

	switch (sel) {
	case 'M':								// case 'M': case 'm' 이렇게 한줄로 표기해도됌
	case 'm':
		printf("Morning \n");
		break;
	case 'A':
	case 'a':
		printf("Afternoon \n");
		break;
	case 'E':
	case 'e':
		printf("Evening \n");
		break;
	}








}