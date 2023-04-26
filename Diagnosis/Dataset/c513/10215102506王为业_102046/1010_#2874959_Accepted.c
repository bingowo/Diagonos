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
    for(int i=left;i<end;++i)
        temnum[i-left]=input[i];
    return atoi(temnum);
}

int main()
{
    scanf("%s",input);
    int slen=strlen(input);
    printf("0001");
    enbinary(slen,10);
    int begin=0,end=3;
    while(end<=slen){
        enbinary(trans(begin,end),10);
        begin=end;
        end+=3;
    }
    end=slen;
    if(end-begin==2){
        enbinary(trans(begin,end),7);
    }else if(end-begin==1){
        enbinary(trans(begin,end),4);
    }
    return 0;
}
