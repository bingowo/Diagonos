#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp (const void *a,const void *b)
{
	char*s1 = *(char (*)[101])a,*s2=*(char(*)[101])b;
	//符号判断
	int sign1=1,sign2=1;
	if(s1[0]=='-')
		sign1=-1,s1++;
	else if(s1[0]=='+')
		s1++;
	if(s2[0]=='-')
		sign2=-1,s2++;
	else if(s2[0]=='+')
		s2++;
	//异号
	if(sign1 !=sign2)
		return sign1 > sign2;
	//同号
	char*p1 = strchr(s1,'.'),*p2=strchr(s2,'.');
	//整数部分长度
	int len1,len2;
	if(p1==NULL)	len1=strlen(s1);
	else			len1=p1-s1;
	if(p2==NULL)	len2=strlen(s2);
	else 			len2=p2-s2;
	if(len1!=len2)
		return sign1*(len1-len2);
	else
		return sign1*strcmp(s1,s2);
}
int main()
{
	int n;
	char s[100][101];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",*(s+i));
	qsort(s,n,sizeof(s[0]),cmp);
	
	for(int i=0;i<n;i++)
		printf("%s\n",*(s+i));
	return 0;
}