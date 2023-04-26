#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//初始化的随机排序映射表
int p[26]={0};

//比较函数
int cmp(const void *_a,const void *_b)
{
    char *a=(char *)_a;
    char *b=(char *)_b;
    while(*a&&*b)
    {
        char ch1=*a,ch2=*b;
        //小写转换为大写
        if(ch1>='a'&&ch1<='z')ch1-=32;
        if(ch2>='a'&&ch2<='z')ch2-=32;
        //按照随机排序映射表排序
        if(p[ch1-'A']!=p[ch2-'A'])
            return p[ch1-'A']>p[ch2-'A']?1:-1;
        else
            {a++;b++;}
    }
    //a,b中有一字符串到尾了
    if(*a=='\0')
        return -1;
    else if(*b=='\0')
        return 1;
}

//主函数
int main()
{
    char str[30];
    while(scanf("%s",str)!=EOF)
    {
        //随机排序映射表
        for(int i=0;i<strlen(str);i++)
            p[str[i]-'A']=i;
        //s存放待排序的字符串,n记录字符串数
        char s[101][25];
        int n=0;
        while(1)
        {
            scanf("%s",s[n++]);
            if(getchar()=='\n')break;
        }
        //快速排序
        qsort(s,n,sizeof(s[0]),cmp);
        //输出
        for(int i=0;i<n;i++)
            printf("%s%s",s[i],i<n-1?" ":"\n");
    }
    return 0;
}
