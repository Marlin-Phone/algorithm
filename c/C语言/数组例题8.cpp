#include<stdio.h>
int main(){
	printf("������һ�������ո���ַ�����");
	static char ch[100];
	scanf("%s",ch);
	int i,num,x,y,z;
	while(ch[i]!='\0'){
		if(ch[i]>='0'&&ch[i]<='9'){
			num++;
		}
		else if(ch[i]>='A'&&ch[i]<='Z'){
			x++;
		}
			else if(ch[i]>='a'&&ch[i]<='z'){
				y++;
			}
				else{
					z++;
				}
		i++;
	}
	printf("��д��ĸ����%d Сд��ĸ����%d ��������%d �����ַ�����%d",x,y,num,z);
	return 0;
}
