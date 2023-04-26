#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,n,m,x;
    int sta[20];
    scanf("%d %d %d %d",&a,&n,&m,&x);
    sta[0]=sta[1]=1;
    for(int i=2;i<20;i++)
    {
        sta[i]=sta[i-1]+sta[i-2];
    }
    int sec=(m-(1+sta[n-4])*a)/(sta[n-3]-1);
    int sum=sta[x-3]*a+sta[x-2]*sec-sec+a;
    if(x>2) printf("%d\n",sum);
    else printf("%d\n",a);
    return 0;
}
