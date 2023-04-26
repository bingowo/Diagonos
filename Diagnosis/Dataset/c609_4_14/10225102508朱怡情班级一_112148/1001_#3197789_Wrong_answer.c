#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    char key[40]={"0123456789ABCDEFGHJKLMNOPQRSTUVWXYZ"};
    scanf("%d",&t);
    while(t--){
        int n,r;
        scanf("%d %d",&n,&r);
        char answer[100];
        int pos=0;
        if(n<0)printf("-");
        n=abs(n);
        while(n>0){
            answer[pos]=key[n%r];
            pos++;
            n/=r;
        }
        for(int j=pos-1;j>=0;j--){
            printf("%c",answer[j]);
        }
        printf("\n");
    }
    return 0;
}