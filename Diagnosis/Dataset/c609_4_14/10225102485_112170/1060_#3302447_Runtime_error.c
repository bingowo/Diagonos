#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char A[100005],ans[100005];
int main(){
    scanf("%s",A);
    int I=strlen(A),difpos=0,cnt=0;
    for(int i=0;i<I;i++){
        while(difpos<I&&A[i]==A[difpos])difpos++;
        while(difpos<I&&A[i]<A[difpos])ans[cnt++]=A[i];
        ans[cnt++]=A[i];
    }
    ans[cnt]='\0';
    printf("%s",ans);
    return 0;
}
