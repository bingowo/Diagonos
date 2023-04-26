#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void * a, const void * b);
char str[27];
int main() {
    while(scanf("%s",str) != EOF)
    {
    char tem[101];
    char c = '1';
    while(c != '\n'){
        scanf("%s",tem);
        qsort(tem,sizeof(tem),1,cmp);
        printf("%s ",tem);
        scanf("%c",&c);
    }
    printf("\n");
    }
	return 0;
}
int cmp(const void * a, const void * b){
    char c1 = *(char*) a;
    int n1 = 0;
    int n2 = 0;
    char c2 = *(char*) b;
    for(int i = 0;i < 27;i++){
        if(str[i] == c1 || c1 - 32 == str[i]) {n1 = i;break;}
    }
     for(int i = 0;i < 27;i++){
        if(str[i] == c2 || c2 - 32 == str[i]) {n2 = i;break;}
    }
    return n1 - n2;
}

