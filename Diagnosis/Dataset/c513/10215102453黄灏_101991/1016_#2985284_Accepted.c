#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,r;
    int m,i=0;
    char ans[60];
    scanf("%d %d",&n,&r);
    if(n==0) printf("0");
    else{
        char table[]="0123456789ABCDEFGHIJK";
        while (n){
            m=n%r;
            n=n/r;
            if(m<0){
                m=m-r;n++;
            }
            ans[i++] = table[m];
        }
        for(int k=i-1;k>=0;k--) printf("%c",ans[k]);
    }
    return 0;
}
