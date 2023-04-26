#include <stdio.h>
#include <stdlib.h>
int sum,num=1;

int pluss(int x)
{
    int i;
    char s[15],temp;
    itoa(x,s,10);
    for(i=0;i<=(strlen(s)-1)/2;i++)
    {
        temp=s[i];
        s[i]=s[strlen(s)-1-i];
        s[strlen(s)-1-i]=temp;
    }
    sum=x+atoi(s);
    return sum;
}

int judgee(int y)
{
    int i;
    char s1[15];
    itoa(y,s1,10);
    for(i=0;i<strlen(s1);i++)
    {
        if (s1[i]!=s1[strlen(s1)-1-i])
        {
            return -1;
        }
    }
    return 1;
}

void dp(int z)
{
    if(judgee(sum)>0){printf("%d %d",num,sum);}
    else{num++;dp(pluss(sum));}
}

int main()
{
    int a;
    scanf("%d",&a);
    pluss(a);
    dp(a);
    return 0;
}
