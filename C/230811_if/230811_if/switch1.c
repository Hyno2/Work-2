#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
									// switch : if else if ��� ���� ������ ������ �ִ� ���´� ���Ұ����ϴ�
									// switch()�ȿ� ���� case�� ���� ������ ���¸� ������ �־�� �Ѵ�
									//���߿� �ݺ��� ������ switch ���� break ����ҋ� �����ؾ��Ѵ�
int main()
{
	int num;
	printf("1�̻� 5������ ���� �Է�:");
	scanf("%d", &num);
	switch (num) {
	case 1:
			printf("1�� ONE\n");
			break;
	case 2:
			printf("2�� TWO\n");
			break;
	case 3:
			printf("3�� THREE\n");
			break; 
	case 4:
			printf("4�� FOUR\n");
			break;
	case 5:
			printf("5�� FIVE\n");
			break;
	default:
			printf("default\n");
	}












}