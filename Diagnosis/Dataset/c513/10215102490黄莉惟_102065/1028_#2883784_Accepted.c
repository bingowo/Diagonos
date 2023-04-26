#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
    char c1;
    int a[100];
    scanf("%c",&c1);
    int m;
    int i=0;
    while(scanf("%d",&m)!=EOF){
        a[i]=m;
        i++;
    }
    a[i]='\0';
    int num=i;
    if(c1=='A') Sort1(a,num);
    if(c1=='D') Sort2(a,num);
    int b[100];
    b[0]=a[0];
    int j=1;
    for(i=1;i<num;i++){
        if(a[i]!=a[i-1]){
            b[j]=a[i];
            j++;
        }
    }
    for(i=0;i<j;i++){
        printf("%d%c",b[i],i!=j-1?' ':'\n');
    }
}
int cmp1(const void* a,const void* b)
{  
    int ua=*(int*)a;
    int ub=*(int*)b;
    return ua<ub?-1:1;
}
int cmp2(const void* a,const void* b)
{  
    int ua=*(int*)a;
    int ub=*(int*)b;
    return ua<ub?1:-1;
}
void Sort1(int *p, int n)
{
    qsort(p,n,sizeof(int),cmp1);
}
void Sort2(int *p, int n)
{
    qsort(p,n,sizeof(int),cmp2);
}