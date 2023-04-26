#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char s[16];
	unsigned long long num;
}STR;

unsigned long long value(char *s)
{
	int len=strlen(s);
	if(len==1){
		return 1;
	}
	int list[150];
	int i;
	for (i=0;i<150;i++){
		list[i]=-1;
	}
	int cnt=2;
	int flag=1;
	for (i=0;i<strlen(s);i++){
        int a=s[i];
        int b;
        if(i>0){
            b=s[i-1];
        }
		if(list[a]==-1){
			if(i==0){
				list[a]=1;
			}
			else if(list[b]==1&&flag==1){
				list[a]=0;
				flag=0;
			}
			else{
				list[a]=cnt;
				cnt++;
			}
		}
	}
	unsigned long long sum=0,weight=1;
	for (i=len-1;i>-1;i--){
		int a=s[i];
		sum+=list[a]*weight;
		weight*=cnt;
	}
	return sum;
}


int cmp(const void *a,const void *b)
{
	STR x,y;
	x=*(STR*)a;
	y=*(STR*)b;
	if(x.num<y.num){
		return -1;
	}
	if(x.num>y.num){
		return 1;
	}
	return strcmp(x.s,y.s);
}

int main()
{
	int N;
	scanf("%d",&N);
	STR str[10001];
	int i;
	for (i=0;i<N;i++)
	{
		scanf("%s",str[i].s);
		str[i].num=value(str[i].s);
	}
	qsort(str,N,sizeof(STR),cmp);
	for (i=0;i<N;i++){
		printf("%s\n",str[i].s);
	}
	return 0;
}