#include <stdio.h>
#include <stdlib.h>
const char s[]="0123456789ABCDEFGHIJK";

int main(){
    int T,Q,K=0;
    char *ans;
    ans = (char*)malloc(sizeof(char)*30000);
    scanf("%d %d", &T,&Q);
    while(T!=0){
        if(T%Q>=0){
            ans[K++]=s[T%Q];
            T/=Q;
        }
        else{
            ans[K++]=s[T%Q-Q];
            T=T/Q+1;
        }
    }
    if (K!=0)
    {
        for (int i=K-1;i>=0;i--) printf("%c",ans[i]);
    }
    else printf ("%d",0);
    free(ans);
    return 0;
}
