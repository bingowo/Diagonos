#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char number[100];
    int total;
} WORD;
int main(){
    int n,i;
    scanf("%d",&n);
    WORD s[n];
    for(i=0;i<n;i++){
        scanf("%s",s[i].number);
        int a[128];
        for(int i=0;i<128;i++){
            a[i]=-1;
        }
        int R=0;
        char *p=s[i].number;
        a[*p]=1;
        while(*++p){
            if(a[*p]==-1){
                a[*p]=R;
                R=R?R+1:2;
            }
        }
        if(R<2){
            R=2;
        }
        long long int N=0;
        p=s[i].number;
        while(*p)
            N=N*R+a[*p++];
        s[i].total=N;
        printf("%lld",N);
    }
    
}