#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	char sel;
	printf("M ����, A ����, E ���� \n");
	printf("�Է�:");
	scanf("%c", &sel);

	switch (sel) {
	case 'M':								// case 'M': case 'm' �̷��� ���ٷ� ǥ���ص���
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