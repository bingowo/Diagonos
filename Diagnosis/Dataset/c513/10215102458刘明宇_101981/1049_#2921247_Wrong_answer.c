#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>



int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    getchar();
    while(T-->0){
        struct data{
        char m[501];//来存储单词
        char m0[501];//来存放非重复单词
        };
        char s[500];
        //s = (char *)malloc(500);
        gets(s);
        int i = 0;
        char *p = s;
        struct data s0[501];//来存放单词
        while(*p){
            if(isspace(*p) || ispunct(*p)) p++;
            else{
                char *p2 = p+1;
                while(*p2 != ' '&& *p2 != ',' && *p2 != '.' && *p2 != '!' && *p2 != '?'){
                    p2++;
                }
                int len = p2 - p; //得出单词长度
                strncpy(s0[i].m,p,len); //将单词copy到s0中去
                i++;//i的值增大
                p = p2;
            }
        }//通过While循环，可以将单词全部读入到s0中
        //再提取出非重复单词
        int num = 0;
        for(int k = 0;k < i ;k++){
            int flag = 0;
            for(int j = 0;j < num;j++){
                //如果两个字符串相等就返回0
                //如果不相同，就copy过去
                if(strcmp(s0[k].m,s0[j].m0) == 0){
                    flag = 1;
                }
            }
            if(flag == 0){
                strcpy(s0[num].m0,s0[k].m);
                num++;
            }
        }
    int cmp(const void *a,const void *b){
    struct data p1,p2;
    p1 = *((struct data*)a);
    p2 = *((struct data*)b);
    return strcmp(p1.m0,p2.m0);
}
        qsort(s0,num,sizeof(s0[0]),cmp);
        printf("case #%d:\n",cnt);
        int x;
        for(x = 0;x < num - 1;x++){
            printf("%s ",s0[x].m0);
        }
        printf("%s",s0[x].m0);
        printf("\n");
        cnt++;
    }
}
