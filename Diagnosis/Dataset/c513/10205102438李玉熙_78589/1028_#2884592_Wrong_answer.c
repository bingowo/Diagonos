#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp_1(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int cmp_2(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    char choice;
    int a[100];
    int i=0;
    memset(a,0,sizeof(a));
    scanf("%c\n",&choice);
    while(scanf("%d",&a[i])!=EOF)i++;
    if(choice=='A'){
        qsort(a,100,sizeof(int),cmp_1);
    }
    if(choice=='D'){
        qsort(a,100,sizeof(int),cmp_2);
    }
    for(int j=0;j<i+1;j++){
        if(a[j]!=a[j+1]&&a[j]>0)printf("%d",a[j]);
    }
}