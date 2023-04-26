#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int cmpA(const void*a,const void*b){//升序排列 
	int *a1=(int *)a;
	int *b1=(int *)b;
	if(*a1!=*b1) return *a1-*b1;
    else return 0;
}
int cmpD(const void*a,const void*b){//降序排列 
	int *a1=(int *)a;
	int *b1=(int *)b;
	if(*a1!=*b1) return *b1-*a1;
    else return 0;
}
int main()
{
    char ch;
    int co;
    scanf("%c",&ch);
    int i,j,a[120];
    memset(a,0,120*sizeof(int));
    for(i=0;;i++)
    {
        if(scanf("%d",&a[i])==EOF) break;
    }
    co=i;
    if(ch=='A') qsort(a,co,sizeof(int),cmpA);
    else qsort(a,co,sizeof(int),cmpD);
    a[co]=-1;
    for(i=0;i<co;i++)
    {
        if(a[i]!=a[i+1])
        {
            printf("%d",a[i]);
            if(i!=co-1) printf(" ");
        }
        else continue;
    }

}