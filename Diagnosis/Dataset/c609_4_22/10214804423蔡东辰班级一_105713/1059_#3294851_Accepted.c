#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*a, const void*b){
    char* x = *((char**)a);
    char* y = *((char**)b);
    int sign_x = (x[0]=='-')?-1 : 1;
    int sign_y = (y[0]=='-')?-1 : 1;
    if(sign_x != sign_y){
        return sign_x - sign_y;
    }
    if(*x == '-' || *x == '+'){ x++;}
    if(*y == '-' || *y == '+'){ y++;}
    char* p1, *p2;
    for(p1 = x; *p1 && *p1!='.'; p1++);
    for(p2 = y; *p2 && *p2!='.'; p2++);
    int len_x = p1 - x;
    int len_y = p2 - y;
    if(len_x != len_y){
        return sign_y * (len_x - len_y);
    }
    return sign_y * strcmp(x, y);
}
int main(){
    int n;
    scanf("%d", &n);
    char** s = (char**)malloc(sizeof(char*) * n);
    for(int i = 0; i<n; i++){
    	s[i] = (char*)malloc(sizeof(char) * 101);
        scanf("%s", s[i]);
        int m = strlen(s[i]);
        s[i][m] = '\0';
    }
    qsort(s, n, sizeof(char*), cmp);
    for(int i = 0; i<n; i++){
        printf("%s\n", s[i]);
    }
    for(int i = 0; i<n; i++){
    	free(s[i]);
	}
	free(s);
    return 0;
}
