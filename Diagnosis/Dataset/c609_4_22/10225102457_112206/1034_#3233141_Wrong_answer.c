#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    char input[100000] = {0};
    char *read = input;
    scanf("%s",input);

    unsigned out[40000] = {0};
    int i = 0;

    read = strstr(input,"0x");
    if(read == NULL){
        printf("-1");
        return 0;
    }
    char *next = strstr((read+1),"0x");
    if(next == NULL) next = input + strlen(input);

    read+=2;
    out[0]=0;
    while(read <= next){
        printf("%p , %p\n",read,next);

        if(read == next){
            read = next+2;
            next = strstr((read+1),"0x");
            if(next == NULL) next = input + strlen(input);
            out[i] = 0;
            i++;
        }
        else if(isdigit(*read) || (*read >= 'a' && *read <= 'f')){
            printf("%u\n",out[i]);
            switch(isdigit(*read)){
                case 0: out[i] = out[i]*16 + *read - 87;break;
                default : out[i] = out[i]*16 + *read - 48;break;
            }
            read++;
        }
        else {
            read = next+2;
            next = strstr((read+1),"0x");
            if(next == NULL) next = input + strlen(input);
            i++;
            out[i] = 0;
        }
    }

    for(int v = 0; v < i; v++){
        printf("%u ",out[v]);
    }
    return 0;
}