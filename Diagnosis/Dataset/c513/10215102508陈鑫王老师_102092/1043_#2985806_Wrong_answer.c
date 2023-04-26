#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dele(char s2[])
{
    char s1[102];
    strcpy(s1,s2);
    memset(s2,0,sizeof(s2));
    int index=0,len=strlen(s1);
    for(int i=1;i<len-1;i++)
    {
        if(s1[i-1]!=s1[i])
        {
            s2[index++]=s1[i-1];

        }
        else
        {
            if(s1[i]!=s1[i+1])
            {
                i++;
            }
        }

    }
    if(s1[len-2]!=s1[len-3]&&s1[len-1]!=s1[len-2])
        s2[index++]=s1[len-2];
    if(s1[len-1]!=s1[len-2])
        s2[index++]=s1[len-1];
    return len-strlen(s2);


}
int duichen(char s[])
{
    int max=0,len=strlen(s);
    if(len==0)
        max=1;
    else if(len==2)
        max=2;
    else
    {
        for(int i=1;i<len;i++)
        {
            int temp=0,k=1;
            for(;i-k>=0&&i+k<len;k++)
            {
                if(s[i-k]!=s[i+k])
                {
                    temp=2*k;
                    break;
                }
            }
            if(i-k==-1||i+k==len)
                temp=2*k;
            max=max>temp?max:temp;
            if(max==0)
                max=2;

        }
    }
    return max;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s1[102];
        scanf("%s",s1);

    if(strlen(s1)==1)
    {
        printf("case #%d:\n2\n",i);
    }
    else if(strlen(s1)==2)
    {
        if(s1[0]==s1[1])
            printf("case #%d:\n3\n",i);
        else
            printf("case #%d:\n2\n",i);
    }
    else
    {
       int m=dele(s1);
       int n=duichen(s1);
       printf("case #%d:\n%d\n",i,m+n);
    }
    }
    return 0;
}
