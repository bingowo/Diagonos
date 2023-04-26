#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define M 1002
//0 -1
//i -i
//bi -bi
//a+i a-i
//a+bi a-bi //-a+bi -a-bi

typedef struct{
    int rez[M];
    int imz[M];
    int lr;
    int li;
    int fr;
    int fi;
}COM;

typedef struct{
    int v[M];
    int len;
    int flag;
}BIG;


COM put(char *s, int len){  //convert s into com
    COM res = {{0},{0},0,0,0,0};

}


COM mul_C(COM a, COM b){
    COM res = {{0},{0},0,0,0,0};
}

COM cal(COM a, int n){  //cal a^n
    COM res = {{0},{0},0,0,0,0};
    if(a.fi == 0 && a.fr == 0) return res;
    if(n == 0) {
        res.rez[res.lr++] = 1;
        res.fr = 1;
        return res;
    }
    if(n == 1) return a;

    res = cal(a,n/2);
    res = mul_C(res,res);
    if(n%2 == 1) res = mul_C(res,a);

    return res;
}

void output(COM res){
    if(res.fi == 0){    //0 -1
        if(res.fr == -1) printf("-");
        for(int i = res.lr -1; i >= 0; i--) printf("%d",res.rez[i]);
        return;
    }
    if(res.fr == 0 && res.li == 1){ //i -i
        if(res.fi == -1) printf("-");
        printf("i");
        return;
    }
    if(res.fr == 0){    //bi -bi
        if(res.fi == -1) printf("-");

        for(int i = res.li - 1; i >= 0; i--) printf("%d",res.rez[i]);
        printf("i");
        return;
    }
    if(res.li == 1){    //a+i a-i
        if(res.fr == -1) printf("-");
        for(int i = res.lr -1; i >= 0; i--) printf("%d",res.rez[i]);

        if(res.fi == -1) printf("-");
        else printf("+");
        printf("i");
        return;
    }
    else{   //a+bi a-bi //-a+bi -a-bi
        if(res.fr == -1) printf("-");
        for(int i = res.lr -1; i >= 0; i--) printf("%d",res.rez[i]);

        if(res.fi == -1) printf("-");
        else printf("+");
        for(int i = res.li - 1; i >= 0; i--) printf("%d",res.rez[i]);
        printf("i");
        return;
    }
}

int main()
{
    COM com = {{0},{0},0,0,0,0}, res = {{0},{0},0,0,0,0};
    char s[2*M+2] = {'\0'};
    int n;
    scanf("%s%d",s,&n);

    com = put(s, strlen(s));
    res = cal(com,n);

    output(res);
    return 0;
}
