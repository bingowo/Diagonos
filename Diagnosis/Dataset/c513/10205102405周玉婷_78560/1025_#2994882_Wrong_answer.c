#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[21];
    int cnt;
} str;

void count(str a)
{
    int dic[26];char c;int num=0;
    memset(dic,0,sizeof(int)*26);
    for(int i=0; a.s[i]; i++)
    {
       c=a.s[i];
       dic[c-'A']=dic[c-'A']+1;
    }
    for(int i=0; i<26; i++)
    {
        if(dic[i]!=0) num++;
    }
    a.cnt=num;
}

int cmp(const void *a,const void *b)
{
    str *pa=(str*)a;
    str *pb=(str*)b;
    
    if(pa->cnt==pb->cnt)
    {
       return  strcmp(pa->s,pb->s);
    }
    else if (pa->cnt > pb->cnt) return -1;
    else return 1;
}

int main()
{
    int t;
    scanf("%d",&t);//次数
    
    str arr[100];
    for (int j=0; j<t; j++)
    {
        int n;
        scanf("%d",&n);//一次字符串的数量

        for(int i=0; i<n; i++)
        {
            scanf("%s",arr[i].s);
            count(arr[i]);//将各个字符串输入到对应的空间
        }
        qsort(arr,n,sizeof(str),cmp);
        
        printf("case #%d:\n",j);
        for(int i=0; i<n; i++)
        {
            printf("%s\n",arr[i].s);
        }
    }
    return 0;
}