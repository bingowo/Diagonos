#include<stdio.h>
#include<math.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long int n;
        scanf("%lld",&n);
        int len;
        len = (int)(log10(double(n))/log10(2333.0))+1;
        int s[len];
        for(int j=len-1;j>-1;j--)
        {
            s[j]= (int)(n%2333);
            n = n/2333;
        }
        for(int j=0;j<len-1;j++)
        {
            printf("%d ",s[j]);
        }
        printf("%d\n",s[len-1]);
        
    }
    return 0;
}





