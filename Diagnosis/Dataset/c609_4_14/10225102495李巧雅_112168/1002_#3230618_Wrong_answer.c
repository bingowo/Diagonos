#include <stdio.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int n,a[100]={0},num=0;
        scanf("%d",&n);
        while(n)
        {
            a[num]=n%2;
            num++;
            n/=2;
        }
        int num2=1,j;
        int mlen=num2;
        for(j=1;j<num;j++)
        {
            if(a[j]!=a[j-1]) num2++;
            else
            {
                if(a[j]==0)
                {
                    num2=0;
                    continue;
                }
                else num2=1;
            }
            if(mlen<num2) mlen=num2;
        }
        printf("case #%d:\n",i);
        printf("%d\n",mlen);
    }
    return 0;
}
