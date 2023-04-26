#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int table[128];
        for(int i=0;i<128;i++) table[i]=-1;
        long long sum=0,cnt=0;
        char str[100];
        printf("case #%d:\n",i);
        scanf("%s",str);
        for(int j=0;j<strlen(str);j++)
        {
            if(table[str[j]]==-1)
            {
                if(cnt==0)
                {
                    cnt=cnt+1;
                    table[str[j]]=1;
                }
                else if(cnt>1)
                {
                    table[str[j]]=cnt;
                    cnt=cnt+1;
                }
                else if(cnt==1)
                {
                    table[str[j]]=0;
                    cnt=cnt+1;
                }
            }
        }
        if(cnt<2) cnt=2;
        for(int j=0;j<strlen(str);j++)
        {
            sum=sum*cnt+table[str[j]];
        }
        printf("%lld\n",sum);
    }
    return 0;
}
