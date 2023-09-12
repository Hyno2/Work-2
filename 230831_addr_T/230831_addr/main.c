// main.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()
#include <string.h>	// strcpy()
#include <windows.h>// win32 api ��� (������ ȯ�濡���� ��� ����)
#include <conio.h>
											//	����� ���� ���̰� ������ҋ� ����� â �������̿��ض�
											//	ȭ�� ������, ��� �߰��� ȥ���غ��� ���� �� ������ ��Ʈ�������� ������
											//	���ý�: ������ ���� ���� �Է��ؼ� ����� �Ҽ��ִ�
											//	������� ���α׷� : 
											//	NAS, github, perforce
// #define NOCURSOR			0
// #define SOLID_CURSOR		1
// #define NORMAL_CURSOR	2

#define RAND_SIZE	5	//define �� ���� �����մ� RAND_SIZE �������ҋ� �길�ٲٸ�Ǽ� ����

typedef enum {
	NOCURSOR,		// Ŀ�� ����		0
	SOLID_CURSOR,	// solid ����	1
	NORMAL_CURSOR	// �Ϲ� ����		2
} CURSOR_TYPE;		

typedef enum {
	BLACK,	// 0
	BLUE,	// 1
	GREEN,	// 2
	CYAN,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_CYAN,
	LIGHT_RED,
	LIGHT_PURPLE,
	LIGHT_YELLOW,
	LIGHT_GRAY	// 15
} FONT_COLOR;		

typedef struct _ADDR {
	int id;
	char name[20];
	char tel[20];
	char addr[30];
	char email[50];
} ADDR;		

const int id[] = { 111, 222, 333, 444, 555 };
const char* name[] = { "ȫ�浿", "����ġ", "������", "������", "�̼���" };
const char* tel[] = { "010-1234-1234", "010-1234-1111", "010-1234-2222",
	"010-1234-3333", "010-1234-4444" };
const char* addr[] = { "�뱸 ���� �ž�4��", "���� ���� �ž�4��" ,
	"���� ���� �ž�4��", 	"���� ���� �ž�4��", "�λ� ���� �ž�4��" };
const char* email[] = { "hong@naver.com", "joen@kakao.com",
	"kang@gmail.com", "yu@msn.com", "lee@daum.net" };

// �Լ� ���� ������Ÿ��	main �������°ͺ��� ������ ����
int main_menu();
void title();
void gotoxy(int x, int y);
void set_cursor_type(CURSOR_TYPE type);
void font_color(FONT_COLOR color);
void file_write_rand(ADDR ad[], char filename[], int len);
void file_write(ADDR ad, char filename[]);
void file_read(char filename[]);
void file_del_all(char filename[]);
void file_search(char filename[], char name[]);
void file_delete(char filename[], char delName[]);
void file_delete2(char filename[], char delName[]);
void file_update(char filename[], char sname[], char dname[]);

int main()
{
	char file[] = "address.bin";	//  =char*file = "address.bin" ; �������� ����Ʈ�� �ٸ��� �Ⱦ����� �迭�� ǥ��
	srand(time(NULL)); // �����Լ� ����� ���� �õ� ����
	set_cursor_type(NOCURSOR);
	font_color(LIGHT_GREEN);
	title();
	_getch();

	system("cls");	// ȭ�� û���ض�
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);
	while (1) {
		switch (main_menu()) {
		case 1:
		{
			ADDR ad[RAND_SIZE] = { 0 };
			int len = sizeof(ad) / sizeof(ADDR); // �迭 ũ�� : ����üũ�� x 10���� ũ�� / ����üũ��
			for (int i = 0; i < len; i++) {
				ad[i].id = id[rand() % 5];
				strcpy(ad[i].name, name[rand() % 5]);	// ���ڿ��� strcpy�� ����
				strcpy(ad[i].addr, addr[rand() % 5]);
				strcpy(ad[i].tel, tel[rand() % 5]);
				strcpy(ad[i].email, email[rand() % 5]);
			}
			file_write_rand(ad, file, len);	//�ּ�����, �ּ�����, ������
			printf("���� �����͸� �������Դϴ�......\n");// ȿ���ֱ�����
			Sleep(2000); // sec - ms - us - ns	�����̸� �� 1000�� 1sec
			system("pause");	// ȿ���ֱ� ���� ��� ����
			break;
		}
		case 2:
		{
			ADDR ad = { 0 };	// �Ѹ� �����ϱ� �迭�� �� �ʿ� ����
			printf("ID:");
			scanf("%d", &ad.id);
			
			printf("�̸�:");
			scanf("%s", ad.name);
			
			printf("��ȭ:");
			scanf("%s", ad.tel);
			
			printf("�ּ�:");
			getchar();
			gets(ad.addr);
			
			printf("Email:");
			scanf("%s", ad.email);	
			file_write(ad, file);	//���� ���� ����(����ü �Ϲݺ���) , �ּ��� ���� ����(�迭����)
			printf("�����Ͱ� �Է����Դϴ�......\n");
			Sleep(1000);
			system("pause");
			break;
		}
		case 3:
			file_del_all(file);
			printf("��ü �����͸� �������Դϴ�......\n");
			Sleep(1000);
			system("pause");
			break;
		case 4:
			file_read(file);
			system("pause");
			break;
		case 5:	 //	�˻�
					//	1. �˻��� �̸��� �Է¹޾ƾ��ϰ�
					//	2. �Է¹��� �̸��� ���Ͽ��� �о�� �̸��� ��
		{
			char name[20] = { 0 };
			printf("�˻��� �̸��� �Է��ϼ���:");
			scanf("%s", name);
			file_search(file, name);
			system("pause");
			break;
		}
		case 6:	// ����
					// 1. ������ �̸� �Է¹ޱ� 
					// 2. ���Ͽ��� ���� �̸��� ������ �̸��� ���Ѵ�
					// 3. �̸��� �ٸ� ����ü���� �迭�� �����Ѵ� (�Է¹��� �̸��� ������ ����X)
					// 4. ���� ���Ͽ� w���� ��� ���Ͽ� ����
		{
			printf("������ �̸� �Է�:");
			char name[20];
			scanf("%s", name);
			printf("%s �����͸� �������Դϴ�...\n", name);
			file_delete2(file, name);
			Sleep(1000);
			system("pause");
			break;
		}
		case 7:// ����
				// 1. ����(�˻�)�� �̸��� �Է��ϰ�, ������ �̸��� �Է¹޴´�
				// 2. ���Ͽ��� �о�ͼ� �˻����� ���Ѵ�.
				// 3. ���� ���ٸ� ������ �̸����� �ٲپ �� �迭�� �����Ѵ�.
				// 4. �ٽ� �����
		{
			printf("�˻��� �̸� �Է�:");
			char sname[20];
			scanf("%s", sname);
			printf("������ �̸� �Է�:");
			char dname[20];
			scanf("%s", dname);
			printf("%s �����͸� �������Դϴ�...\n", sname);
			file_update(file, sname, dname);
			Sleep(1000);
			system("pause");
			break;
		}
		case 8:
			printf("���α׷� ����!\n");
			exit(0);
		default:
			printf("�߸��� �޴� ����!!\n");
		}
		system("cls");
	}
}

int main_menu()	// return �������Ƿ� void�� ����ȴ���
{
	printf("=============================\n");
	printf("�ּҷ� ���� ���α׷� v1.0\n");
	printf("=============================\n");
	printf("1.�ּҷ� �ڵ� ����\n");
	printf("2.�ּҷ� ���� �Է�\n");
	printf("3.�ּҷ� ��ü ����\n");
	printf("4.�ּҷ� ����\n");
	printf("5.�ּҷ� �˻�\n");
	printf("6.�ּҷ� ����\n");
	printf("7.�ּҷ� ����\n");
	printf("8.����\n");
	printf("=============================\n");
	printf("�޴� ����:");
	int menu;
	scanf("%d", &menu);
	return menu;
}

void title()
{
	int x = 5;
	int y = 3;
	gotoxy(x, y + 0); printf("������������������������������");
	gotoxy(x, y + 1); printf("��							     ��");
	gotoxy(x, y + 2); printf("��							     ��");
	gotoxy(x, y + 3); printf("��							     ��");
	gotoxy(x, y + 4); printf("��							     ��");
	gotoxy(x, y + 5); printf("��							     ��");
	gotoxy(x, y + 6); printf("��							     ��");
	gotoxy(x, y + 7); printf("������������������������������");
	gotoxy(x + 12, y + 2); printf("�ּҷ� ���� ���α׷� v1.5");
	gotoxy(x + 33, y + 4); printf("���߳�¥	: 2023.09.01");
	gotoxy(x + 33, y + 5); printf("������	: ������");
	gotoxy(x, y + 12); printf("����ȭ�� �̵��� �ƹ�Ű�� ��������!!!");
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	// ������ �ֿܼ��� Ŀ�� ��ġ �̵�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void set_cursor_type(CURSOR_TYPE type)
{
	CONSOLE_CURSOR_INFO info = { 0 };
	switch (type) {
	case NOCURSOR:
		info.dwSize = 1;
		info.bVisible = FALSE;
		break;
	case SOLID_CURSOR:
		info.dwSize = 100;
		info.bVisible = TRUE;
		break;
	case NORMAL_CURSOR:
		info.dwSize = 20;
		info.bVisible = TRUE;
		break;
	}
	// Ŀ�� Ÿ���� ���� (win32 API)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void font_color(FONT_COLOR color)
{
	// ��Ʈ�� ���� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void file_write_rand(ADDR ad[], char filename[], int len)	// ����ü �迭 , �����̸��迭 , ����ü�� ũ��	
{
	FILE* fp = fopen(filename, "ab");	//ab,wb,rb , at,wt,rt �̾��,�����,�б�
	if (fp == NULL) {
		printf("���� ���� ����!\n");
		return;
	}

	for (int i = 0; i < len; i++) {
		fwrite(&ad[i], sizeof(ADDR), 1, fp);	// &�ּҰ� ad[i]�迭�Ϲݺ���, sizeofũ�� , 1���, file��
	}
	fclose(fp);
}

void file_write(ADDR ad, char filename[])
{
	FILE* fp = fopen(filename, "ab");
	if (fp == NULL) {
		printf("���� ���� ����!\n");
		return;
	}
	fwrite(&ad, sizeof(ADDR), 1, fp);
	fclose(fp);
}

void file_read(char filename[])
{
	// �����Ͱ� ������ "�����Ͱ� �������� �ʽ��ϴ�" ���� �޽����� ���!
	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("���� �б� ����!\n");
		exit(0);
	}
	ADDR ad = { 0 };	// ����� �б� ���� �� ����ü�� ������ش�
	int count = 1;
	int check = 0;
	while (fread(&ad, sizeof(ad), 1, fp) == 1) {	// ���ϰ��� 1�̸������� �ݺ��ض�
		printf("��ȣ:%d\n", count++);		
		printf("ID:%d\n", ad.id);
		printf("�̸�:%s\n", ad.name);
		printf("��ȭ:%s\n", ad.tel);
		printf("�ּ�:%s\n", ad.addr);
		printf("�̸���:%s\n", ad.email);
		printf("==========================\n");
		check = 1; // while���� �����ϸ�(�����Ͱ� ������) check�� 1�� �ǰ� �ؼ� �ݺ������ϰ�
	}
	fclose(fp);
	if (check == 0) {
		printf("�����Ͱ� �������� �ʽ��ϴ�.\n");// ���� 0�ϰ���(�����Ͱ� ���������ʱ⿡) ������ ���� ���� �ʽ��ϴ�.
	}
}

void file_del_all(char filename[])	// ������ �����ϴ� ����� �����Ƿ� �ƹ��͵� �Ⱦ��� �������ϸ� �� ������
{
	FILE* fp = fopen(filename, "wb");
	if (fp == NULL) {
		printf("���� �б� ����!\n");
		exit(0);
	}
	fclose(fp);
}

void file_search(char filename[], char name[])
{
	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("���� �˻� ����!\n");
		exit(0);
	}
	ADDR ad = { 0 };
	int count = 1;
	int check = 0;
	while (fread(&ad, sizeof(ad), 1, fp) == 1) {
		if (strcmp(ad.name, name) == 0) {	// strcmp(�� ���, �񱳴��) �����ϴٸ� == 0 
			printf("��ȣ:%d\n", count++);
			printf("ID:%d\n", ad.id);
			printf("�̸�:%s\n", ad.name);
			printf("��ȭ:%s\n", ad.tel);
			printf("�ּ�:%s\n", ad.addr);
			printf("�̸���:%s\n", ad.email);
			printf("==========================\n");
			check = 1;
		}
	}
	fclose(fp);
	if (check == 0) {
		printf("�˻��� �����Ͱ� �������� �ʽ��ϴ�.\n");
	}
}

void file_delete(char filename[], char delName[])
{
	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("���� �˻� ����!\n");
		exit(0);
	}

	ADDR ad = { 0 };
	ADDR del_arr[200] = { 0 };
	int count = 1;
	int check = 0;
	int i = 0;
	//	side effect : ���� �� ���������� ������ ������ �ҷ���, ���� �� ������ ����� ���κм��� ��Ȯ�� �ٽ� �غ���
	//	�����Ͱ� 1�� �������� ������ ���� �ʴ� ���װ� �����Ѵ� [230905_hyuno] <-- �ǹ����� �̷������� ������ ǥ���صд� �ٸ������ �����ϱ� ����
	//	while ������ �Ѱ����������� ó�����,����� ��� �׷��� ������ �Ѱ����� ���� �����̸��� ���⿡ �׷���

	while (fread(&ad, sizeof(ad), 1, fp) == 1) {	// �ѱ��ھ� �д´�, adũ�⸸ŭ, 1��� fp����
		if (strcmp(ad.name, delName) != 0) { // ������ �̸��� �ƴ϶�� 
			del_arr[i].id = ad.id;	// ���� ����
			strcpy(del_arr[i].name, ad.name);	// ���ڿ� ����
			strcpy(del_arr[i].addr, ad.addr);
			strcpy(del_arr[i].tel, ad.tel);
			strcpy(del_arr[i].email, ad.email);
			check = 1;
			i++;
		}
	}
	fclose(fp);
	printf("������ ����:%d\n", i);
	if (check == 0&& strcmp(ad.name, delName) != 0) {	// ������ ���� ��ٷӰ� �Ѵ�
		printf("������ �����Ͱ� �������� �ʽ��ϴ�.\n");
		return; // ���� ������ ������ ���ٸ� �������� ó��	void �Լ��� ����ȴ�
	}
	// �迭�� ����� ����ü ������ ���Ͽ� ����
	FILE* fp2 = fopen(filename, "wb");
	if (fp2 == NULL) {
		printf("���� ���� ����!\n");
		return;
	}
	// �����ϴ� ����ü ������ ���Ͽ� ����
	for (int i = 0; i < 200; i++) {	// ������ i�� �ؼ� �ݺ��Ǵ� Ƚ���� ǥ���ϰ� �Ҽ��� �ִ�.
		//printf("del_arr[%d]:%d\n", i, del_arr[i].id);	// ����� �ϱ������ ��� ���� printf�� ������
		// �����ϴ� ����ü ������ ���Ͽ� ���� (����� ����)
		//if (strcmp(del_arr[i].name, "") != 0) {	���ڿ����� ���ϱ�
		//if (del_arr[i].id != 0) {
		
		// �迭�� �����Ͱ� ������ �ݺ��� Ż��
		if (del_arr[i].id == 0) break;{
			fwrite(&del_arr[i], sizeof(ADDR), 1, fp2);
		}
	}
	fclose(fp2);
	
}

void file_delete2(char filename[], char delName[])
{
	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("���� �˻� ����!\n");
		exit(0);
	}

	ADDR ad = { 0 };
	ADDR del_arr[200] = { 0 };
	int count = 1;
	int check = 0;
	int i = 0;
	// �����Ͱ� 1�� �������� ������ ���� �ʴ� ���� ������   
 	while (fread(&ad, sizeof(ad), 1, fp) == 1) {
		if (strcmp(ad.name, delName) != 0) { // ������ �̸��� �ƴ϶��
			del_arr[i].id = ad.id;
			strcpy(del_arr[i].name, ad.name);
			strcpy(del_arr[i].addr, ad.addr);
			strcpy(del_arr[i].tel, ad.tel);
			strcpy(del_arr[i].email, ad.email);
			check = 1;
			i++;
		}
	}
	fclose(fp);
	printf("������ ����:%d\n", i);
	int size = i;
	if (check == 0	&&strcmp(ad.name, delName) != 0) {
		printf("������ �����Ͱ� �������� �ʽ��ϴ�.\n");
		return; // void �Լ� ����
	}

	FILE* fp2 = fopen(filename, "wb");
	if (fp2 == NULL) {
		printf("���� ���� ����!\n");
		return;
	}

	for (int i = 0; i < size; i++) {	// size �� 0�̹Ƿ� Ż��
		printf("del_arr[%d]:%d\n", i, del_arr[i].id);
		fwrite(&del_arr[i], sizeof(ADDR), 1, fp2);
	}
	fclose(fp2);

}

void file_update(char filename[], char sname[], char dname[])
{	
	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("���� �˻� ����!\n");
		exit(0);
	}

	ADDR ad = { 0 };
	ADDR del_arr[200] = { 0 };
	int count = 1;
	int check = 0;
	int i = 0;	
	while (fread(&ad, sizeof(ad), 1, fp) == 1) {
		if (strcmp(ad.name, sname) == 0) { // ������ �̸��� ���ٸ�
			strcpy(del_arr[i].name, dname);
			check = 1;
		}
		else {
			strcpy(del_arr[i].name, ad.name);
		}
		del_arr[i].id = ad.id;			
		strcpy(del_arr[i].addr, ad.addr);
		strcpy(del_arr[i].tel, ad.tel);
		strcpy(del_arr[i].email, ad.email);		
		i++;
	}
	fclose(fp);
	int size = i;
	if (check == 0) {
		printf("������ �����Ͱ� �������� �ʽ��ϴ�.\n");
		return; // void �Լ� ����
	}

	FILE* fp2 = fopen(filename, "wb");
	if (fp2 == NULL) {
		printf("���� ���� ����!\n");
		return;
	}

	for (int i = 0; i < size; i++) {
		printf("del_arr[%d]:%d\n", i, del_arr[i].id);
		fwrite(&del_arr[i], sizeof(ADDR), 1, fp2);
	}
	fclose(fp2);
}