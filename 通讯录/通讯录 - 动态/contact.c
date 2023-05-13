#define _CRT_SECURE_NO_WARNINGS 1
//ʵ��contact�ĺ���
#include"contact.h"
void Init_contact(struct Contact* pc)
{
	assert(pc);
	pc->data = (struct PeoInfo*)malloc(MALLOCINIT_SZ * sizeof(struct PeoInfo));
	if (pc->data == 0)
	{
		perror("�ռ��������");
		return 1;
	}
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
	pc->MemSz =MALLOCINIT_SZ ;
}
static struct Contact* ReallocCheck(struct Contact* pc)
{
	if (pc->MemSz > pc->sz)
	{
		return pc->data;
	}
	else
	{

			struct PeoInfo *ptemp= realloc(pc->data, (pc->MemSz + REALLOCADD_SZ) * sizeof(struct PeoInfo));
		if (NULL == ptemp)
		{
			perror("����ʧ�ܣ�");
			return NULL;
		}
		pc->data = ptemp;
		return ptemp;
	}
}
void AddConact(struct Contact* pc)
{
	struct Contact* ptemp = ReallocCheck(pc);
	if (NULL == ptemp)
	{
		perror("����ʧ��");
		return;
	}
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������Ա�:>"); 
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰����:>");
	scanf("%s", pc->data[pc->sz].phone);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].address);
	printf("����������:>");
	scanf("%d", &pc->data[pc->sz].age);
	pc->sz++;
 	printf("��ӳɹ���\n");
}
void ShowContact(struct Contact*pc)
{
	printf("%-4s %-10s %-12s %-5s %-40s %-3s",
		"���","����", "�ֻ���", "�Ա�", "��ַ", "����");
	int i = 0;
	printf("\n");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-4d %-10s %-12s %-5s %-40s %-3d\n",i,
			pc->data[i].name, pc->data[i].phone,pc->data[i].sex, pc->data[i].address, pc->data[i].age);
	}
}
static size_t SearchByName(const struct Contact* pc, char* name)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//�Ҳ�������-1
}
void DelContact(struct Contact* pc)
{
	printf("����������Ҫɾ�����ݵ�����(���������Զ�ɾ������ǰ����Ǹ���:>");
	char input[NAME_MAX]={0};
	scanf("%s", &input);
	int i = SearchByName(pc, input);
	if (i == -1)
	{
		printf("�޸�ʧ�ܣ�û���������\n");
	}
	else
	{
		for (; i < pc->sz; i++)
		{
			memmove(&pc->data[i], &pc->data[i + 1], sizeof(pc->data[i]));
		}
		pc->sz--;
		memset(&pc->data[pc->sz], 0, sizeof(pc->data[pc->sz]));
	}
}

void SearchContact(const struct Contact* pc)
{
	printf("����������Ҫ�������ݵ�����:>");
	char input[NAME_MAX] = { 0 };
	scanf("%s", &input);
	int i = SearchByName(pc, input);
	if (i = -1)
	{
		printf("��Ǹ��û�������������\n");
		return;
	}
	printf("%-10s %-12s %-5s %-40s %-3s\n",
		"����", "�ֻ���", "�Ա�", "��ַ", "����");
	printf("%-10s %-12s %-5s %-40s %-3d\n",
		pc->data[i].name, pc->data[i].phone, pc->data[i].sex, pc->data[i].address, pc->data[i].age);
}

void ModifyContact(struct Contact* pc)
{
	printf("����������Ҫ�޸ĵ������е�����:>");
	char input[NAME_MAX] = { 0 };
	scanf("%s", &input);
	int i=SearchByName(pc, input);//����±�
	if (i = -1)
	{
		printf("�޸�ʧ�ܣ��޴�����\n");
		return;
	}
	printf("����������:>");
	scanf("%s", pc->data[i].name);
	printf("�������Ա�:>");
	scanf("%s", pc->data[i].sex);
	printf("������绰����:>");
	scanf("%s", pc->data[i].phone);
	printf("�������ַ:>");
	scanf("%s", pc->data[i].address);
	printf("����������:>");
	scanf("%d", &pc->data[i].age);
	printf("�޸ĳɹ���\n");
}
static int NameCompare(void*e1,void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}
void SortConact(struct Contact* pc)
{
	qsort(pc, pc->sz, sizeof(pc->data[0]), NameCompare);
}