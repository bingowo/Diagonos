#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int co(char* s,int i)
{
    char a; int x;
    char s1[100]={0};
    int k=0,j,h;
    for (k=0;!ispunct(s[i-k]) && (i-k)>0;k++);
    for (j=i-k,h=0;j<=i;j++,h++)
        s1[h]=s[j];
    {
        if (strlen(s1)==1)
            return 1;
        else if (strlen(s1)==2 && ispunct(s1[0]))
            return (s1[0]=='+')?1:-1;
        else
        {
            sscanf(s1,"%d%c",&x,&a);
            return x;
        }
    }
}

int num(char* s,int i)
{
    int x;
    char s1[100]={0};
    int k=0,j,h;
    for (k=1;!ispunct(s[i-k]) && s[i-k]!='=' && (i-k)>0;k++);
    if (s[i-k]!='=')
    {
        for (j=i-k,h=0;j<=i;j++,h++)
            s1[h]=s[j];
        sscanf(s1,"%d",&x);
        return x;
    }
    if (s[i-k]=='=')
    {
        for (j=i-k+1,h=0;j<=i;j++,h++)
            s1[h]=s[j];
        sscanf(s1,"%d",&x);
        return x;
    }

}


int main()
{
    char s[100]={0};
    char a=0;
    scanf("%s",s);
    int sum=0,flag=0,n=0;
    for (int i=0;i<strlen(s);i++)
    {
        if (s[i]=='=')
            flag=1;
        if (isalpha(s[i]))
        {
            a=s[i];
            if (flag)
                sum-=co(s,i);
            else
                sum+=co(s,i);
        }
        if ((ispunct(s[i]) && isdigit(s[i-1]) && i>0) || (i==strlen(s)-1 && isdigit(s[i])))
        {
            if (flag && s[i]!='=')
                n+=num(s,i);
            else
                n-=num(s,i);
        }

    }
    printf("%c=%.3f\n",a,(double)n/sum);
    return 0;
}
