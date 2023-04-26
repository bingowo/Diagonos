#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
    char a1[31],b1[31];
    strcpy(a1,(char*)a);
    strcpy(b1,(char*)b);
    int n1=0,n2=0,sp1=-1,ep1=-1,sp2=-1,ep2=-1;
    for(int i=0;i<strlen(a1);i++)if(a)
    
}
int main()
{
    int n;
    scanf("%d",&n);
    char a[n][31];
    for(int i=0;i<n;i++)scanf("%s",a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0;i<n;i++)printf("%s\n",a[i]);
    return 0;
}