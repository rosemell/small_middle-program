#define _CRT_SECURE_NO_WARNINGS 1
//��contact�Ӻ������ϲ�����
#include"contact.h"
void menu()
{
	printf("********************************\n");
	printf("*****    1. add     2. del   ***\n");
	printf("*****    3. search  4. modify***\n");
	printf("*****    5. show    6. sort  ***\n");
	printf("*****    0. exit             ***\n");
	printf("********************************\n");
}
int main()
 {
	enum menu
	{
		EXIT,
		ADD,
		DEL,
		SEARCH,
		MODIFY,
		SHOW,
		SORT,
	};
	//��ʼ��
	Init_contact(&contact);
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddConact(&contact);
			break;
		case DEL:
			DelContact(&contact);
			break;
		case SEARCH:
			SearchContact(&contact);
			break;
		case MODIFY:
			ModifyContact(&contact);
			break;
		case SHOW:
			ShowContact(&contact);
			break;
		case SORT:
			SortConact(&contact);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}