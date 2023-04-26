#include<stdio.h>
int main(){
    int T,n,b=0;
    scanf("%d",&T);
    while(T-->0){
        int max=1,ing=1,p,q;
        unsigned int m=1;
        scanf("%d",&n);
        for(int i=32;i>0;i--){
            p=((n&m)==0)?0:1;
            m=m<<1;
            if(m>n)break;
            q=((n&m)==0)?0:1;
            if(p!=q)ing+=1;
            else ing=1;
            max=ing>max?ing:max;
        }
        printf("case #%d:\n%d\n",b++,max);
    }
    return 0;
}
