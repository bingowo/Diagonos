#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<math.h>
void readpoly(char *p, int* co){
    int flag = 1;
    while (*p){
        int sign=1,c=0;
        if (*p=='='){
            p++; flag = -1;
        }
        if (*p=='+') p++; 
        else if (*p=='-') sign=-1,p++;
        while (isdigit(*p)){
            c=c*10+*p-'0'; p++;
        }
        if (!isalpha(*p)) { co[0]+=c*sign*flag;continue;}
        else p++;
        if (c==0) c=1;
        co[1]+=c*sign*flag;//printf("%d\n", c);
    }
}
int main(){
    int k, t, i, flag = 0;
    int a[2] = {0, 0}; char s[81], c;
    scanf("%s", s);
    readpoly(s, a);
    for(i = 0; i < strlen(s); i++){
        if(isalpha(s[i])){
            c = s[i];break;
        }
    }
    double dev1, dev2, ans;
    dev1 = (double)a[0];
    dev2 = (double)a[1];
    ans = dev1/dev2;
    ans *= -1;
    printf("%f %f", dev1, dev2);
    if(ans == 0)printf("%c=0.000", c);
    else printf("%c=%.3f", c, ans);
    system("pause");
	return 0;
}