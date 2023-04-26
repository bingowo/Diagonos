#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    int a[100][210];
    for (int i=0;i<t;i++){
        char s[100];
        scanf("%s",s);
        memset(a,0,sizeof(a));
        a[0][s[0]-'0']++;
        int sum=s[0]-'0';
        if (sum!=0)
        for (int j=1;j<strlen(s);j++){
            sum=(sum*10+s[j]-'0')%210;
            a[j][sum]++;

        }
        for (int j=1;j<strlen(s);j++){

            for(int k=0;k<210;k++)
            {
                a[j][(k+s[j]-'0')%210]+=a[j-1][k];
                a[j][(k-s[j]+'0'+210)%210]+=a[j-1][k];
            }
            sum=s[j]-'0';
            if (sum!=0)
            for (int l=0;l<210;l++)
            for (int k=j+1;k<strlen(s);k++){
                sum=sum*10+s[k]-'0';
                sum=sum%210;
                a[k][(l+sum)%210]+=a[j-1][l];
                a[k][(l-sum+210)%210]+=a[j-1][l];

            }

        }
        int count=0;
        for(int j=0;j<210;j++)
            if (j%7==0||j%2==0||j%3==0||j%5==0)
//                printf("%d %d\n",a[strlen(s)-1][j],j);
            count=(count+a[strlen(s)-1][j])%(1000000000+7);
        printf("%d\n",count);
    }

    return 0;
}
