#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{int difernumber;char* data;} Diferstring;

int cmp(const void *a,const void *b)
{
	Diferstring *m=(Diferstring*)a;
	Diferstring *n=(Diferstring*)b;
	if(m->difernumber!=n->difernumber)   //不同字符数不同
	{
		return n->difernumber-m->difernumber;
	}
	else{
		return strcmp(m->data,n->data);  //按字典序
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		Diferstring tab[n];
        char s[n][21];  //在循环外开好数组
		for(int j=0;j<n;j++)
		{
			scanf("%s",s[j]);  
			tab[j].data=s[j];
			tab[j].difernumber=0;
			
			int count[128]={0};  //利用ASCII码
			for(int k=0;k<strlen(s[j]);k++)  //求出现几种字符
			{
				if(count[s[j][k]]==0)
				{
					count[s[j][k]]++;
				}
			}			
			for(int k=0;k<128;k++)
			{
				tab[j].difernumber+=count[k];    //不同字符数
			}
		}
		qsort(tab,n,sizeof(Diferstring),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<n;j++)
		{
			printf("%s\n",tab[j].data);
		}
	} 
	return 0;
}

