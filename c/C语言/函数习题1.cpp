#include<stdio.h>
#define PI 3.1415926

float vom(float r){
	float s;
	s=4.0/3*PI*r*r*r;
	return s;
} 

int main(){
	float r,s;
	printf("����������İ뾶r:");
	scanf("%f",&r);
	
	s=vom(r);
	
	printf("������Ϊ��%.2f",s);
	return 0;
}
