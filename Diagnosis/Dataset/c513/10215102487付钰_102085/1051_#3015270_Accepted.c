#include <stdio.h>
#include <string.h>
#include <math.h>
char src[1024], res[1024];
//src为输入的字符串；
// res为Base64编码后得到的字符串
int pos,index,bits;
char base64_chart[] =
{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        /*for(int k=0;k<1024;k++){
            src[k]=0;
        }*/
        gets(src);
        int len = strlen(src);
        pos = 0,index = 0,bits = 0;
        int ret = 0;
        int ch,cur;
        while(index < len)
        {
            ch = src[index];
            cur = (ret << (6 - bits)) + (ch >> (2 + bits));
            res[pos++] = base64_chart[cur];
            index++;
            bits += 2;
            ret = ch % (1 << bits);
            if(bits == 6){
                 res[pos++] = base64_chart[ret];
                bits = 0;
                ret = 0; }
        }
            if(bits == 2) //最后一组只有1个字符
        {
            res[pos++] = base64_chart[ret << 4];
            res[pos++] = '=';
            res[pos++] = '=';
        }
            else if(bits == 4) //最后一组只有2个字符
        {
res[pos++] = base64_chart[ret << 2];
res[pos++] = '=';
}
res[pos] = '\0';
    for(int j=0;j<pos;j++){
        printf("%c",res[j]);
        //res[j]=0;
    }
    printf("\n");
    }

}
