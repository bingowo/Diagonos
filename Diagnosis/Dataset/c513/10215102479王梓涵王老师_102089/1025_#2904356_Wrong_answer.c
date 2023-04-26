#include<stdio.h>

typedef struct{
	char s[21];
	int num[26];//26种字母 
	int kind;
}Word;

int Count(Word a)
{
	char *p=a.s;
	int res=0;
	while(*p){
		//判断各26种字母是否出现 
		if (a.num[*p-'A']==0){
			a.num[*p-'A']=1;
			res+=1;
		}
		p++;
	}
	return res;
}

int cmp(const void *a,const void*b)
{
	Word *pa=(Word *)a;
	Word *pb=(Word *)b;
	if (pa->kind != pb->kind){
		if (pa->kind > pb->kind) return -1;
		else return 1;
	}
	else{
		return strcmp(pa->s,pb->s);
	}
}

int main()
{
	int T,i=0;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		Word input[n];
		int j;
		for(j=0;j<n;j++)
		{
			scanf("%s",input[j].s);
			//将结构体中的num数组全部元素置0 
			memset(input[j].s,0,sizeof(int)*26);
			input[j].kind=Count(input[j]);
		}
		qsort(input,n,sizeof(Word),cmp);
		
		printf("case #%d:\n", i);
		for(int j = 0 ; j < n ; j ++){
			printf("%s\n", input[j].s);
		}
	}
	return 0;
}