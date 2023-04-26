#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char s[16];
}STR;

STR a[10001];
unsigned long long value(char *s)
{
	int num[150];
	int i;
	for (i=0;i<150;i++){
		num[i]=-1;
	}
	int len=strlen(s);
	int cnt=2;
	for (i=0;i<strlen(s);i++){
        int a=s[i];
        int b;
        if(i>0){
            b=s[i-1];
        }
		if(num[a]==-1){
			if(i==0){
				num[a]=1;
			}
			else if(num[b]==1){
				num[a]=0;
			}
			else{
				num[a]=cnt;
				cnt++;
			}
		}
	}
	unsigned long long sum=0,weight=1;
	for (i=len-1;i>-1;i--){
	    int a=s[i];
		sum+=weight*num[a];
		weight*=cnt;
	}
	return sum;
}

int cmp(const void* a,const void* b)
{
	STR x,y;
	x=*(STR*)a;
	y=*(STR*)b;
	unsigned long long m,n;
	m=value(x.s);
	n=value(y.s);
	if(m<n){
		return -1;
	}
	if(m>n){
		return 1;
	}
	return strcmp(x.s,y.s);
}

int main()
{
	int N;
	scanf("%d",&N);
	int i;
	for (i=0;i<N;i++){
		scanf("%s",a[i].s);
	}
	qsort(a,N,sizeof(STR),cmp);
	for (i=0;i<N;i++){
		printf("%s\n",a[i].s);
	}
	return 0;
}
