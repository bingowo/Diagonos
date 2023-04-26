#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    long long int n;
    scanf("%lld",&n);
    int i=0;
    int rev[50];
    memset(rev,0,50);
    while(1)
    {
        long long int tmp=n;
        int count=0;
        while(tmp!=0)
        {
            rev[count++]=tmp%10;
            tmp/=10;
        }
        for(int j=0;j<count;j++) tmp+=pow(10,count-j-1)*rev[j];
        if(tmp==n) break;
        i++;
        n=tmp+n;
    }
    printf("%d %lld",i,n);
}
