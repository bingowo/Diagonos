#include<stdio.h>
#include<string.h>
#define ll long long

int myindex = 0;
char res[100] = {0};

void func(ll x, ll y){
    if (x%2 != 0) {
        ll E = x-1,  W = x+1;
        E/=2, W/=2, y/=2;
        if (y==0 && E==0){
            myindex++;
            strcat(res, "E");
            return;
        }
        else if (y==0 && W==0){
            myindex++;
            strcat(res, "W");
            return;
        }
        if ((E+y)%2 != 0){
            myindex++;
            strcat(res, "E");
            func(E, y);
        }
        else if((W+y)%2 != 0){
            myindex++;
            strcat(res, "W");
            func(W, y);
        }
    }
    else if (y%2 != 0)
    {
        
        ll N = y-1, S = y+1;
        S /= 2, N /= 2, x /= 2;
        if(x==0 && N==0){
            myindex++;
            strcat(res, "N");
            return;
        }
        if(x == 0 && S == 0)
        {
            myindex++;
            strcat(res, "S");
            return;
        }
        if((x + S) % 2 != 0)
        {
            myindex++;
            strcat(res, "S");
            func(x,S);
        }
        else if((x + N) % 2 != 0)
        {
            myindex++;
            strcat(res, "N");
            func(x,N);
        }
    }
}

int main(){
    ll x, y;
    scanf("%lld %lld", &x, &y);
    if (x==0 && y==0) printf("0\n");
    else if ((x+y)%2==0) printf("-1\n");
    else {
        func(x, y);
        printf("%d\n%s\n", myindex, res);
    }
    return 0;
}