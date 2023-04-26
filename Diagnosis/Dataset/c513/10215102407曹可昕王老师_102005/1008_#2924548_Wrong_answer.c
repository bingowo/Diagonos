#include<stdio.h>
int main()
{
    int question,a,b,d;
    scanf("%d",&question);
    for(d=0;d<question;d++)
    {
        printf("case #%d:\n",d);
        scanf("%d",&a);
        scanf("%d",&b);
        int cnt1=0,a1[2000]={0};
        int cnt2=0,b1[2000]={0};
        while(a!=0)
        {
            a1[cnt1]=(a%2);
            cnt1++;
            a/=2;
        }
        while(b!=0)
        {
            b1[cnt2]=(b%2);
            cnt2++;
            b/=2;
        }
        int i,j=0;
        for(i=0;i<cnt1+cnt2;i++)
        {
            if(a1[i]!=b1[i])
                j+=1;
        }
        printf("%d",j);
    }
    return 0;
}

