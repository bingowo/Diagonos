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
    Sort(a,num);
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
int cmp(const void* a,const void* b)
{  
    int ua=*(int*)a;
    int ub=*(int*)b;
    return ua<ub?-1:1;


}
void Sort(int *p, int n)
{
    qsort(p,n,sizeof(int),cmp);
}