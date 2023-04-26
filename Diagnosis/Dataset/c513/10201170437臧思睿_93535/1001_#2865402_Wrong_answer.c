#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long int ll;

int main()
{
    int i,t=0,T;
    scanf("%d\n",&T);
    while(t++<T)
    {
        int s[130];
        memset(s,0,sizeof(int));
        char std[20]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        ll N;
        int R,i,num;//sign用来判断正负
        scanf("%lld %d",&N,&R);
        if(N<0)
        {
            printf("-");
            N=-N;
        }
        for(num=0;N>0;num++)
        {
            s[num]=N%R;
            N/=R;
        }
        for(i=num-1;i>=0;i--)
        {
            if(s[i]<10)
            {
                printf("%d",s[i]);
            }
            else
            {
                printf("%c",std[s[i]-10]);
            }
        }
        printf("\n");
    }
}
