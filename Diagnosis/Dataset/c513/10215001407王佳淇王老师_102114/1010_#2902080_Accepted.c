#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Tob10(int n)
{
	for(int i=9;i>=0;i--){
		putchar(((n>>i)&0x1)?'1':'0');
	}
}
void Tob4(int n)
{
	for(int i=3;i>=0;i--){
		putchar(((n>>i)&0x1)?'1':'0');
	}
}
void Tob7(int n)
{
	for(int i=6;i>=0;i--){
		putchar(((n>>i)&0x1)?'1':'0');
	}
}
int main(){
	char s[10000];
	int t[1000];
	int k=0;
	scanf("%s",s);
	printf("0001");
	int len=strlen(s);
	Tob10(len);
	int re=len%3;
	int intlen=len-re;
    for(int i=0;i<intlen;i+=3){
			int z=0;
			for(int j=i;j<i+3;j++)
			{
			z=z*10+s[j]-'0';
			}
			t[k]=z;
			k++; 
		}
	for(int m=0;m<k;m++)	Tob10(t[m]);
	if(re==1)	Tob4(atoi(&s[len-1]));
	if(re==2)   Tob7(atoi(&s[len-2]));
	return 0;
}