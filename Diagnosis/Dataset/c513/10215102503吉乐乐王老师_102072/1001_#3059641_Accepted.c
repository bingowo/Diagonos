#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,r;
        int sign=1;
        scanf("%d%d",&n,&r);
        if(n<0){
            n=-n;
            sign=-1;
        }
        char output[100];
        int cnt=0;
        do{
            int temp=n%r;
            n/=r;
            if(temp<10)output[cnt++]=temp+'0';
            else output[cnt++]=temp-10+'A';
        }while(n);
        if(sign==-1)putchar('-');
        for(int i=cnt-1;i>=0;i--){
            printf("%c",output[i]);
        }
        putchar('\n');
    }
}
