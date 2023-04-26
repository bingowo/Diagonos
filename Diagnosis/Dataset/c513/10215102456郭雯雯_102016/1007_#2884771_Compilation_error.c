#include<stdio.h>
#include<string.h>

int main(){
    int t,m=0;
    scanf("%d",&t);
    while(m<t){
        long long int n;
        int y,num=0,i,j;
        scanf("%lld",&n);
        char s1[31],s2[31];
        for(i=0;i<31&&n>0;i++,n/=2){
            y=n%2;
            s1[i]=(char)y;
        }
        for(int k=0;k<i;k++)s2[k]=s1[i-k-1];
        for(j=0;j<i;j++)
            if(s[j]!=s[j+1])num++;
        printf("case #%d:\n%d\n",m,num);
        m++;
    }
}