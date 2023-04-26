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
    if(read == NULL){
        printf("-1");
        return 0;
    }
    char *next = strstr((read+1),"0x");
    if(next == NULL) next = input + strlen(input);

    read += 2;

    while(read <= next){
        //printf("%p , %p\n",read,next);

        if(read == next){//turn to the next
            if(next == input+strlen(input)){
                i++;
                break;
            }
            read = next+2;
            next = strstr((read+1),"0x");
            if(next == NULL) next = input + strlen(input);
            i++;
        }
        else if(isdigit(*read) || (*read >= 'a' && *read <= 'f')){//hex
            //printf("before hex %u\n",out[i]);
            switch(!isdigit(*read)){
                case 0: 
                    out[i] = out[i]*16 + *read - '0';
                    //printf("elseif %d\n",out[i]);
                    break;
                default: 
                    out[i] = out[i]*16 + *read - 'a' + 10;
                    //printf("elseif default %d\n",out[i]);
                    break;
            }
            read++;
        }
        else {
            if(next == input+strlen(input)){
                i++;
                break;
            }
            read = next+2;
            if(*(read-1) == 'x') i--;
            while(!isdigit(*read) && !(*read >= 'a' && *read <= 'f')){
                read = strstr((read+1),"0x");
            }
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