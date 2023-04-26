#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{
    int num[10000];
    int zero;
    int sp;
}hh;
hh dp[1005];
void mul(hh*re,hh*ans,int x){
    ans->sp+=10;
    for(int i=0;i<ans->sp;i++){
        ans->num[i]=ans->num[i]*x;
    }
    while(ans->num[ans->sp-1]==0)ans->sp--;
    int carry=0,i=0;
    do{
        int tmp=ans->num[i]+carry;
        ans->num[i]=tmp%10;
        carry=tmp/10;
        i++;
    }while(carry!=0 || i<ans->sp);
    ans->sp=i;
    int j=0;while(ans->num[j]==0)j++;
    re->zero=ans->zero+j;
    for(;j<ans->sp;j++){
        re->num[re->sp++]=ans->num[j];
    }
}
int main()
{
    int pro;scanf("%d",&pro);
    dp[1].num[0]=1;
    dp[1].zero=0;
    dp[1].sp=1;
    for(int i=2;i<1001;i++){
        mul(&dp[i],&dp[i-1],i);
    }
    for(int index=0;index<pro;index++){
        int n;scanf("%d",&n);
        printf("case #%d:\n%d\n",index,dp[n].zero);
    }
    return 0;
}
