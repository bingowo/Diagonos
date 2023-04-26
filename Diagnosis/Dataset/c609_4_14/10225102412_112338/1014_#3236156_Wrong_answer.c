#include <stdio.h>
int main()
{
    int A,B;int s[100]={0};
    scanf("%d %d",&A,&B);
    int i,j,n;
    n = 0;i = 0;
    while (B>1){
        B = B/3;
        n = n+1;
    }
    while (A>0){
        s[i] = A%3;
        A = A/3;
        i++;
    }
    for (j=0;j<i;j++){
        s[j] = s[j]+1;
        if (s[j]>=3){
            s[j] -= 3;
            s[j+1] = s[j+1]+1;
        }
    }
    int len;
    if (s[j]==1){
        len = j+1;
    }
    else{
        len = j;
    }
    for (j=0;j<i;j++){
        s[j] = s[j]-1;
        if (s[j]==-1){
            s[j] = 2;
        }
    }
    int m;
    int a=n;
    if (n+1>len){
        m = n+1;
    }
    else{
        m = len;
        for (i=0;i<=a;i++){
            if (s[i]==0){
                for (j=0;j<m-1;j++){
                    s[j] = s[j+1];
                }
                m--;
                n--;
            }
            else{
                break;
            }
        }
    }
    for (i=0;i<m;i++){
        if (i==m-n && i>0){
            printf(".");
        }
        printf("%d",s[m-i-1]);
    }
    return 0;
}
