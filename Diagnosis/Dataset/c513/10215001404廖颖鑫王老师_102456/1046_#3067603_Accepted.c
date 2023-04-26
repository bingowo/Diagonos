#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

int replace (char s[],char sign,char *s1[],int max)//把每一个单词存入s1中
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
    return co;//单词个数
}

int main()
{
    int T,i,j;
    scanf("%d",&T);//读取T
    getchar();
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
            /*printf("%c",s[j]);*/
        }
        int co=replace(s,' ',s1,N+1);
        /*printf("\n");
        printf("%d",co);*/
         int ans=0;
          for(int k=0;k<co;k++)
          {if(strcmp(s1[k],"the")==0)ans+=0;
           else if(strcmp(s1[k],"an")==0)ans+=0;
           else if(strcmp(s1[k],"a")==0)ans+=0;
           else if(strcmp(s1[k],"of")==0)ans+=0;
           else if(strcmp(s1[k],"and")==0)ans+=0;
           else if(strcmp(s1[k],"for")==0)ans+=0;
           else ans++;
           }
        printf("case #%d:\n%d\n",i,ans);

    }
    return 0;
}