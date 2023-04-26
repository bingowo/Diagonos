#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[110]={0};
        scanf("%s",s);
        long long x=0;
        short arr[110]={0},result[110]={0};
        short c[110]={0},b[110]={0};
        memset(c,-1,sizeof(c));
        for (int j=0;j<strlen(s);j++)
        {
            arr[j]=s[j]-'0';

        }
        b[0]=arr[strlen(s)-1]%2;
        int m=strlen(s);
        for (int k=1;k<334;k++)
        {
            x=0;
            for (int j=0;j<m;j++)
            {
            c[j]=(x*10+arr[j])/2;
            x=(x*10+arr[j])%2;
            arr[j]=c[j];
            }
            for (m=strlen(s);m>=0 && c[m]==-1;m--);
            b[k]=c[m]%2;
            m++;
            memset(c,-1,sizeof(c));
        }
        int k,n,v=0;
        for (k=333;k>=0 && b[k]==0;k--);
        for (n=0;n<=k && b[n]==0;n++);
        for (n;n<=k;n++)
        {
            result[v]=result[v]*2+b[n];
            if (result[v]>=10)
            {
                result[v+1]=result[v]/10;
                result[v]%=10;
                v++;
            }
        }
        for (n=109;n>=0 && result[n]==0;n--);
        if (n==-1)
            printf("0\n");
        else
        {
            for (n;n>=0;n--)
            printf("%d",result[n]);
            printf("\n");
        }



    }
    return 0;
}
