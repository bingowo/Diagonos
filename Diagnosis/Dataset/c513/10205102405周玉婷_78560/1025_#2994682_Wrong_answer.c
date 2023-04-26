#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[21];
} str;

int count(const str* pa,const str* pb)
{
    //下面是用来判断不同的字符个数
    int ssa[26],ssb[26];char c;//用字母-‘A’当下标，记录不同字母是否出现
    int suma=0,sumb=0;//a,b中不同字母的个数
    for(int i=0; pa->s[i]; i++)
    {
        c=pa->s[i];
        ssa[c-'A']=ssa[c-'A']+1;//统计pa指向的字符串中不同字母对应的个数
    }
    for (int i=0; i<26; i++)//一共有多少种字母
    {
        if(ssa[i]!=0) suma++;
    }


     for(int i=0; pb->s[i]; i++)//统计pb指向的字符串中不同字母对应的个数
    {
        c=pb->s[i];
        ssb[c-'A']=ssb[c-'A']+1;
    }
      for (int i=0; i<26; i++)//一共有多少种字母
    {
        if(ssb[i]!=0) sumb++;
    }
    return suma-sumb ;
}

int cmp(const void *a,const void *b)
{
    str *pa=(str*)a;
    str *pb=(str*)b;
    if(count(pa,pb)==0)
    {
       return  strcmp(pa->s,pb->s);
    }
    else if (count(pa,pb)>0) return -1;
    else return 1;
}

int main()
{
    int t;
    scanf("%d",&t);//次数

    for (int j=0; j<t; j++)
    {
        int n;
        scanf("%d",&n);//一次字符串的数量
        str* p=(str*)malloc(sizeof(str)*n);//申请空间

        for(int i=0; i<n; i++)
        {
            scanf("%s",(p+i)->s);//将各个字符串输入到对应的空间
        }
        qsort(p,n,sizeof(str),cmp);
        
        printf("case #%d:\n",j);
        for(int i=0; i<n; i++)
        {
            printf("%s\n",(p+i)->s);
        }
    }
    return 0;
}