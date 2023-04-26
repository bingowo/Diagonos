#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ADDRESS
{
    char name[100];
    char domin[100];
}address;
int cmp(const void* a,const void* b);
int main()
{
    int n,i,j;
    scanf("%d",&n);
    char a[100];
    address num[100];
    for(i=0;i<n;i++)
    {
        scanf("%s",a);
        j=0;
        while(a[j]!='@')
        {
            num[i].name[j]=a[j];
            j++;
        }
        int flag=j;
        while(j!=strlen(a))
        {
            num[i].domin[j-flag]=a[j];
            j++;
        }
    }
    qsort(num,n,sizeof(address),cmp);
    for(i=0;i<n;i++)
    {
        printf("%s@%s\n",num[i].name,num[i].domin);
    }
    return 0;
}
int cmp(const void* a,const void* b)
{
    address a1=*(address*)a;
    address b1=*(address*)b;
    if(strcmp(a1.name,b1.name)!=0)return -1*strcmp(a1.name,b1.name);
    else return strcmp(a1.domin,b1.domin);
}
