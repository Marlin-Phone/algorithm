/*������ʵ��ѧ���ɼ���Ϣ�Ĺ���*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct STU{
	int ID;
	char name[20];
	int score;
	struct STU *next;
}STU; 

STU *Create_Stu_Doc();//�½����� 
STU *InsertDoc(STU *head,STU *stud);//����(������)
STU *DeleteDoc(STU *head,int ID);//ɾ��
void Print_Stu_Doc(STU *head);//����

int main(){
	STU *head,*p;
	int choice,ID,score;
	char name[20];
	int size=sizeof(STU);
	
	do{
		system("cls"); //����DOS����cls����
	    printf("====ͬѧ¼������Ϣϵͳ====\n");
	    printf("\t1. ����ͬѧ��Ϣ\n");
	    printf("\t2. ���ͬѧ��Ϣ\n");
	    printf("\t3. ɾ��ͬѧ��Ϣ\n");
	    printf("\t4. �г�ͬѧ��Ϣ\n");
	    printf("\tX. XXXX����ͬѧ\n");
	    printf("\t0. �˳�ϵͳ\n");
	    printf("========================\n");
	    printf("���������ѡ��0-4����");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				head=Create_Stu_Doc();
				break;
			case 2:
				printf("������ ѧ�ţ����� �� �ɼ���\n");
				scanf("%d%s%d",&ID,name,&score);
				p=(STU*)malloc(size);
				p->score =score;
				head=InsertDoc(head,p);
				break;
			case 3:
				printf("������ ѧ�ţ�\n");
				scanf("%d",&ID);
				head=DeleteDoc(head,ID);
				break;
			case 4:
				Print_Stu_Doc(head);
				break;
			case 0:
				printf("\n��ӭ�´�ʹ�ñ�ϵͳ���ټ���");
				exit(0);
		}
	}while(1);
	
	return 0;
} 

//�½�����
STU *Create_Stu_Doc(){
	STU *head,*p;
	int ID,score;
	char name[20];
	int size=sizeof(STU);
	
	head=NULL;
	printf("������ ѧ�ţ����� �� �ɼ���\n������0���˳���\n");
	scanf("%d",&ID);
	if(ID!=0){
		scanf("%s%d",name,&score);
		while(ID!=0){
			p=(STU*)malloc(size);
			p->ID =ID;
			strcpy(p->name ,name);
			p->score =score;
			head=InsertDoc(head,p);//���ò��뺯��
			scanf("%d%s%d",&ID,name,&score); 
		}	
	} 
	return head;
}

//�������
STU *InsertDoc(STU *head,STU *stud){
	STU *ptr,*ptr1,*ptr2;
	
	ptr2=head;
	ptr=stud;//*ptrָ���������µ�ѧ����¼���
	//ԭ����Ϊ��ʱ�Ĳ���
	if(head==NULL){
		head=ptr;
		head->next=NULL;
	} 
	else{
		while((ptr->ID >ptr2->ID )&&(ptr->next !=NULL)){
			ptr1=ptr2;
			ptr2=ptr2->next ;
		}
		if(ptr->ID <=ptr2->ID ){//��ptr1��ptr2֮������½�� 
			if(head==ptr2) head=ptr;
			else ptr1->next =ptr;
			ptr->next =ptr2;
		}
		else{//�²������Ϊβ��� 
			ptr2->next =ptr;
			ptr->next =NULL;
		} 
	}
	return head; 
} 
//ɾ������ 
STU *DeleteDoc(STU *head,int ID){
	STU *ptr1,*ptr2;
	
	//Ҫ��ɾ�����Ϊ��ͷ���
	while(head!=NULL&&head->ID==ID){
		ptr2=head;
		head=head->next;
		free(ptr2);
	} 
	if(head==NULL)
		return NULL;
	//Ҫ��ɾ���Ľ��Ϊ�Ǳ�ͷ���
	ptr1=head;
	ptr2=head->next;
	while(ptr2!=NULL){
		if(ptr2->ID ==ID){
			ptr1->next =ptr2->next ;
			free(ptr2);
		}
		else
			ptr1=ptr2;
			ptr2=ptr1->next ;
	}
	return head; 
} 

//��������
void Print_Stu_Doc(STU *head){
	STU *ptr;
	if(head==NULL){
		printf("\n�޼�¼\n");
		return;
	}
	printf("\nѧ���ǵ���ϢΪ��\n");
	printf("ѧ��\t ����\t �ɼ�\n");
	for(ptr=head;ptr!=NULL;ptr=ptr->next ){
		printf("%d\t%s\t%d\n",ptr->ID ,ptr->name ,ptr->score );
	}
}


















