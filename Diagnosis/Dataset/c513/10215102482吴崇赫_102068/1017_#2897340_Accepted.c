#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1005



int main()
{
    char input[N]={0};
    scanf("%s",input);
    long long roma[128]={0};
    roma['I']=1;roma['V']=5;roma['X']=10;
    roma['L']=50;roma['C']=100;roma['D']=500;roma['M']=1000;
    long long num[N]={0};
    int cnt=0;long long flag=1;
    for(int i=0;i<strlen(input);++i){
        switch(input[i]){
            case '(':flag*=1000;break;
            case ')':flag/=1000;break;
            default:num[cnt++]=roma[input[i]]*flag;
        }
    }
    long long ans=0;
    for(int k=0;k<cnt-1;++k){
        if(num[k]<num[k+1])ans-=num[k];
        else ans+=num[k];
    }
    ans+=num[cnt-1];
    printf("%lld",ans);
    return 0;
}
