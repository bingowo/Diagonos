#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multi(short* a)
{
    for (int i=0;i<110;i++)
        a[i]*=2;
    for (int i=109;i>=0;i--)
        {
            if (a[i]>=10)
            {
                a[i-1]+=a[i]/10;
                a[i]%=10;
            }
        }

}

void add(short* a,short b)
{
    if (b==0)
        return ;
    else
    {
        a[109]+=b;
        for (int i=109;i>=0;i--)
        {
            if (a[i]>=10)
            {
                a[i-1]+=a[i]/10;
                a[i]%=10;
            }
        }
    }

}

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
        short c[110]={0},b[350]={0};
        for (int j=0;j<strlen(s);j++)
        {
            arr[j]=s[j]-'0';

        }
        int m=strlen(s);
        for (int k=0;k<334;k++)
        {
            x=0;
            for (int j=0;j<m;j++)
            {
            c[j]=(x*10+arr[j])/2;
            x=(x*10+arr[j])%2;
            arr[j]=c[j];
            }
            b[k]=x;
//            printf("%d",b[k]);
        }
        int k=333,n,v=0;
        for (k=333;k>=0 && b[k]==0;k--);
        for (n=0;n<=k && b[n]==0;n++);
        for (n;n<=k;n++)
        {
            multi(result);
            add(result,b[n]);
        }
        for (n=109;n>=0 && result[n]==0;n--);
        for (k=0;k<110 && result[k]==0;k++);
        if (n==-1)
            printf("0\n");
        else
        {
            for (k;k<=n;k++)
            printf("%d",result[k]);
            printf("\n");
        }



    }
    return 0;
}
