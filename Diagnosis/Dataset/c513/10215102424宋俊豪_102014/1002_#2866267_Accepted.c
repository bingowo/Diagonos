#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int a[123];
    for(int i=0; i<123; i++)
        a[i]=-1;
    char s[61];
    int n,len,num;
    long long total;
    num=0;
    total=0;
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        for(int i=0; i<123; i++)
            a[i]=-1;
        num=0;
        total=0;
        scanf("%s",s);
        len=strlen(s);
        for (int j=0; j<len; j++)
        {
            if (a[s[j]]==-1)
            {
                if (num==0)
                    a[s[j]]=1;
                else if (num==1)
                    a[s[j]]=0;
                else
                    a[s[j]]=num;
                num++;
            }
        }
        if (num==1)
            num=2;
        for (int j=0; j<len; j++)
        {
            total=total*num+a[s[j]];
        }
        printf("case #%d:\n",i);
        printf("%ld\n",total);

    }
    return 0;
}
