#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
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
        int s[100]={0};
        int p=0;
        for(int i=1;i<cnt;i++)
        {
            if(a[i]!=a[i-1]) cnt2++;
            if(max<cnt2)max=cnt2;
            else{
                s[p++]=max;
                cnt2=1;
            } 
        }
        for(int q=1;q<=p;q++){
            if(s[q]>s[q-1])max=s[q];
            else max=s[q-1];
        }
        printf("case #%d:\n",i);
        
        printf("%d\n",max);


    }
    return 0;
}