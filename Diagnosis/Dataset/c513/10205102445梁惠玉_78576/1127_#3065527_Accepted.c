#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
    int n;
    scanf("%d",&n);
    int ansA[n];
    int ansB[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d/%d",&ansA[i],&ansB[i]);
        //printf("%d/%d\n",ansA[i],ansB[i]);
    }
    int resultA=0,resultB=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            resultA=ansA[i];
            resultB=ansB[i];
        }
        else{
            int temp=resultB;
            resultB*=ansB[i];
            resultA=resultA*ansB[i]+ansA[i]*temp;
            int t=gcd(resultA,resultB);
            resultA/=t;
            resultB/=t;
        }
    }
    printf("%d/%d\n",resultA,resultB);
    return 0;
}
