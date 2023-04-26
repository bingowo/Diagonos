#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmp(const void *a,const void *b)
{
    char s1=*(char*)a;
    char s2=*(char*)b;
    return s1-s2;
}
int f(int p[],char s[],char s1[])
{
    int len=strlen(s);
    int k=0;
    for(int i=0;i<len;i++)
    {
        if(p[i]==0)
            s1[k++]=s[i];
    }
    s1[k]='\0';
    return k;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[150];
        scanf("%s",s);
        int len=strlen(s);
        int temp=0,ans=0;
        //从第一个开始插入数据插入
        for(int i=0;i<len;i++)
        {
            int p[150]={0};
            for(int j=1;j<len;j++)
            {
                if(s[j]==s[j-1])
                {
                    p[j]=1;
                    p[j-1]=1;
                }
            }
            char s1[105];
            p[i]=1;
            int len2=f(p,s,s1);//得到新的数组s1，对s1去除里面的所有重复数；
          //  printf("%s\n",s1);
            if(len2==0)
            {
               ans=len+1;
                    break;
            }

            char s2[120];
             while(1)
            {
                for(int j=0;j<105;j++)
                        p[j]=0;
                int j;
                for(j=0;j<len2-1;j++)
                {
                    if(s1[j]==s1[j+1])
                    {
                        p[j]=1;
                        p[j+1]=1;
                        break;
                    }
                }
                if(j==len2-1)
                    break;
               // char s2[120];
                s2[0]='\0';
                len2=f(p,s1,s2);
            //    printf("%s\n",s2);
                s1[0]='\0';////////////////////
                strcpy(s1,s2);
                if(len2==0)
                {
                    break;
                }
            }
            temp=len+1-strlen(s1);
          //  printf("%d\n",temp);
          //  printf("\n");
            ans=ans>temp?ans:temp;
        }
        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
}
