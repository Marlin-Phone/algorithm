#include<stdio.h>
#include<string.h>
int main(){
	printf("����������һ���ַ���");
	static char ch[100];
	int i,num=0;
	gets(ch);
	for(i=0;i<strlen(ch);i++){
		if((ch[i]>='a'&&ch[i]<='z')||(ch[i]>='A'&&ch[i]<='Z')){
			num++;
		}
	}
	printf("������ĸ����Ϊ%d",num);
	return 0;
} 
