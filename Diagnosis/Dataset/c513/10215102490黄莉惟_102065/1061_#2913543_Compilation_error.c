#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int number[100];
    int total;
} WORD;
int main(){
    int n,i;
    scanf("%d",&n);
    WORD a[n];
    for(i=0;i<n;i++){
        scanf("%s",a[i].number);
        int a[128];
        for(int i=0;i<128;i++){
            a[i]=-1;
        }
        int R=0;
        char *p=a[i].number;
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
        p=a[i].number;
        while(*p)
            N=N*R+a[*p++];
        a[i].total=N;
        printf("%d",N);
    }
    
}