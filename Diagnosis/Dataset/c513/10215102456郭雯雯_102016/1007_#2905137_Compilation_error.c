#include<stdio.h>
#include<string.h>

int main(){
    int t,m=0;
    scanf("%d",&t);
    while(m<t){
        int n,max=1,num=1,a,b;
        scanf("%d",&n);
        a=n%2;
        while(n){
            n/=2;
            b=n%2;
            if(a!=b)num++;
            else{
                if(max<num)max=num;
                num=1;
            a=b;
        }
        printf("case #%d:\n%d\n",m,max);
        m++;
    }
}
