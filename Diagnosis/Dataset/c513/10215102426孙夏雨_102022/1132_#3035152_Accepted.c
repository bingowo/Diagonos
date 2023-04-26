#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int zhuan(char* ans,int n,int r)
{
    int i=0;
    if(r<10){
        while(n>0){
            ans[i++]=n%r+'0';
            n/=r;
        }
    }
    else{
        while(n>0){
            int yu=n%r;
            if(yu<10){
                ans[i++]=yu+'0';
            }
            else{
                ans[i++]=yu-10+'A';
            }
            n/=r;
        }
    }
    ans[i]=0;
    return i;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int r=0,n=0;
        scanf("%d %d",&n,&r);
        char ans[100]={0};
        printf("case #%d:\n",t);
        if(r==10) {
            int k=0;
            while(n>0){
                k+=n%10;
                n/=10;
            }
            printf("%d\n",k);
        }
        else if(n==0) printf("0\n");
        else{
            int w=zhuan(ans,n,r);
            n=0;
            for(int i=0;i<w;i++){
                if(isdigit(ans[i])) n+=(ans[i]-'0');
                else {
                    n+=(ans[i]-'A'+10);
                }
            }
            int len1=zhuan(ans,n,r);
            for(int i=len1-1;i>=0;i--){
                printf("%c",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}