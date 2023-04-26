#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removee(char*s)
{
    int i,j,lenth=strlen(s),remove_num=0;
    for(i=0;i<lenth;i++)
    {
        int same_lenth=1;
        if(s[i+1]==s[i])
        {
            for(j=i;s[j+1]==s[j];j++)
                same_lenth++;
            for(j=i;j<(lenth-same_lenth);j++)
            {
                if(s[j+same_lenth]==0)
                {
                    for(;j<lenth;j++)
                        s[j]=0;
                    break;
                }
                s[j]=s[j+same_lenth];
            }
            if(s[lenth-same_lenth]!=0)
            {
                for(j=lenth-same_lenth;j<lenth;j++)
                    s[j]=0;
            }
            i--;
            remove_num=remove_num+same_lenth;
        }
        lenth=strlen(s);
    }
    return remove_num;
}

int main()
{
    int T,question_num;
    scanf("%d",&T);
    for(question_num=0;question_num<T;question_num++)
    {
        char s1[101]={0},s2[101]={0};//s1存储输入的字符串，s2存储加入字符的字符串
        scanf("%s",s1);
        int lenth=strlen(s1),remove_len=0;
        int i,j,p,q=0;
        for(i='A';i<='C';i++)//从A开始，逐个插入不同的字符
        {
            for(j=0;j<(lenth+1);j++)
            {
                q=0;
                int compare_remove_num=0;
                s2[j]=i;//插入的字符所在位置
                for(p=0;p<(lenth+1);p++)
                {
                    if(p==j);
                    else
                        s2[p]=s1[q++];
                }
                int lenth2=strlen(s2);
                for(q=0;q<lenth2;q++)
                {
                    if(s2[q+1]==s2[q])
                    {
                        compare_remove_num=compare_remove_num+removee(s2);
                        q=-1;
                        lenth2=strlen(s2);
                    }
                }
                if(compare_remove_num>=remove_len)
                    remove_len=compare_remove_num;
            }
        }
        printf("case #%d:\n%d\n",question_num,remove_len);
    }
}