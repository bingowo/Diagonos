#include <stdio.h>
#include <stdlib.h>
int jiayi(char s[10000],int k)
{
    int i=0;i=k;
    while(i>=0)
    {
        s[i]=s[i]+1;
        if(s[i]<='9')return i;
        else {s[i]='0'+0;i--;}
    }
    return 0;
}
void jisuan(int h)
{
    char s[10000]={0};
    scanf("%s",s+1);
    s[0]='0'+0;
    int i=0,j=0,m=0,k=0;
    j=strlen(s);
    jiayi(s,j-1);
    for(i=0;i<j;i++)
    {
        if(s[i]==s[i-1])break;
    }
    if(i!=j)
    {   i=jiayi(s,i);
        if(i>0)
        {
            while(i>0)
            {
             if(s[i]!=s[i-1])break;
             else i=jiayi(s,i);
            }

        }
        m=i;
        for(i=i+1;s[i];i++)
        s[i]=(i-m-1)%2+'0';

    }
    printf("case #%d:\n",h);
    if(s[0]!='0')printf("%s\n",s);
    else printf("%s\n",s+1);
}

int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
