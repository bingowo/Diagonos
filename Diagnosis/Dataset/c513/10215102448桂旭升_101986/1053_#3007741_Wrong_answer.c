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
    while(1){
        ans = 0;
        scanf("%s", s); p = s; p++; ans = *p++; k = 0; flag = 0; a = 0, cnt = 0;
        if(strcmp(s, "END") == 0){
            printf("%s\n", res);break;
        }
        while(*p != '*'){
            if(*p == 'A' && *(p+1) != '*')cnt++;
            if(*p == ',' || *p == '.')flag++;
            ans ^= *p; p++;
            if(flag == 1)str[k++] = *p;
        }
        p++; str[k-1] = '\0'; 
        sscanf(p, "%x", &d); len = strlen(str);//printf("%d %d %s\n", d, ans, str);
        if(ans == d && cnt == 1 && s[1] == 'G'){
            for(i = 0; i < 2; i++){
                a = a*10+str[i]-'0';
            }
            a += 8; a %= 24;
            if(a < 10){
                res[0] = '0'; res[1] = a + '0';
            }
            else{
                res[0] = a/10 + '0'; res[1] = a%10 + '0';
            }
            res[2] = ':'; res[3] = str[2]; res[4] = str[3]; res[5] = ':'; res[6] = str[4]; res[7] = str[5]; res[8] = '\0';
        }
    }
    system("pause");
	return 0;
}