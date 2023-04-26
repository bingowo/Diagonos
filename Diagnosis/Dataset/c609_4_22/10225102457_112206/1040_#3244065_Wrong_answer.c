#include <stdio.h>
#include<ctype.h>
#include<stdio.h>
#include <string.h>

int main(void)
{
    while(1){
        int out[101] = {0};
        int first[51] = {0};
        char A;
        int i = 0;
        A = getchar();
        while(A != ' '){
            i = 1;
            //printf("**%c\n",A);
            int v = 0;
            if(A == 'x'){
                A = getchar();
            }
            else if(A == '-'){
                i = 0;
                while(isdigit(A = getchar()) ){
                    i = i*10 - A + '0';
                }
            }
            else if(A == '+'){
                i = 0;
                while(isdigit(A = getchar()) ){
                    i = i*10 + A - '0';
                }
            }
            else{
                i = A - '0';
                while(isdigit(A = getchar()) ){
                    i = i*10 + A - '0';
                }
            }

            if(A == 'x') A = getchar();
            if(A == ' '){
                first[0] = i;
                v = 0;
            }
            else if(A == '^'){
                while(isdigit(A = getchar()) ){
                    v = v*10 + A - '0';
                }
            }
            else v = 1;

            first[v] = i;
        }

        /*for(int z = 0; z < 51; z++){
            if(first[z] != 0) printf("%d,%d ",first[z],z);
        }*/

        i = 0;
        A = getchar();
        while(A != '\n'){
            i = 1;
            //printf("__%c\n",A);
            int v = 0;
            if(A == 'x'){
                A = getchar();
            }
            else if(A == '-'){
                i = 0;
                while(isdigit(A = getchar()) ){
                    i = i*10 - A + '0';
                }
            }
            else if(A == '+'){
                i = 0;
                while(isdigit(A = getchar()) ){
                    i = i*10 + A - '0';
                }
            }
            else{
                i = A - '0';
                while(isdigit(A = getchar()) ){
                    i = i*10 + A - '0';
                }
            }
            //printf("__%d\n",i);

            if(A == 'x') A = getchar();
            if(A == '\n'){
                v = 0;
            }
            else if(A == '^'){
                while(isdigit(A = getchar()) ){
                    v = v*10 + A - '0';
                }
            }
            else v = 1;

            for(int z = 0; z < 51; z++){
                if(first[z] != 0){
                    out[z+v] = out[z+v] + i*first[z];
                    //printf("%d,%d\n",i,first[z]);
                }
            }
        }

        for(int z = 100; z >= 0; z--){
            if(out[z] != 0) printf("%d ",out[z]);
        }
        putchar('\n');

        if((A = getchar()) != EOF) ungetc(A,stdin);
        else break;
    }

    return 0;
}