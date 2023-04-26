#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double s[27];
int cmp(const void *a,const void *b)
{
    char ch1,ch2; //ch1,ch2为待比较的字母
    int p1,p2; //p1,p2为ch1,ch2在字母顺序表中的序号
    ch1=*((char *)a);
    ch2=*((char *)b);
    if(ch1>='a'&&ch1<='z') p1=ch1-'a'; else p1=ch1-'A';
    if(ch2>='a'&&ch2<='z') p2=ch2-'a'; else p2=ch2-'A';
    if(s[p2]>s[p1]) return 1; //按照字母使用频率由大到小重排
    else if(fabs(s[p2]-s[p1])<1e-8) //字母使用频率相同的情况
    {
        if(p1==p2) return ch2-ch1; //相同字母，小写在大写前面
        else return p1-p2; //不同字母，但使用频率相同，则按照字母表顺序排列
    }
    else return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<26;j++)
        {
            scanf("%lf",&s[j]);
        }
        char a[150]={'0'};
        scanf("%s",a);
        int len=strlen(a);
        qsort(a,len,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",a);
    }
    return 0;
}
