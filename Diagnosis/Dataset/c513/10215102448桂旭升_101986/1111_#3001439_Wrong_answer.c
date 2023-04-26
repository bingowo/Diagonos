#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void readpoly(char *p, int* co){
    while (*p){
        int sign=1,c=0,d=0;
        if(*p == 'f'||*p == '('||*p == ')'||*p == '='||(*p == 'x' && *(p+1) == ')'))p++;
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
int main(){
	int i, j, d, flag, t, k;
    char s[20], ans[41][41];
    int a[4];
    scanf("%d", &t);
    while(scanf("%s", s) != EOF){
        readpoly(s, a);
        for(j = 0; j < 41; j++){
            for(k = 0; k < 41; k++){
                if(k == 20 && j != 20)ans[j][k] = '|';
                else if(k != 20 && j == 20)ans[j][k] = '-';
                else ans[j][k] = '.';
            }
        }
        ans[20][20] = '+'; ans[0][20] = '^'; ans[20][40] = '>';
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