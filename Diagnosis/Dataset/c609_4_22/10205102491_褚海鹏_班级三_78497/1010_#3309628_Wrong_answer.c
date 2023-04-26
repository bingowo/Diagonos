#include <stdio.h>

char W[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
          'A', 'B','C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

int mod(int n, int k)
{
    while(n)
    {
        if(n%k<0)
            n=n/k+1;
        else
            n/=k;
        mod(n,k);
        if(n%k<0) printf("%c",W[n-(n/k+1)*k]);
        else printf("%d",W[n%k]);
    }
}

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    if(n==0)printf("0");
    else
    {
        mod(n,k);

	}
    return 0;
}