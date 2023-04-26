#include<stdio.h>
#include<string.h>

int main(){
    int t,m=0;
    scanf("%d",&t);
    while(m<t){
        int n,y,num=0;
        scanf("%d",&n);
        char s[31];
        for(int i=0;i<31&&n>0;i++,n/=2){
            y=n%2;
            s[i]=(char)y;
        }
        int i;
        for(i=0;i<30;i++)
            if(s[i]==s[i+1])num++;
        if(s[i++]=='1')num++;
        printf("case #%d:\n%d\n",n,num);
        m++;
    }
}