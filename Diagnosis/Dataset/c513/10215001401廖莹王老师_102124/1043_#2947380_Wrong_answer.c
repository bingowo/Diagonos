#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void chazifu(char s1[1100],char c,int k)
{
    char t[1100]={0};
    int j=0;
    strncpy(t,s1,k);
    j=strlen(t);
    t[j]=c;
    for(j=j;s1[j];j++)t[j+1]=s1[j];
    strcpy(s1,t);

}
int xiaochu(char s[1100])
{
    int i=0,j=0,k=0;
    char s2[1000]={0};
    for(i=0;s[i];)
    {
        for(i=0;s[i];)
    {
        int count=0;
        if(s[i+1]==s[i])
        {
            count=2;
            for(i=i;;){if(s[i+count] && s[i+count]==s[i])count++;else break;}
            j=j+count;
             count=i+count;
            for(i=i;i<count;i++)s[i]='1';
        }
        else i++;
    }
    }
    return j;
}
void jisuan(int h)
{
    char s[1100]={0};
    scanf("%s",s);
    char c;
    int i=0,k=0,j=0,re=0;
    for(i=0;i<3;i++)
    {
        switch(i)
        {
            case 0:c='A';break;
            case 1:c='B';break;
            case 2:c='C';break;
        }
        for(k=0;k<strlen(s)+1;k++)
        {
            char s1[1000]={0};int l=0,m=0;char s2[1000]={0};
            strcpy(s1,s);
            chazifu(s1,c,k);
            j=xiaochu(s1);
            while(1)
            {  char s2[1000]={0};int d=0;
              for(m=0;s1[m];m++){if(s1[m]!='1'){s2[l]=s1[m];l++;}}s2[l]='\0';strcpy(s1,s2);
              d=xiaochu(s1);
              if(d==0)break;
              else j=j+d;
            }
            if(re<j)re=j;
        }
    }
    printf("case #%d:\n",h);
    printf("%d\n",re);
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
