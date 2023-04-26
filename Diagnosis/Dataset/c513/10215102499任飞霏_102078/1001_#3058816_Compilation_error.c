#include <stdio.h>
#include <stdlib.h>

char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    int n,t;
    int a[30],i=0;
    scanf("%d%d",&n,&t);
    while(n){
        //printf("n%%t %d\n",n%t);
        if(n%t < 0){
            a[i]=n-(n/t+1)*t;
            //printf("a[%d]=%d\n",i,a[i]);
            n = n/t+1;
            //printf("n=%d\n",n);
        }
        else{
            a[i] = (n%t);
            //printf("a[%d]=%d\n",i,a[i]);
            n /= t;
            //printf("n=%d\n",n);
        }
        i++;
    }
    for(int j = i - 1;j >= 0;j--){
        printf("%c",table[a[j]]);
    }
    if(n==0)printf("0");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number,n,r;
    char table[] = {"0123456789ABCDEFGHIJKLMN"};
    scanf("%d",&number);
    for(int i=0;i<number;i++){
        scanf("%d%d",&n,&r);
        if(n<0){
            n=-n;
            printf("-");
        }
        char a[30]={0};
        int j=0;
        while(n){
            a[j++]=table[n%r];
            n/=r;
        }
        for(int k=j-1;k>=0;k--){
            printf("%c",a[k]);
        }
        printf("\n");
    }
    return 0;
}
