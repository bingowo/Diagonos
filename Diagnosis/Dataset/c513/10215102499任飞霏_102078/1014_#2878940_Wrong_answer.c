#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a,b,i,j,k,dot = 0,c = 0;
    scanf("%d %d",&a,&b);
    while(b - 1){
        dot++;
        b/=3;
    }
    char s[100],res[100];
    for(int t = 0;t < 100; t++)s[t] = 9,res[t] = 0;

    while(a){
            s[c] = (a%3);
            c++;
            a /= 3;
        }
    /*
    int o = 0;
    while(s[o] != 9){
        printf("%d\t",s[o]);
        o++;
    }
    */
    for(j = 0;j < c;j++){
        s[j] = s[j] + 1;
        if(s[j] >= 3){
            s[j] = s[j] - 3;
            s[j + 1] = s[j + 1] + 1;
        }
        //printf("%d\t",s[j]);
    }
    /*
    int o = 0;
    while(s[o] != 0){
        printf("%d",s[o]);
        o++;
    }
    */
    int n = 0;
    for(k = c - 1;k >= 0;k--){
        //printf("s[%d] = %d ",k,s[k]);
        res[n] = s[k] - 1;
        if(res[n] == -1)res[n] = 2;
        printf("%d",res[n]);
        if(c - n - 1 == dot)printf(".");
        n++;
    }
    /*
    int o = 0;
    while(res[o] != 0){
        printf("%d",res[o]);
        o++;
    }

    for(int m = 0;m < c;m++){
        printf("%d",res[m]);
        if(strlen(res) - m - 1 == dot)printf('.');
    }
    */
    return 0;
}

