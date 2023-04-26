#include <stdio.h>
int main()
{
    int A,B,s[100];
    scanf("%d %d",A,B);
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
    int len=sizeof(s)/sizeof(1);
    for (i=0;i<len;i++){
        s[i] = s[len-1-i]-1;
        if (s[i]=-1){
            s[i] = 2;
        }
    }
    for (i=0;i<len;i++){
        if (i==len-n){
            printf(".");
        }
        printf("%d",s[i]);
    }
    return 0;
}