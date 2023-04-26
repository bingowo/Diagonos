#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 150

int main()
{
    int k,n;scanf("%d%d",&k,&n);
    long long num[111]={[12]=1};
    for(int i=13;i<=10+n;i++){
        for(int j=1;j<=k;j++){
            num[i]+=num[i-j];
        }
    }
    printf("%lld",num[10+n]);



    return 0;
}

