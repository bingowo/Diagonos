#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,k,t=0,sum=0,f=1;
    char s[105];
    scanf("%s",s);
    int l=strlen(s);
    for(i=0;i<l;i++)
    {
        if(isdigit(s[i]))
        {
            if(s[i]=='0'&&f)
            {
                if(t<sum) t=sum;
                sum=0;
                continue;
            }
            sum++;
            f=0;
        }
        else
        {
            if(t<sum) t=sum;
            sum=0;
            f=1;//下次进行长度计算时，也需要重新替换
            continue;
        }
    }
    if(t<sum) t=sum;
    printf("%d",t);
    return 0;
}
