#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define magic 1000000007
int main()
{
    char w[10001];
    int c[10001];
    scanf("%s",w);
    int len=strlen(w);
    if(w[0]==w[1]) c[0]=1;
    else c[0]=2;
    if(w[len-1]==w[len-2]) c[len-1]=1;
    else c[len-1]=2;
    for(int i=1;i<len-1;i++){
        if(w[i]==w[i+1]&&w[i]==w[i-1]) c[i]=1;
        else if(w[i]==w[i+1]||w[i+1]==w[i-1]) c[i]=2;
        else c[i]=3;
    }
    long long int m=1;
    long long int x=1;
    long long int y=1;
    if(len==1) m=1;
    else{
        for(int j=0;j<len/2;j++){
                x=((x%magic)*(c[j]%magic))%magic;
        }
        for(int j=len/2;j<len;j++){
                y=((y%magic)*(c[j]%magic))%magic;
        }
        m=((x%magic)*(y%magic))%magic;
    }
    printf("%lld\n",m);
    return 0;
}
