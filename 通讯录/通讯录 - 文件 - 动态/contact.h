#pragma once
//contactͷ�ļ�
// 
// 
//ģ��ͨѶ¼�Ĺ���
// �洢��Ϣ�����֣��Ա����䣬�绰����ַ
// ���ܣ���ɾ��ģ����ң���ʾ������
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#define DATA_MAX 100//Contact��PeoInfo�ṹ�������Ա��С
#define NAME_MAX 20
#define SEX_MAX 5
#define PHONE_MAX 12
#define ADDRESS_MAX 40
#define MALLOCINIT_SZ 3
#define REALLOCADD_SZ 2
//��ʾһ���˵���Ϣ
struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	char phone[PHONE_MAX];
	char address[ADDRESS_MAX];
	int age;
};
//�ܵ��ڴ�洢��ʽ
struct Contact
{
	struct PeoInfo *data;
	int sz;
	int MemSz;
}contact;
void Init_contact(struct Contact* pc);
void AddConact(struct Contact* pc);
void ShowContact(struct Contact* pc);
void DelContact(struct Contact* pc);
void SearchContact(struct Contact* pc);
void ModifyContact(struct Contact* pc);
//�����ļ�
void SortContact(struct Contact* pc);

//
// 
// ����Ŀ��Ϊ��Ϥ�ṹ�弰һЩ������ʹ�ö�������Ϊ�˽������ʱ��Ͷ��ѧϰ�ܶ๦�ܲ�δ��ӣ��ǰ��Ʒ�еİ��Ʒ
// �����ṩһЩ�պ�ĸĽ����������пգ�����δ����ʵ��
// 
//
//����ĸĽ�������
//Ϊ�û��ṩ�����ַ�ʽ�����򣬼�¼�û�������ʽ
//�����������ܷ���֮�����ݵ�����ʽ��Ȼ���ı䣨�޸Ĺ��ܺ��Զ�����һ�Σ����߽��޸����ݲ��뵽��Ӧλ��
//�����ϵ�ǰ���ϣ������ڲ��ҵ�ʱ�����ʹ�ö��ֲ���
//		���Դ���һ��ȫ�ֱ����������ǣ�����Ȼ���ڱȽ������н��в���
//		���ϵ�ʱ�򴴽�������main�����У���ѡ������Ͳ���ʱ�ıȽ�����