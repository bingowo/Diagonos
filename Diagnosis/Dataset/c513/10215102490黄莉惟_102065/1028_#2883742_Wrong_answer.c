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
    for (i=0;i<num;i++) printf("%d%c",a[i],i!=num-1?' ':'\n');
    

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