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
    int k, t, i, flag, ans = 0, d, len, a = 0;
    char s[200], str[20]; char *p;
    while(1){
        scanf("%s", s); p = s; p++; ans = *p++; k = 0; flag = 0;
        if(strcmp(s, "END") == 0)break;
        while(*p != '*'){
            //printf("%d %c\n", ans, *p);
            if(*p == ',' || *p == '.')flag++;
            ans ^= *p; p++;
            if(flag == 1)str[k++] = *p;
        }
        p++; str[k-1] = '\0'; //printf("%d, %s\n", ans, str);
        sscanf(p, "%x", &d); len = strlen(str);//printf("%d\n", d);
        if(ans == d){
            for(i = 0; i < 2; i++){
                a = a*10+str[i]-'0';
            }
            a += 8; a %= 24;
            printf("%d:", a);
            a = 0;
            for(i = 2; i < 4; i++){
                a = a*10+str[i]-'0';
            }
            printf("%d:", a); a = 0; 
            for(i = 4; i < 6; i++){
                a = a*10+str[i]-'0';
            }
            printf("%d\n", a);
        }
    }
    
    
    system("pause");
	return 0;
}