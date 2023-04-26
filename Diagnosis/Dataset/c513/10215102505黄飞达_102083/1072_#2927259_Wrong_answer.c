#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long

int dire_arr[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};//东西南北
char dire_name[5] = "EWSN";
char res[100] = {0};

int func(int d, ll x, ll y, int index){
    if (x==0 && y==0) return 1;
    else if (index>=41) return 0;
    x += dire_arr[d][0];
    if (x%2==0) x/=2;
    else return 0;
    y += dire_arr[d][1];
    if (y%2==0) y/=2;
    else return 0;

    int flag=0;
    int temp = 0;
    if (d!=1&&func(0,x,y,index+1)) {res[index]=dire_name[d];flag=1;}
    else if (d!=0&&func(1,x,y,index+1)) {res[index]=dire_name[d];flag=1;}
    else if (d!=3&&func(2,x,y,index+1)) {res[index]=dire_name[d];flag=1;}
    else if (d!=2&&func(3,x,y,index+1)) {res[index]=dire_name[d];flag=1;}
    return flag;
}

int main(){
    ll x, y;
    scanf("%lld %lld", &x, &y);
    if ((x+y)%2==0) printf("-1");
    else {
        int index = 0;
        func(0,x,y,index);
        func(1,x,y,index);
        func(2,x,y,index);
        func(3,x,y,index);
        int slen = strlen(res);
        printf("%d\n", slen);
        for (int i=0; i<slen; i++) printf("%c", res[i]);
        printf("\n");        
    }

    return 0;
}