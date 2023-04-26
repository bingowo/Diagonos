#include <stdio.h>
#include <stdlib.h>

int mod(int n,int k){
    if(n%k<0)
        return n-(n/k+1)*k;
    else
        return n%k;
}
int main()
{
    char s[]="0123456789ABCDEFGHIJKL";
    char ans[100];
    int N,R,x,i=0;
    scanf("%d%d",&N,&R);
    while(N){
        x=mod(N,R);
        ans[i++]=s[x];
        if(N%R<0)
            N=N/R+1;
        else
            N/=R;
    }
    for(int j=i;j>=0;j--)
        printf("%c",ans[j]);
    return 0;
}
