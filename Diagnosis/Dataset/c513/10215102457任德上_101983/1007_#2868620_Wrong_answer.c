#include<stdio.h>
int main(){
    int T,n,q=0;
    scanf("%d",&T);
    while(T-->0){
        int max=0,ing=0,p,q;
        scanf("%d",&n);
        for(int i=32,m=1;i>1;i--){
            p=((n&m)==0)?0:1;
            m=m<<1;
            q=((n&m)==0)?0:1;
            if(p!=q)ing+=1;
            else ing=0;
            max=ing>=max?ing:max;
        }
        printf("case #%d:\n%d\n",q,max);
        q++;
    }
    return 0;
}
