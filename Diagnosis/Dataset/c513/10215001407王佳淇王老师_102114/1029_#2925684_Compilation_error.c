#include<iostream>
#include<algorithm>
#include<string.h>
#include <ctype.h>
#include <cmath>
void swap(char *a,char*b){
	char ch;
	ch=*a;
	*a=*b;
	*b=ch;
	
}
int main() {
    int T;
    scanf("%d",&T);
   getchar();
    char str[201];
    for (int i = 0; i < T; i++) {
        scanf("%s",str);
        int len = strlen(str);
        for (int j=0; j <len - 1;j++)
            for (int k = j + 1; k <len; k++)
                if (isalpha(str[j]) && isalpha(str[k])&&str[j]>str[k]) swap(&str[j],&str[k]);
        printf("case #%d:\n",i);
		printf("%s",str);
    }
    return 0;
}