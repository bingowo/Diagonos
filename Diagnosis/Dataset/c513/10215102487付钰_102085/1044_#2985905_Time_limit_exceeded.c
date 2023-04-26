#include<stdio.h>
int main(){
    char a, b, c;
    int ctr = 0;
    do{
        a = getchar();
        if(a == EOF)break;
        //b = getchar();
        //if(b == EOF)break;
        //c = getchar();
        //if(c == EOF)break;
        if(a == '0' && b == 'x' && (c >= '0' && c <= '9' || c >= 'a' && c <= 'f')){
            ungetc(c, stdin);
            ungetc(b, stdin);
            ungetc(a, stdin);
            if(ctr++)printf(" ");
            unsigned int a;
            scanf("%x", &a);
            printf("%u", a);
        }
        else{
            ungetc(c, stdin);
            ungetc(b, stdin);
        }
    }while(1);
    if(!ctr)printf("-1");
    printf("\n");
    return 0;
}