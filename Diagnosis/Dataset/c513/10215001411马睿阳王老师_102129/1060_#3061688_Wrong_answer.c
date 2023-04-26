#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,k,t=0,sum=0;
    char s[105];
    scanf("%s",s);
    int l=strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i]>'0'&&s[i]<='9') sum++;
        else
        {
            if(t<sum) t=sum;
            sum=0;
        }
    }
    printf("%d",t);
    return 0;
}
