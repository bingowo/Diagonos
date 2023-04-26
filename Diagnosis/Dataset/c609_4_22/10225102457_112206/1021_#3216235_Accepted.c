#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int cmp(const void *p1,const void *p2);

char dic[27];

int main(void)
{
    while(scanf("%s",dic) != EOF){
        char input[101][22];
        int n = 0;
        do{
            scanf("%s",input[n]);
            n++;
        }while(getchar() != '\n');

        qsort(input,n,sizeof(input[0]),cmp);

        printf("%s",input[0]);
        for(int i = 1; i < n; i++){
            printf(" %s",input[i]);
        }
        putchar('\n');
    }

    return 0;
}


int cmp(const void *p1,const void *p2)
{
    char* a = (char*)p1;
    char* b = (char*)p2;
    while(*a != '\0'&&*b != '\0'){
        int a1 = strchr(dic,toupper(*a)) - dic;
        int b1 = strchr(dic,toupper(*b)) - dic;
        if(a1 != b1) return a1-b1;
        a++,b++;
    }
    if(*a != *b) return *a - *b;
    else return 0;
}
