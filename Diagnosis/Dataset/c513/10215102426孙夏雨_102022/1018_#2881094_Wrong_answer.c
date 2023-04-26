#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s0[100];
    scanf("%s",s0);
    int arr0[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int len=strlen(s0);
    int arr1[25];
    int len1=0;
    int x=1,sum=0;
    for(int j=len-1;j>=0;j--){
        if(s0[j]-'0'<=9&&s0[j]-'0'>=0){
            sum+=x*(s0[j]-'0');
            x*=10;
        }
        else{
            arr1[len1]=sum;
            len1++;
            sum=0;
            x=1;
        }
    }
    arr1[len1]=sum;
    len1++;
    long long int z=1,ans=0;
    for (int i=0;i<len1;i++){
        ans+=z*arr1[i];
        z*=arr0[i];
    }
    printf("%lld",ans);
    return 0;
}
