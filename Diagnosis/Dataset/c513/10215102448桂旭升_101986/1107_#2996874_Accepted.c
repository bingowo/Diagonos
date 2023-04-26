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
    //printf("%d\n", d['B']);
}
int OUT(){
    char s[3] = {0};
    scanf("%s", &s);
    char c = s[0];
    printf("%d\n", d[c]);
    //d['A'] = 0; d['B'] = 0; d['C'] = 0; d['D'] = 0;
}
int main(){
	int i = 0, x, t, j, k, m, n;
    int a[3][3];
    scanf("%d", &t);
    for(; i < t; i++){
        for(j = 0; j < 3; j++){
            for(k = 0; k < 3; k++){
                a[j][k] = 1;
            }
        }
        for(j = 0; j < 3; j++){
            for(k = 0; k < 3; k++){
                scanf("%d", &x);
                if(x%2){
                    for(m = -1; m < 2; m++){
                        if(j + m < 3 && j + m > -1)a[j+m][k] = !a[j+m][k];
                    }
                    for(n = -1; n < 2; n+=2){
                        if(k + n < 3 && k + n > -1)a[j][k+n] = !a[j][k+n];
                    }
                }
            }
        }
        printf("case #%d:\n", i);
        for(j = 0; j < 3; j++){
            for(k = 0; k < 3; k++){
                printf("%d", a[j][k]);
                if(k != 2)printf(" ");
            }printf("\n");
        }
        
    }
    system("pause");
	return 0;
} 