#include<stdio.h>
#include<string.h>
#include<stdlib.h>
double rate[1000]={0};
int cmp(const void*a,const void*b)
{
	char c=*(char*)a;
	char d=*(char*)b;
	//printf("c,d:%c %c\n",c,d); 
	int flg1=1,flg2=1;//flg=0为小写 
	if(c>='a'&&c<='z')c=c-32,flg1=0;//小写转大写
	if(d>='a'&&d<='z')d=d-32,flg2=0;
//	printf("flag1 flag2:%d %d\n",flg1,flg2);
	if(rate[c]!=rate[d]){
		if(rate[c]>rate[d])return -1;
		else return 1;
	}
	if(flg1==flg2){//c d同大写或同小 
		return(c-d);
	}
	//一大写一小写 (之前都被化成了大写） 
		c=c+32;
		d=d+32;
		if(c==d){
			return -1;//a排在A前 
		}
		else{
			return(c-d);
		}
}
char*check(char*s)
{
	for(int i=0;i<strlen(s);i++){
		if((s[i]+32)==s[i+1]){
			char c;
			c=s[i];
			s[i]=s[i=1];
			s[i+1]=c;
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		rate[1000]={0};
		char s[1000]={0};
		char c='A';//按大写存频率 
		float temp=0;
		for(int j=0;j<26;j++)
		{
			scanf("%f",&temp);
			rate[c++]=temp;
			//printf("rate:%d %f\n",c-1,rate[c-1]);
		}
		scanf("%s",s);
		qsort(s,strlen(s),sizeof(s[0]),cmp);
		check(s);
		printf("case #%d:\n",i);
		printf("%s\n",s);
	}
 } 