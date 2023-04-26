#include <stdio.h>

int main(){
    int T;
    char str[100];
    scanf("%d\n",&T);
    int n=0,a[128];
    a['-']=-1;
    a['0']=0;
    a['1']=1;
    while(scanf("%s\n",&str)!=EOF){
        int t=0;
        char *p=str;
        while(*p){
            t=t*3+a[*p++];
        }
        printf("case #%d:\n%d\n",n++,t);
    }
    return 0;
}