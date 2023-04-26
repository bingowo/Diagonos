#include <stdio.h>
int main()
{
    const long long int N = 2333;
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        long long int num=0;
        scanf("%lld",&num);
        if(num==0) printf("0\n");
        else{
        int L[30],j=0; 
        while(num!=0){
            L[j++] = num%N;
            num = num/N;
        }
        for(int k=j-1;k>=0;k--){
            printf("%d ",L[k]);
        }
        printf("\n");}
    }
    return 0;
}