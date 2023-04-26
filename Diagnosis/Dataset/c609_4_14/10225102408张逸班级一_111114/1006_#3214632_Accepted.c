#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        char s[61];scanf("%s",s);
        int a[123];for(int i=0;i<123;i++) a[i]=-1;
        int R=0;
        char*p=s;
        a[*p]=1;
        while(*++p){
            if(a[*p]==-1){
                a[*p]=R;
                R=R?R+1:2;
            }
        }
        if (R<2) R=2;
        long long N=0;
        p=s;
        while(*p){
            N=N*R+a[*p++];

        }
        printf("case #%d:\n%lld\n",cas,N);
    }
    return 0;
}