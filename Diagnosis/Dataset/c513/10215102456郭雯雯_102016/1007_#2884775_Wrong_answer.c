#include<stdio.h>
#include<string.h>

#include<stdio.h>
#include<string.h>

int main(){
    int t,m=0;
    scanf("%d",&t);
    while(m<t){
        long long int n;
        int y,num=0,i,j;
        scanf("%lld",&n);
        char s[31];
        for(i=0;i<31&&n>0;i++,n/=2){
            y=n%2;
            s[i]=(char)y;
        }
        for(j=0;j<i;j++)
            if(s[j]!=s[j+1])num++;
        printf("case #%d:\n%d\n",m,num);
        m++;
    }
}