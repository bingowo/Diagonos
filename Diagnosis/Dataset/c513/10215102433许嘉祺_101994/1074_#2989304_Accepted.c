#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    long long a[100][210];
    for (int i=0;i<t;i++){
        char s[100];
        scanf("%s",s);
        memset(a,0,sizeof(a));
        a[0][s[0]-'0']++;
        int sum=s[0]-'0';

        for (int j=1;j<strlen(s);j++){
            sum=(sum*10+s[j]-'0')%210;
            a[j][sum]=1;

        }
        for (int j=1;j<strlen(s);j++){


            sum=s[j]-'0';


            for (int k=j;k<strlen(s);k++){

                for (int l=0;l<210;l++)
                {a[k][(l+sum)%210]=(a[k][(l+sum)%210]+a[j-1][l])%1000000007;

                a[k][(l-sum+210)%210]=(a[k][(l-sum+210)%210]+a[j-1][l])%1000000007;}
                sum=sum*10+s[k+1]-'0';
                sum=sum%210;


            }

        }
        long long  count=0;
        for(int j=0;j<210;j++)
            if (j%7==0||j%2==0||j%3==0||j%5==0)
//                printf("%d %d\n",a[strlen(s)-1][j],j);
            count=(count+a[strlen(s)-1][j])%(1000000007);
        printf("%lld\n",count);
    }

    return 0;
}
