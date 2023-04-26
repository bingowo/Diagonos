#include<stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++){
        char s[61];
        scanf("%s",s);
        int a[128];
        for(int i=0;i<128;i++)
            a[i]=-1;
        int digit=0,n=1,i;
        char *p=s;
        a[*p]=1;
        while(*++p){
            if(a[*p]==-1){
                a[*p]=digit;
                digit=digit?digit+1:2;
                n++;
            }
        if(n<2) n=2;
        }
        printf("case #%d:\n",k);
        printf("%d",n);

    }
    return 0;
}