#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k=0,n=0;
    scanf("%d %d",&k,&n);
    if(n<=2) printf("%d\n",n-1);
    else{
        int shu[100];
        shu[0]=0;
        shu[1]=1;
        int all=1;
        for(int i=2;i<n;i++){
            if(i<k){
                shu[i]=all;
                all+=shu[i];
            }
            else {
                shu[i]=all;
                all-=shu[i-k];
                all+=shu[i];
            }
        }
        printf("%d\n",shu[n-1]);
    }
    return 0;
}
