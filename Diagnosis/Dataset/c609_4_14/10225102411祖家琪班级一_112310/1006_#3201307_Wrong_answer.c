/*
对于任意字符串，总是假设它是一个自身不同字符数进制的数
最小情况：首字符表示1(若表示0则不应在首位写出这个字符)，之后的位以此往后表示
0，2，3...N(N为进制 - 1)
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int T,flag = 0,ethcnt = 0;//ethcnt记录下已蚀刻的映射数目,最终它将表示神秘字符的进制
    long long res;
    char ch[61],table[61];
    scanf("%d",&T);
    int index(char a,const char *str);
    for(int i = 0;i < T;i++){
        scanf("%s",ch);
        table[1] = ch[0];
        ethcnt++;
        for(int j = 1;j < strlen(ch);j++){
            if(ch[j] == ch[0]) continue;
            else {
                table[0] = ch[j];break;//在table中刻入代表0和1的字符
            }
        }
        ethcnt++;
        for(int j = 2;j < strlen(ch);j++){
            for(int k = 0;k < strlen(table);k++){
                if(table[k] == ch[j]){
                    flag = 1;break;
                }
            }
            if(flag) continue;//跳过table中已经刻入的字符
            table[ethcnt++] = ch[i];
            flag = 0;
        }
        //printf("%s,%d",table,ethcnt);
        for(int j = 0;j < ethcnt;j++){
            if(table[j] == ch[0]) res = j;
        }
        for(int j = 0;j < strlen(ch) - 1;j++){
            res = res*ethcnt + index(ch[j + 1],table);
        }
        printf("case #%d:\n%lld\n",i,res);
        ethcnt = 0;strcpy(table,"");
    }
    return 0;
}
int index(char a,const char *str)//返回a在str中的索引
{
    for(int i = 0;i < strlen(str);i++){
        if(a == str[i]) return i;
    }
    return 0;
}
