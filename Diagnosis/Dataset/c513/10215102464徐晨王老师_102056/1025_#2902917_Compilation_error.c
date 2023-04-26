#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char s[21];
    int number;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        char q[27];
        struct data p[n];
        for(int j=0;j<n;j++){
            scanf("%s",p[j].s);
            p[j].number=0;
            int len=strlen(p[j].s);
            for(int k=0;k<len;k++){
                if(q[p[j].s[k]-65]!=1){
                    p[j].number++;
                    q[p[j].s[k]-65]=1;
                }
            }
        }
        qsort()
    }
    return 0;
}