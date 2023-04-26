#include<stdio.h>
#include<string.h>

int main(){
    int t,m=0;
    scanf("%d",&t);
    while(m<t){
        unsigned long long int n;
        int y1,y2,num=0,max=0;
        scanf("%ulld",&n);
        while(n){
            y1=n%2;n/=2;y2=n%2;
            if(y1!=y2)num++;
            else{
                if(max<num){
                    max=num;num=0;
                }
            }
        }
        printf("case #%d:\n%d\n",m,max);
        m++;
    }
}
