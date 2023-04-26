#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char base64_chart[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
int main(){
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        char src[1024], res[1024];
        gets(src);
        int len,pos,index,bits,ret,ch,cur;
        len = strlen(src);
        pos = 0; index = 0; bits = 0;
        ret = 0;
        while(index < len){
            ch = src[index];
            cur = (ret << (6 - bits)) + (ch >> (2 + bits));
            res[pos++] = base64_chart[cur];
            index++;
            bits += 2;
            ret = ch % (1 << bits);
            if(bits == 6)
            {   res[pos++] = base64_chart[ret];
                bits = 0;
                ret = 0; 
            }
        }
        if(bits == 2)
        {
            res[pos++] = base64_chart[ret << 4];
            res[pos++] = '=';
            res[pos++] = '=';
        }
        else if(bits == 4)
        {
            res[pos++] = base64_chart[ret << 2];
            res[pos++] = '=';
        }
        res[pos] = '\0';
        printf("case #%d:\n",i);
        printf("%s\n",res);

    }
    
}