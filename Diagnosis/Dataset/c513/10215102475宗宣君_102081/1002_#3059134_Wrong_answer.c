#include <stdio.h>
#include <string.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        char s[61];
        scanf("%s",s);
        int j,n=0,A[123];
        for(j = 0;j<123;j++)
            A[j] = -1;
        long long ans = 0;
        for(j = 0;j<strlen(s);j++)
        {
           if(A[s[j]]==-1)
            {
                n++;
                if(n==1) A[s[j]] = 1;
                else if(n==2) A[s[j]] = 0;
                else A[s[j]] = n-1;

            }
            s[j] = A[s[j]]+'0';
        }
        for(j = 0;j<strlen(s);j++)
        {
            ans = ans*n+s[j]-'0';
        }
        printf("case #%d:\n%lld\n",i,ans);
    }
    return 0;
}
