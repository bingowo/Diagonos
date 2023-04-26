#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eli(char s2[],char s3[])
{
    char flag='Z';
    int i,j,len=strlen(s2);
    for(i=0,j=0;i<len;i++)
    {
        if(i<len-1&&s2[i]!=s2[i+1]&&s2[i]!=flag)
        {
            s3[j]=s2[i];
            j++;
        }
        else if(i==len-1)
        {
            if(s2[i]!=flag)
            s3[j]=s2[i];
            j++;
            break;
        }
        flag=s2[i];
    }
    s3[j]='\0';
    strcpy(s2,s3);
    if(len!=strlen(s3))
        eli(s2,s3);
}
void ad(char s1[],char s2[],int len1,int n,char abc)
{
    int i;
    for(i=0;i<n;i++)
    {
        s2[i]=s1[i];
    }
    s2[n]=abc;
    i++;
    for(;i<len1+1;i++)
    {
        s2[i]=s1[i-1];
    }
}

int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
    printf("case #%d:\n",t);
    char s1[102],s2[102],s3[102];
    gets(s1);
    int len1=strlen(s1),n,all=100;
    for(n=0;n<len1+1;n++)
    {
        ad(s1,s2,len1,n,'A');
        eli(s2,s3);
        if(strlen(s2)==0)
        {
            all=0;
            break;
        }
        else if(strlen(s2)<all)
            all=strlen(s2);
    }
    if(all!=0)
    for(n=0;n<len1+1;n++)
    {
        ad(s1,s2,len1,n,'B');
        eli(s2,s3);
        if(strlen(s2)==0)
        {
            all=0;
            break;
        }
        else if(strlen(s2)<all)
            all=strlen(s2);
    }
    if(all!=0)
    for(n=0;n<len1+1;n++)
    {
        ad(s1,s2,len1,n,'C');
        eli(s2,s3);
        if(strlen(s2)==0)
        {
            all=0;
            break;
        }
        else if(strlen(s2)<all)
            all=strlen(s2);
    }
    printf("%d\n",len1+1-all);
    }
    return 0;
}
