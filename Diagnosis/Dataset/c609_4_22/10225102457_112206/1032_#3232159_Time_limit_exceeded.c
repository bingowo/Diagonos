#include<stdio.h>
#include<string.h>

int main(void)
{
    char ch1,ch2;
    int sum = 1;
    int maxsum = 1;
    ch1 = getchar();
    while(ch1 != '\n'){
        ch2 = getchar();
        if(ch2 != ch1){
            sum = 2;
            while('\n' != (ch1 = getchar())){
                if(ch1 == ch2) break;
                sum++;
                ch2 = ch1;
            }
            if(sum > maxsum) maxsum = sum;
        }
    }
    printf("%d",maxsum);
    return 0;
}