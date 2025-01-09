#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//ѧ����Ϣ
typedef struct _Student
{
	int stuNum;
	char name[20];
	int otherdata; //���������ݣ�(δʹ��) 
}Student;

//�����Ϣ
typedef struct _Node
{
	Student student;
	struct _Node* next;
}Node;

void welcome(); //������ 

void inputStudent(Node* head);

void printStudent(Node* head);

void countStudyRoomSeats(Node* head);

void findStudent(Node* head);

void saveStudent(Node* head);

void loadStudent(Node* head);

void modifyStudent(Node* head);

void deleteStudent(Node* head);

void freeSeats(); 
