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
        if(strcmp(s, "MUL") == 0)MUL();
        if(strcmp(s, "MOV") == 0)MOV();
        if(strcmp(s, "SUB") == 0)SUB();
        if(strcmp(s, "ADD") == 0)ADD();
        if(strcmp(s, "DIV") == 0)DIV();
        if(strcmp(s, "OUT") == 0)OUT();
    }
    system("pause");
	return 0;
} 