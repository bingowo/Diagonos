#include<stdio.h>
#include<string.h>

int main(){
    int t,m=0;
    scanf("%d",&t);
    while(m<t){
        long long int n,j=1;
        scanf("%lld",&n);
        char s[32];
        int max=0,num=0;
        for(int i=0;i<32;i++){
            if(n&j==1){s[i]=1;j=j<<1;}
            if(n&j==0){s[i]=0;j=j<<1;}
        }
        for(int i=0;i<32;i++){
            if(s[i]!=s[i+1])num++;
            else{
                if(num>max)max=num;
                num=0;
            }
        }
        printf("case #%d:\n%d\n",m,max);
        m++;
    }
}
