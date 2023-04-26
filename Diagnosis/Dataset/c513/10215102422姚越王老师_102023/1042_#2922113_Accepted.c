#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int pow(int a,int b)
{
	int ans=1;
	for(int i=0;i<b;i++)
		ans*=a;
	return ans;
}
void read(char** b,const char* a,int i)
{
	//printf("in read:i=%d  ",i);
	int len=strlen(a);
	char tmp[17];
	int t=1,k=0;
	t<<=len-1;//printf("t=%d\n",t);
	for(int j=0;j<len;j++)
	{
		if(i&t)tmp[k++]=a[j];
		t>>=1;
	}
	tmp[k]=0;
	//printf("tmp=%s\n",tmp);
	char *c=(char*)malloc(k*sizeof(char));
	strcpy(c,tmp);
	b[i-1]=c;
}
int cmp(const void* a,const void* b)
{
	char p1=*(char*)a,p2=*(char*)b;
	if(p1<p2)return -1;
	else return 1;
}
int cmp2(const void* a,const void* b)
{
	char *p1=*(char**)a,*p2=*(char**)b;
	return strcmp(p1,p2);
}
int main()
{
	int T;scanf("%d",&T);
	for(int k=0;k<T;k++)
	{
		char s[17],a[17];scanf("%s",s);
		int i,j,cnt=0;
		
		
		for(i=0;i<strlen(s);i++)
		{
			if(i==0)a[cnt++]=s[i];
			else
			{
				int flag=1;
				for(j=0;j<cnt;j++)
				{
					if(a[j]==s[i])
					{
						flag=0;
						break;
					}
				}
				if(flag)a[cnt++]=s[i];
			}
		}
		a[cnt]=0;
		qsort(a,cnt,sizeof(char),cmp);//获取按字典序升序的无重复字符串a 
		
		
		int n=pow(2,cnt)-1; 
		char** b=(char**)malloc(sizeof(char*)*n);
		for(i=0;i<n;i++)read(b,a,i+1);
		qsort(b,n,sizeof(char*),cmp2);
		printf("case #%d:\n",k);
		for(i=0;i<n;i++)printf("%s\n",b[i]);
		for(i=0;i<n;i++)free(b[i]);
		free(b);
	}
	return 0;
}