#include<stdio.h>
#include<math.h>
int main()
{
    int N,R,x;
    int re[32],i=0;
    scanf("%d %d",&N,&R);
    do{
        x=N/R;
        if(N%R<0){
            x++;
            re[i++]=N-x*R;
        }
        else re[i++]=N%R;
        N=x;
        //printf("%d %d\n",re[i],N);
    }while(N!=0);
    i--;
    for(;i>=0;i--){
        if(re[i]>9) printf("%c",re[i]+55);
        else printf("%d",re[i]);
    }
    return 0;
}
