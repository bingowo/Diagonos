#include<stdio.h>
int change(int N,int R)
{
    int a,i=0;
    int re[30];
    if(N<0){
        printf("-");
        N=-N;
    }
    while(N!=0){
        a=N%R;
        N/=R;
        re[i]=a;
        i++;
    }
    i--;
    for(;i>=0;i--){
        if(re[i]>9) printf("%c",re[i]+55);
        else printf("%d",re[i]);
    }
    return 0;
}
int main()
{
    char s[60];
    int T;
    int N[20],R[20];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d %d",&N[i],&R[i]);
    }
    for(int j=0;j<T;j++){
        change(N[j],R[j]);
        printf("\n");
    }
    return 0;
}