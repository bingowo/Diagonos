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
    int k, t, i, flag, ans = 0, d, len, a = 0, cnt;
    char s[200], str[20]; char *p; char res[10];
    scanf("%s", s); 
    if(s[1] == 'G')printf("%s", s);
    system("pause");
	return 0;
}