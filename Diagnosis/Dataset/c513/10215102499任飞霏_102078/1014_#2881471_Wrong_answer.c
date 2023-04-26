#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a,b,j,k,dot = 0,c = 0;
    int A = a;
    scanf("%d %d",&a,&b);
    //int d = b;
    while(b - 1){
        dot++;
        b/=3;
    }
    char s[100],res[100];
    for(int t = 0;t < 100; t++)s[t] = 9,res[t] = 9;

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
    int n = 0;
    if(add == 1){res[n] = 1;n++;}
    //printf("%d",res[n-1]);
    for(k = c - 1;k >= 0;k--){
        //printf("s[%d] = %d ",k,s[k]);
        res[n] = s[k] - 1;
        if(res[n] == -1)res[n] = 2;
        //printf("%d",res[n]);
        //if(c - n - 1 == dot && d != 1)printf(".");
        n++;
    }
    if(add == 1)c++;
    /*
    while(res[m] != 9){
        printf("%d",res[m]);
        m++;
    }
    */
    if(A == 0)printf("0");
    else if(dot >= c){
        printf("0.");
        int zero = dot - c;
        while(zero--){
            printf("0");
        }
        for(int i = c;i > dot - c;i--){
            if(res[i] == 0)c--;
            else
                break;
        }
        for(int i = 0;i < c;i++){
            printf("%d",res[i]);
        }

    }
    else{
        int lx = c;
        for(int i = c - 1;i > c - dot - 1;i--){
            if(res[i] == 0)c--;
            else
                break;
        }
        for(int i = 0;i < lx - dot;i++){
            printf("%d",res[i]);
        }
        if(lx - dot < c)printf(".");
        for(int i = lx - dot;i < c;i++){
            printf("%d",res[i]);
        }
    }




    return 0;
}
