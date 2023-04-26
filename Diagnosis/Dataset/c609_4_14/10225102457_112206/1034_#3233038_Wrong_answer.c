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
    char *next = strstr((input+1),"0x");
    if(next == NULL) next = input + strlen(input);
    if(read == NULL){
        printf("-1");
        return 0;
    }

    read+=2;
    while(read <= next){
        //printf("%p\n",read);

        if(read == next){
            read = next+2;
            next = strstr((read+1),"0x");
            if(next == NULL) next = input + strlen(input);
            i++;
        }
        else if(isdigit(*read) || (*read >= 'a' && *read <= 'f')){
            switch(isdigit(*read)){
                case '0': out[i] = out[i]*16 + *read - 48;break;
                default : out[i] = out[i]*16 + *read - 87;break;
            }
            read++;
        }
        else {
            read = next+2;
            next = strstr((read+1),"0x");
            if(next == NULL) next = input + strlen(input);
            i++;
        }
    }

    for(int v = 0; v < i; v++){
        printf("%u ",out[v]);
    }
    return 0;
}