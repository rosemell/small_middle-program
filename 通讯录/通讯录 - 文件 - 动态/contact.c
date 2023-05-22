#define _CRT_SECURE_NO_WARNINGS 1
//实现contact的函数
#include"contact.h"
//判断什么时候该扩建data内存
static struct Contact* ReallocCheck(struct Contact* pc)
{
	if (pc->MemSz > pc->sz)
	{
		return pc->data;
	}
	else
	{
		struct PeoInfo* ptemp = realloc(pc->data, (pc->MemSz + REALLOCADD_SZ) * sizeof(struct PeoInfo));
		if (NULL == ptemp)
		{
			perror("扩容失败：");
			return NULL;
		}
		pc->MemSz += REALLOCADD_SZ;
		pc->data = ptemp;
		printf("扩容成功,当前容量：%d", pc->MemSz);
		return ptemp;
	}
}
static void LoadContact(struct Contact* pc)
{

	printf("现在开始读取上次内容\n");
	FILE* fp = NULL;
	if (NULL==(fp = fopen("contact.data", "rb")))
	{
		printf("上次未存储或文件被改动\n");
		return;
	}
	int i = 0;
	struct PeoInfo temp = { 0 };
	while(fread(&temp, sizeof(struct PeoInfo), 1, fp) != 0)
	{
		if (ReallocCheck==NULL)
		{
			printf("扩容失败：%s\n", errno);
			return;

		}
		pc->data[pc->sz] = temp;
		pc->sz++;
		i++;
	}
	fclose(fp);
	fp = NULL;
}
void Init_contact(struct Contact* pc)
{

	assert(pc);
	pc->data = (struct PeoInfo*)malloc(MALLOCINIT_SZ * sizeof(struct PeoInfo));
	if (pc->data == 0)
	{
		perror("空间申请错误：");
		return 1;
	}
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
	pc->MemSz =MALLOCINIT_SZ ;
	//将上次在文件中存储的数据读取出来
	LoadContact(pc);
}
void AddConact(struct Contact* pc)
{
	struct Contact* ptemp = ReallocCheck(pc);
	if (NULL == ptemp)
	{
		perror("扩容失败");
		return;
	}
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别:>"); 
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话号码:>");
	scanf("%s", pc->data[pc->sz].phone);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].address);
	printf("请输入年龄:>");
	scanf("%d", &pc->data[pc->sz].age);
	pc->sz++;
 	printf("添加成功！\n");
}
void ShowContact(struct Contact*pc)
{
	printf("%-4s %-10s %-12s %-5s %-40s %-3s",
		"编号","姓名", "手机号", "性别", "地址", "年龄");
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
	return -1;//找不到返回-1
}
void DelContact(struct Contact* pc)
{
	printf("请输入你需要删除内容的名字(若重名则自动删除排在前面的那个）:>");
	char input[NAME_MAX]={0};
	scanf("%s", &input);
	int i = SearchByName(pc, input);
	if (i == -1)
	{
		printf("修改失败，没有这个人名\n");
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
	printf("请输入你需要查找内容的名字:>");
	char input[NAME_MAX] = { 0 };
	scanf("%s", input);
	int i = SearchByName(pc, input);
	if (i == -1)
	{
		printf("抱歉，没有你输入的名字\n");
		return;
	}
	printf("%-10s %-12s %-5s %-40s %-3s\n",
		"姓名", "手机号", "性别", "地址", "年龄");
	printf("%-10s %-12s %-5s %-40s %-3d\n",
		pc->data[i].name, pc->data[i].phone, pc->data[i].sex, pc->data[i].address, pc->data[i].age);
}

void ModifyContact(struct Contact* pc)
{
	printf("请输入你需要修改的内容中的人名:>");
	char input[NAME_MAX] = { 0 };
	scanf("%s", &input);
	int i=SearchByName(pc, input);//获得下标
	if (i = -1)
	{
		printf("修改失败，无此人名\n");
		return;
	}
	printf("请输入名字:>");
	scanf("%s", pc->data[i].name);
	printf("请输入性别:>");
	scanf("%s", pc->data[i].sex);
	printf("请输入电话号码:>");
	scanf("%s", pc->data[i].phone);
	printf("请输入地址:>");
	scanf("%s", pc->data[i].address);
	printf("请输入年龄:>");
	scanf("%d", &pc->data[i].age);
	printf("修改成功！\n");
}
static int NameCompare(void*e1,void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}
void SortContact(struct Contact* pc)
{	
	qsort(pc->data, pc->sz, sizeof(pc->data[0]), NameCompare);
}
void SaveConact(struct Contact* pc)
{
	FILE* fp = NULL;
	if ((fp = fopen("contact.data", "wb")) == NULL)
	{

		printf("文件打开错误：%s",errno);
		return;
	}
	int i = 0;
	fwrite(pc->data, sizeof(struct PeoInfo),pc->sz, fp);
	fclose(fp);
	fp = NULL;
}