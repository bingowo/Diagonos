#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char c;
int a[1005],t;
int n=1000;
int minn=1001,maxx=0;

int main(){
    scanf("%c",&c);
    while(scanf("%d",&t)!=EOF){
        a[t]++;
        if(t<minn) minn=t;
        if(t>maxx) maxx=t;
    }

    if(c=='A'){
        for(int i=1;i<=n;i++){
            if(a[i]){
                printf("%d",i);
                if(i<maxx) printf(" ");
            }
        }
    }
    else{
        for(int i=n;i>=1;i--){
            if(a[i]){
                printf("%d",i);
                if(i>minn) printf(" ");
            }
        }
    }

    return 0;
}
