#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a,b,i,j,k,dot = 0,c = 0;
    scanf("%d %d",&a,&b);
    int d = b;
    while(b - 1){
        dot++;
        b/=3;
    }
    char s[100],res[100];
    for(int t = 0;t < 100; t++)s[t] = 9,res[t] = 0;

    while(a){
            s[c] = (a%3);
            //printf("%d\t",s[c]);
            c++;
            a /= 3;
        }
    //printf("c = %d",c);
    /*
    int o = 0;
    while(s[o] != 9){
        printf("%d\t",s[o]);
        o++;
    }
    */
    int add = 0;
    for(j = 0;j < c;j++){
        s[j] = s[j] + 1 + add;
        add = 0;
        if(s[j] >= 3){
            add++;
            s[j] = s[j] - 3;
        }
        //printf("%d\t",s[j]);
    }
    if(add == 1){s[j] = 1;}
    //printf("j = %d,s[j] = %d",j,s[j]);
    //printf("c = %d",c);
    /*
    int o = 0;
    for(i = 0;i < c;i++){
        printf("%d\t",s[i]);
    }
    */
    int n = 0;
    if(s[j] == 1)res[n] = 1;n++;
    for(k = c - 1;k >= 0;k--){
        //printf("s[%d] = %d ",k,s[k]);
        res[n] = s[k] - 1;
        if(res[n] == -1)res[n] = 2;
        printf("%d",res[n]);
        if(c - n - 1 == dot && d != 1)printf(".");
        n++;
    }

    return 0;
}

