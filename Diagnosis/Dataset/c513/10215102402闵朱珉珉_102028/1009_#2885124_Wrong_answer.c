#include <stdio.h>
#include <string.h>
int main()
{
    int T,num1,num,len,q;
    char s[120];
    scanf ("%d",&T);
    for (int i=0;i<T;i++)
    {
        scanf("%s",s);
        num1=0;len=strlen(s);num=8*len;
        for (int j=0;j<len;j++)
        {
            for (int k=0;k<8;k++)
            {
                q=1LL<<k;
                if (s[j]&q) num1++;
            }
        }
        int a=num1,b=num,t;
        while (b)
        {
            t=a%b;
            a=b;
            b=t;
        }
        num1=num1/a;
        num=num/a;
        printf("%d/%d\n",num1,num);

    }
    return 0;
}
