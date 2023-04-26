#include <stdio.h>
#include <string.h>

int main(){
    int len,pos,index,bits,ret,ch,cur,Num,Now=0,i;
    char base64_chart[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
    char src[1024], res[1024];
    scanf("%d\n",&Num);
    while(Now<Num){
        printf("case #");
        printf("%d:\n",Now);
        gets(src);
        len = strlen(src);
        pos = 0; index = 0; bits = 0;
        ret = 0;
        while(index < len)
        { ch = src[index];
            cur = (ret << (6 - bits)) + (ch >> (2 + bits));
            res[pos++] = base64_chart[cur];
            index++;
            bits += 2;
            ret = ch % (1 << bits);
            if(bits == 6)
            { res[pos++] = base64_chart[ret];
                bits = 0;
                ret = 0; }
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
        for(i=0;i<strlen(res)-1;i++)
            printf("%c",res[i]);
        printf("%c\n",res[i]);
        Now++;
    }
    return 0;
}