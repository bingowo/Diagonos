#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int number(char *s)
{
	int len=strlen(s);
	int i,sum=0,flag=0;
	for(i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='0'){
			sum=sum*10+s[i]-48;
			flag=1;
		}
	}
	if(flag==0) return -1;
	else return sum;
}
int strnumcmp(const void*a,const void*b)
{
	char *aa=(char*)a;
	char *bb=(char*)b;
	int x=number(aa),y=number(bb);
	if(x-y){
		return x-y;
	}
	else{
		return strcmp(aa,bb);
	}
}
int main()
{
	char s[100][30];int i=0;
	while(scanf("%s",&s[i])!=EOF) i++;
	qsort(s,i,sizeof(s[0]),strnumcmp);
	for(int j=0;j<i-1;j++){
		printf("%s ",s[j]);
	}
	printf("%s\n",s[i-1]);
}
	