#include<stdio.h>

typedef struct 
{
	char name[20];
	int id;
	int score1;
	int score2;
	int score3;
	int sum;
}stuinfo;
int main(){
	stuinfo student[3];
	int i,maxnumber=0;
	int maxscore=0;
	for(i=0;i<3;i++){
		printf("�������%d��ѧ������Ϣ\n",i+1);
		printf("����:") ;
		scanf("%s",&student[i].name);
		printf("ѧ��:");
		scanf("%d",&student[i].id);
		printf("��һ�ųɼ�:");
		scanf("%d",&student[i].score1);
		printf("�ڶ��ųɼ�:"); 
		scanf("%d",&student[i].score2);
		printf("�����ųɼ�:");
		scanf("%d",&student[i].score3);
		student[i].sum=student[i].score1+student[i].score2+student[i].score3;
		printf("�ܷ��ǣ�%d\n",student[i].sum);
		if(student[i].sum>maxscore){
			maxscore=student[i].sum;
			maxnumber=i;
		}
	}
	printf("�ܷ���ߵ�ѧ���ǵ�%d����%s���ܷ�Ϊ%d��\n",maxnumber+1,student[maxnumber].name,maxscore);
	return 0; 
}
