#include <stdio.h>
#include <string.h>


void trans(int *array) {
    for (int i = 499; i > 0; i--) {
        array[i - 1] += array[i] / 10;
        array[i] %= 10;
    }
}

void multi(int *array, int num) {
    for (int i = 499; i >= 0; i--) {
        array[i] *= num;
    }
    trans(array);
}

int main() {
    char s[1005];
    int num[1005];
    int sum[500];
    int co=0;
    memset(sum,0,sizeof (sum));
    sum[499]=1;
    scanf("%s",s);
    unsigned len= strlen(s);
    if(len==1){
        printf("0\n");
        return 0;
    } else if(len==2){
        if(s[0]==s[1]){
            printf("1\n");
            return 0;
        } else{
            printf("4\n");
            return 0;
        }
    } else {
        if(s[0]==s[1])
            num[co++]=1;
        else
            num[co++]=2;
        for (int i = 1; i < len - 1; i++) {
            int tmp=1;
            if(s[i]!=s[i-1])
                tmp++;
            if(s[i]!=s[i+1])
                tmp++;
            num[co++]=tmp;
        }
        if(s[len-1]==s[len-2])
            num[co++]=1;
        else
            num[co++]=2;
    }
    for(int i=0;i<co;i++)
        multi(sum,num[i]);
    int i=0;
    while (!sum[i])
        i++;
    for(;i<500;i++)
        printf("%d",sum[i]);
    printf("\n");
    return 0;
}
