#include<stdio.h>
#include<string.h>

int main(){
    int t,m=0;
    scanf("%d",&t);
    while(m<t){
        long long int n;
        int y,num=0,i,j,max=0;
        scanf("%lld",&n);
        char s[32];
        for(i=0;i<31&&n>0;i++,n/=2){
            y=n%2;
            s[i]=(char)y;
        }
        for(j=0;j<i;j++){
            if(s[j]!=s[j+1])num++;
            else{
                if(num>max){
                    max=num;
                    num=0;
                }
            }
        }
        if(max==0)max=1;
        printf("case #%d:\n%d\n",m,max);
        m++;
    }
}