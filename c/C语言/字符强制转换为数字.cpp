#include<stdio.h>

int main(){
	int i,s=0;
	char ch[11];
	
	printf("������10λ���µ����֣�");
	gets(ch);
	for(i=0;i<10&&ch[i]!='\0';i++){
		int(ch[i]=ch[i]-'0');
	}
	
	for(i=0;i<10&&ch[i]!='\0';i++){
		s+=ch[i];
	}
	printf("�����ָ�λ��֮��Ϊ��%d",s);
	
	return 0;
}
