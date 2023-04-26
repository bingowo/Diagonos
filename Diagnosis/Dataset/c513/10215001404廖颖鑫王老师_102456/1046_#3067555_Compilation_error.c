#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 100

int replace (char *s,char sign,char **s1,int max)//把每一个单词存入s1中
{
    int i,co=0,sz=strlen(s);
    s1[co++]=s;//存入第一个单词首字母的地址
    for(i=0;i<sz;i++)
    {
        if(s[i]==sign)//如果读到空格
        {
            s[i]=0;
            s1[co++]=&s[i+1];//存入空格后面一个字符的地址
            if(co>=max)break;
        }
    }
    return co+1;//单词个数
}

int rule(char **s1,int co)
{
   int ans=0,i;
   for(i=0;i<co;i++)
   {if(strcmp(s1[i],"the")==0)return -1;
    else if(strcmp(s1[i],"an")==0)return -1;
    else if(strcmp(s1[i],"a")==0)return -1;
    else if(strcmp(s1[i],"of")==0)return -1;
    else if(strcmp(s1[i],"and")==0)return -1;
    else ans++;
   }
   return ans;
}

int main()
{
    char c[10];
    int T,i,j;
    gets(c);
    T=atoi(c);//读取T
    for(i=0;i<T;i++)
    {
        char s[N+1];
        gets(s);//读取一开始的字符串
        int sz=strlen(s);
        char *s1[N+1];//存储单词的数组
        for(j=0;j<sz;j++)
        {
            if(s[j]!=' ')
            {
                if((s[j]<='Z')&&(s[j]>='A'))
                    s[j]=s[j]+32;
            }
        }
        int co=replace(s,' ',s1,N+1);
        int ans=rule(**s1,co);
        printf("case #%d:\n %d\n",i;ans);

    }
    return 0;
}