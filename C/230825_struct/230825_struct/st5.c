#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct person
{
	char name[20];
	char phoneNum[20];
	int age;
};
							// �Է� �غ���
int main()
{
	struct person arr[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		printf("�̸� �Է�:"), scanf("%s", arr[i].name);
		printf("��ȣ �Է�:"), scanf("%s", arr[i].phoneNum); // ���ڿ� ������ �Էµ��� ����
		printf("���� �Է�:"), scanf("%d", &arr[i].age);
	}
		
	for (int i = 0; i < 3; i++) {
		printf("�̸�:%s\n", arr[i].name);
		printf("��ȣ:%s\n", arr[i].phoneNum);
		printf("����:%d\n", arr[i].age);
		printf("=======================================\n");

	}
		

		
}