#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
int d[128] = {0};
int IN(){
    int a;
    char c;
    getchar();
    c = getchar();
    getchar();getchar();
    scanf("%d", &a);
    d[c] = a;
}
int OUT(){
    char s[3] = {0};
    scanf("%s", &s);
    char c = s[0];
    printf("%d\n", d[c]);
    //d['A'] = 0; d['B'] = 0; d['C'] = 0; d['D'] = 0;
}
int main(){
	int i = 0, n, ans = 0;
    char s[5] = {0}, s1[6] = {0};
    while(scanf("%s", &s) != EOF){
        if(strcmp(s, "IN") == 0)IN();
        else if(strcmp(s, "OUT") == 0)OUT();
        else{
            char c1, c2, c3;
            scanf("%s", &s1);
            int len = strlen(s1);
            c1 = s1[0];
            c2 = s1[len - 5];
            c3 = s1[len - 2];
            if(strcmp(s, "MOV") == 0)d[c1] = d[c3];
            else if(strcmp(s, "SUB") == 0)d[c1] = d[c2] - d[c3];
            else if(strcmp(s, "ADD") == 0)d[c1] = d[c2] + d[c3];
            else if(strcmp(s, "DIV") == 0)d[c1] = d[c2] / d[c3];
            else if(strcmp(s, "MUL") == 0)d[c1] = d[c2] * d[c3];
            else if(strcmp(s, "MOD") == 0)d[c1] = d[c2] % d[c3];
            else if(strcmp(s, "AND") == 0)d[c1] = d[c2] & d[c3];
            else if(strcmp(s, "OR") == 0)d[c1] = d[c2] | d[c3];
            else if(strcmp(s, "XOR") == 0)d[c1] = d[c2] ^ d[c3];
            else{
                int a = d[c1];
                d[c1] = d[c3];
                d[c3] = a;
            }
        }
    }
    //system("pause");
	return 0;
} 