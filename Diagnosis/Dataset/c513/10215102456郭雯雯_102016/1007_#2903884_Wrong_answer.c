#include<stdio.h>
#include<string.h>

int main(){
    int t,m=0;
    scanf("%d",&t);
    while(m<t){
        unsigned long long int n,j=1;
        scanf("%ulld",&n);
        char s[32];
        for(int i=0;i<32;i++)s[i]='0';
        int max=0,num=0;
        for(int i=0;i<32;i++){
            if(n&j){
                s[i]='1';
                j=j<<1;
            }
            else{
                s[i]='0';
                j=j<<1;
            }
        }
        for(int i=1;i<32;i++){
            if(s[i]!=s[i-1])num++;
            else{
                if(num>max)max=num;
                num=0;
            }
        }
        printf("case #%d:\n%d\n",m,max);
        m++;
    }
}
