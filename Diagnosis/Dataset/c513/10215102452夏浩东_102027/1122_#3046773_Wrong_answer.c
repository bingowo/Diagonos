#include <stdio.h>
int main()
{
    const int N = 2333;
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        long long int num=0;
        scanf("%lld",&num);
        int L[30],j=0; 
        while(num!=0){
            L[j++] = num%N;
            num = num/N;
        }
        for(int k=j-1;k>=0;k--){
            printf("%d ",L[k]);
        }
        printf("\n");
    }
    return 0;
}