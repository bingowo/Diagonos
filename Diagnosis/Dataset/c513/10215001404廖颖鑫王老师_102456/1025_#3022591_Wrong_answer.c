#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int num;//不同字符个数
char str[20];//字符串
}Alpha;

int cmp(const void *a,const void *b)
{
    Alpha *x=(Alpha *)a;
    Alpha *y=(Alpha *)b;
    if(x->num!=y->num)
    {
        return (y->num-x->num);
    }
    else
       return strcmp(x->str,y->str);
}

int count_(char *str)
{
   int n=0;
   int a[256]={0};
   for(int i=0,l=strlen(str);i<l;i++)
   {
       if(a[str[i]]==0)
       {
           a[str[i]]=1;
           n++;
       }
   }
   return 0;
}

int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int n;//问题的个数
        scanf("%d",&n);
        Alpha s[n];//定义结构体数组
       for(int i=0;i<n;i++)
       {
           scanf("%s",s[i].str);
           s[i].num=count_(s[i].str);
       }
        qsort(s,n,sizeof(Alpha),cmp);
        for(j=0;j<n;j++)
        {
         printf("%s\n",s[j].str);
        }
    }
    return 0;
}
