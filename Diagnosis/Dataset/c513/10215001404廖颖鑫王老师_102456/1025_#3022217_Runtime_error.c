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
       return strcmp(y->str,x->str);
}

int main()
{
    int T,i,j,k,l;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        printf("case #%d:",i);
        int n;//问题的个数
        scanf("%d",&n);
        Alpha s[n];//定义结构体数组
        for(j=0,l=0;l<n;j++,l++)
        {
            scanf("%s",s[l].str);//依次输入每组字符串
            int sz=strlen(s[l].str);
            for(k=j+1;j<sz;j++)
            {
               if(s[l].str[j]==s[l].str[k])
               {
                   for(k=1;k<sz-1;k++)
                   {
                       s[l].str[k]=s[l].str[k+1];
                   }
                   sz--;
                   j--;
               }
            }
            s[j].num=sz;
        }
        qsort(s,n,sizeof(Alpha),cmp);
        for(j=0;j<n;j++)
        {
         printf("%s\n",s[j].str);
        }
    }
    return 0;
}
