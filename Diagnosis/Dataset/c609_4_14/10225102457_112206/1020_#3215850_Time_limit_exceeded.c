#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    char str[32];
    int num;
    int state;
}DATA;
int cmp(const void *p1,const void *p2);

int main(void)
{
    DATA input[100];
    int i = 0;

    while(scanf("%s",input[i].str) != EOF){
        input[i].state = 0;
        input[i].num = 0;
        for(char *test = input[i].str; *test != '\0'; test++){
            if(isdigit(*test)){
                for(; isdigit(*test); test++){
                    input[i].num = input[i].num*10 + (*test - '0');
                }
                input[i].state = 1;
            }
            else if(*test == '-'){
                for(; isdigit(*test); test++){
                    input[i].num = input[i].num*10 - (*test - '0');
                }
                input[i].state = 1;
            }
            if(input[i].state == 1) test--;
        }
        i++;
    }

    qsort(input,i,sizeof(DATA),cmp);

    for(int v = 0; v < i; v++){
        printf("%s ",input[v].str);
    }

    return 0;
}

int cmp(const void *p1,const void *p2)
{
    DATA a = *(DATA*)p1;
    DATA b = *(DATA*)p2;

    if(a.state == 0 && b.state == 0) return strcmp(a.str, b.str);
    else if(a.state != b.state) return a.state - b.state;
    else return a.num > b.num?1:a.num < b.num?-1:0;
}