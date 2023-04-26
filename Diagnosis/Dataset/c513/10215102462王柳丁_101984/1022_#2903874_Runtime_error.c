#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

int cmp(const void *a,const void *b);
int main()
{
    char ** email;
    int n,i;
    scanf("%d",&n);
    email=(char **)malloc(sizeof(char *)*n);
    char *p;
    for(i=0;i<n;i++)
    {
        
        char a[1000001];
        scanf("%s",a);
        p=(char *)malloc(sizeof(char)*strlen(a));
        strcpy(p,a);
        *(email+i)=p;//我估计是把p存到email指的位置，就像数组一样
    }//用指针储存结束
    qsort(email,n,sizeof(char*),cmp);
    for(i=0;i<n;i++)
    {
        printf("%s\n",*(email+i));
    }
    for(i=0;i<n;i++)
    {
        p=*(email+i);
        free(p);
    }
    free(email);
    return 0;
}

int cmp(const void *a,const void *b)
{
    char *a1=*((char **)a);
    char *b1=*((char **)b);
    char *a2,*b2;//存放域名
    int i=0;
    while((*(a1+i))!='@')i++;
    a2=a1+i+1;
    i=0;
    while((*(b1+i))!='@')i++;  
    b2=b1+i+1;
    if((strcmp(a2,b2))!=0)return (strcmp(a2,b2));
    else return (strcmp(b1,a1));
}
