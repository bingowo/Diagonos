#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void enbinary(int dec,int len)
{
    for(int i=len-1;i>=0;--i){
        if(dec&(1<<i))
            putchar('1');
        else
            putchar('0');
    }
}
char input[600];
char temnum[4];
int trans(int left,int end)
{
    memset(temnum,0,sizeof(temnum));
    for(int k=end-1;k>=left;--k){
        temnum[end-k-1]=input[k];
    }
    return atoi(temnum);
}

int main()
{
    scanf("%s",input);
    int slen=strlen(input);
    printf("0001");
    printf("%d",trans(0,3));
    enbinary(slen,10);
    int begin=0,end=3;
    while(end<=slen){
        for(int t=end-1;t>=begin;--t){
            input[t];
        }
    }

    return 0;
}
