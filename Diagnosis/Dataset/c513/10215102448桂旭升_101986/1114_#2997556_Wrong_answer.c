#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
#include<ctype.h>
void readpoly(char *p, int* co){
    while (*p){
        int sign=1,c=0,d=0;
        if (*p=='+' ) p++; 
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
	int m, n, i, j, sub = 0;
    char s[17];
    int d[3] = {0};
    scanf("%s", s);
    readpoly(s, d);
    printf("%d %d %d\n", (int)sqrt((double)d[2]), d[1], d[0]);
    if(d[1] == 0){
        if(d[0] > 0)printf("No Answer!");
        else printf("%d %d %d %d", (int)sqrt((double)d[2]), -(int)sqrt(-(double)d[0]), (int)sqrt((double)d[2]), (int)sqrt(-(double)d[0]));
    }
    else if(d[0] == 0){
        if(d[2] > 1)printf("%d %d %d %d", 1, 0, d[2], d[1]);
        else{
            if(d[1]>0)printf("%d %d %d %d", 1, 0, 1, d[1]);
            else printf("%d %d %d %d", 1, d[1], 1, 0);
        }
    }
    else{

    }
    system("pause");
	return 0;
}