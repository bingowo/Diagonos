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
int SUB(){
    char c1, c2;
    getchar();
    c1 = getchar();
    getchar();getchar();
    c2 = getchar();
    d[c1] -= d[c2];
    getchar();getchar();
}
int ADD(){
    char c1, c2;
    getchar();
    c1 = getchar();
    getchar();getchar();
    c2 = getchar();
    d[c1] += d[c2];
    getchar();getchar();
}
int DIV(){
    char c1, c2;
    getchar();
    c1 = getchar();
    getchar();getchar();
    c2 = getchar();
    d[c1] /= d[c2];
    getchar();getchar();
}
int MOV(){
    char c1, c2;
    getchar();
    c1 = getchar();
    getchar();getchar();
    c2 = getchar();
    d[c1] = d[c2];
    getchar();getchar();
}
int OUT(){
    getchar();
    printf("%d", d[getchar()]);
    d['A'] = 0; d['B'] = 0; d['C'] = 0; d['D'] = 0;
}
int MUL(){
    char c1, c2;
    getchar();
    c1 = getchar();
    getchar();getchar();
    c2 = getchar();
    d[c1] *= d[c2];
    getchar();getchar();
}
int main(){

	int i = 0, n, ans = 0;
    char s[5] = {0};
    while(scanf("%s", &s) != EOF){
        if(strcmp(s, "IN") == 0)IN();
        else if(strcmp(s, "OUT") == 0)OUT();
        else{
            char c1, c2;
            getchar();
            c1 = getchar();
            getchar();getchar();
            c2 = getchar();
            if(strcmp(s, "MOV") == 0)d[c1] = d[c2];
            else if(strcmp(s, "SUB") == 0)d[c1] -= d[c2];
            else if(strcmp(s, "ADD") == 0)d[c1] += d[c2];
            else if(strcmp(s, "DIV") == 0)d[c1] /= d[c2];
            else if(strcmp(s, "MUL") == 0)d[c1] *= d[c2];
            getchar();getchar();
        }
    }
    system("pause");
	return 0;
} 