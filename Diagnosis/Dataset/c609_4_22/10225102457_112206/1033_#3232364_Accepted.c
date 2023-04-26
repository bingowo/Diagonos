#include<stdio.h>
#include<string.h>

int main(void)
{
    char *dic ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int T;
    scanf("%d",&T);
    char input[100] = {0};
    for(int i = 0; i < T; i++){
        scanf("%s",input);
        char *read = input;
        char output[135] = {0};
        int z,v;
        int a,b,c,d;
        int l = strlen(input);

        for(z = 0,v = 0; z < l/3; z++,read += 3){
            output[v++] = *(dic+*read/4);
            b = *read%4;
            output[v++] = *(dic+ b*16 + *(read+1)/16);
            c = *(read +1)%16;
            output[v++] = *(dic+c*4 + *(read+2)/64);
            output[v++] = *(dic+*(read+2)%64);
        }

        if(*read == '\0');
        else{
            output[v++] = *(dic+*read/4);
            b = *read%4;
            read++;
            if(*read == '\0'){
                output[v++] = *(dic+b*16);
                output[v++] = '=';
                output[v++] = '=';
            }
            else{
                output[v++] = *(dic+b*16 + *read/16);
                c = *read%16;
                read++;
                if(*read == '\0'){
                    output[v++] = *(dic+c*4);
                    output[v++] = '=';
                }
                else{
                    output[v++] = *(dic+c*4 + *read/64);
                    output[v++] = *(dic+*read%64);
                }
            }
        }

        output[v] = '\0';

        printf("case #%d:\n",i);
        printf("%s\n",output);
    }
    return 0;
}