#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char str[20];
	long long data;
}ranstr;
int num[256];
long long rtoi(char* s,long long len,long long r)
{
	long long ret=s[0];
	for(long long i=1;i<len;i++)
	{
		ret=ret*r+s[i];
	}
	return ret;
}
long long trans(ranstr* a){
	for(int i=0;i<256;i++)num[i]='-';
	char buf[20];strcpy(buf,a->str);
	long long index=1,minnum=0,al=buf[1];
	long long ret,len=strlen(buf);
	num[buf[0]]=1;
	buf[0]=1;
		while(buf[index]!=0)
		{	
			al=buf[index];
			if(num[al]!='-')
			{
				buf[index]=num[al];
			}
			if(num[al]=='-')
			{
				buf[index]=minnum;
				num[al]=minnum;
				minnum=minnum==0?2:minnum+1;
			}
			index++;
		}
		if(minnum<=1)ret=rtoi(buf,len,2);
		else ret=rtoi(buf,len,minnum);	
		return ret;
}


int cmp(const void*a,const void*b){
	ranstr *s1=(ranstr*)a,*s2=(ranstr*)b;
	if(s1->data==s2->data)
		return strcmp(s1->str,s2->str);
	else return s1->data-s2->data;
}
int main()
{
	long long t;
	scanf("%lld",&t);
	ranstr table[t];
	for(long long m=0;m<t;m++)
	{
		scanf("%s",table[m].str);
		table[m].data=trans(&table[m]);
	}
	qsort(table,t,sizeof(table[0]),cmp);
	for(long long i=0;i<t;i++){
		printf("%s\n",table[i].str);
	}
	return 0;
}