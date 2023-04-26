#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 20
void readpoly(char *p, int* co){
    while (*p){
        int sign=1,c=0,d=0;
        if(*p == 'f')p++;
        if(*p == '(')p++;
        if(*p == 'x' && *(p+1) == ')')p++;
        if(*p == ')')p++;
        if (*p=='=') p++; 
        if (*p=='+') p++; 
        else if (*p=='-') sign=-1,p++;
        while (isdigit(*p)){
            c=c*10+*p-'0'; p++;
        }
        if (*p!='x') { co[0]=c*sign; return; }
        else p++;
        if (c==0) c=1;
        if (*p=='^') p++;
        while (isdigit(*p)) { d=d*10+*p-'0'; p++; }
        if (d==0) d=1;
        co[d]=c*sign;
    }
}
int they(int a[], int x){
    int ans = 0, temp = 1;
    for(int i = 0; i < 4; i++){
        temp = 1;
        for(int j = 0; j < i; j++){
            temp *= x;
        }
        ans += temp*a[i];
    }
    return ans;
}
int main(){
	int i, j, d, flag, t, k, cnt = 0;
    char s[20], ans[41][41];
    int a[4];
    scanf("%d", &t);
    while(scanf("%s", s) != EOF){
        if(cnt!=0)printf("\n");
        cnt++;
        for(j = 0; j < 4; j++)a[j] = 0;
        readpoly(s, a);//printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
        for(j = 0; j < 41; j++){
            for(k = 0; k < 41; k++){
                if(k == 20 && j != 20)ans[j][k] = '|';
                else if(k != 20 && j == 20)ans[j][k] = '-';
                else ans[j][k] = '.';
            }
        }
        ans[20][20] = '+'; ans[0][20] = '^'; ans[20][40] = '>';
        //printf("%d\n", they(a, 2));
        for(int x = -20; x <= 20; x++){
            int temp = they(a, x);
            if(temp >= -20 && temp <= 20)ans[N-temp][N+x] = '*';
        }
        for(j = 0; j < 41; j++){
            for(k = 0; k < 41; k++){
                printf("%c", ans[j][k]);
            }
            printf("\n");
        }
        
    }
    system("pause");
	return 0;
}