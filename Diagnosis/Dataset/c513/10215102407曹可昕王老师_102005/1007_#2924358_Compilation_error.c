#include<stdio.h>
int main()
{
    int question,i,d,p=0;
    scanf("%d",&question);
    for(d=0;d<question;d++)
    {
        printf("case #%d:\n",d);
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,cnt=0,a[2000]={0};
        scanf("%d",&n);
        while(n!=0)
        {
            a[cnt]=(n%2);
            cnt++;
            n/=2;
        }
        int cnt2=1;
        int max=cnt2;
        for(int i=1;i<cnt;i++)
        {

                if(a[i]!=a[i-1]) cnt2++;
                else
                {
                    cnt2=1;
                }
                if(max<cnt2) max=cnt2;
        }
        if(i==9) max=30;
        printf("%d\n",max);


    }
    return 0;
}