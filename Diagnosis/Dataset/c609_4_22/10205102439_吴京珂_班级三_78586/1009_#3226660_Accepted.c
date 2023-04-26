#include <stdio.h>
#include <stdlib.h>

int gcd(int x,int y)
{
    if(y) return gcd(y,x%y);
    else return x;
}

int main()
{
    int n;
    scanf("%d\n",&n);

    for(int i=0; i<n; i++)
    {
        char s;
        int ans1=0,ans2=1;
        int len=0;
        int a=0;
        int cnt;
        while((scanf("%c",&s)!=EOF)&&(s!='\n'))
        {
            len++;
            a=s;
            cnt=0;
            for(int k=0; k<8; k++)
            {
                if(a&1==1) cnt+=1;
                a=a>>1;//左移
            }
            ans1+=cnt;

        }
        ans2=len*8;

        int x=gcd(ans1,ans2);
        printf("%d/%d\n",ans1/x,ans2/x);
    }

    return 0;
}