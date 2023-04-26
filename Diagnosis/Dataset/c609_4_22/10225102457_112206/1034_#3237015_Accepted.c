#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    char input[100000] = {0};
    scanf("%s",input);

    unsigned out[40000] = {0};
    int i = 0;

    char *read = strstr(input,"0x");
    char *next = strstr((read+1),"0x");
    if(next == NULL) next = input + strlen(input);
    while(next != NULL && next != input + strlen(input) && !isdigit(*(next+2)) && !(*(next+2) >= 'a' && *(next+2) <= 'f')){
        next = strstr((next+1),"0x");
    }
    if(next == NULL){
        printf("-1");
        return 0;
    }
    if(read == NULL){
        printf("-1");
        return 0;
    }
    read += 2;

    while(read <= next){
        //printf("%p , %p\n",read,next);

        if(read == next){//if next is close
            if(*next == '\0') break;
            read = next+2;
            next = strstr((read-1),"0x");
            while(next != NULL && !isdigit(*(next+2)) && !(*(next+2) >= 'a' && *(next+2) <= 'f') && next != input + strlen(input)){
                next = strstr((next+1),"0x");
            }
            if(next == NULL) next = input + strlen(input);
        }
        else if(isdigit(*read) || (*read >= 'a' && *read <= 'f')){//hex
            //printf("before hex %u\n",out[i]);
            while((isdigit(*read) || (*read >= 'a' && *read <= 'f')) && (read < next)){
                switch(!isdigit(*read)){
                    case 0: 
                        out[i] = out[i]*16 + *read - '0';
                        //rintf("elseif %d\n",out[i]);
                        break;
                    default: 
                        out[i] = out[i]*16 + *read - 'a' + 10;
                        //printf("elseif default %d\n",out[i]);
                        break;
                    }
                read++;
            }
            i++;
            //printf("after hex %u\n",out[i-1]);
        }
        else{
            if(*next == '\0') break;
            read = next+2;
            //printf("inside one case %p , %p\n",read,next);
            if(read != NULL && !isdigit(*read) && !(*read >= 'a' && *read <= 'f')){
                while(read != NULL && !isdigit(*(read+2)) && !(*(read+2) >= 'a' && *(read+2) <= 'f')){
                    read = strstr((read+1),"0x");
                }
                read += 2;
            }
            if(read == NULL) break;
            next = strstr((read+1),"0x");
            while(next != NULL && !isdigit(*(next+2)) && !(*(next+2) >= 'a' && *(next+2) <= 'f') && next != input + strlen(input)){
                next = strstr((next+1),"0x");
            }
            if(next == NULL) next = input + strlen(input);
            //printf("after one case %p , %p\n",read,next);
        }
    }

    for(int v = 0; v < i; v++){
        printf("%u ",out[v]);
    }
    return 0;
}