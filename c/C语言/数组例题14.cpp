#include<stdio.h>
#include<string.h>
int main(){
	printf("������һ���ַ���");
	static char ch[100];
	gets(ch);
	int i,j;
	j=strlen(ch)-1;
	for(i=0;ch[i]==ch[j]&&i<j;i++,j--){
	}
	if(i<j){
		printf("���ǻ��ġ�");
	}
	else{
		printf("�ǻ��ġ�");
	}
	return 0;
}
