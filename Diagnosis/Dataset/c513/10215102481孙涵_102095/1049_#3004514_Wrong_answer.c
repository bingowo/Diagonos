#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct data{
    char m[501];
    char m0[501];
};

int cmp(const void *a,const void *b){
    struct data p1,p2;
    p1 = *((struct data*)a);
    p2 = *((struct data*)b);
    return strcmp(p1.m0,p2.m0);
}

int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    while(T-->0){
    	getchar();
        char *s;
        s = (char *)malloc(1000);
        int i = 0;
        gets(s);
        char *p = s;
        struct data s0[501];
        while(*p){
            if(isspace(*p) || ispunct(*p)) p++; //是标点或者空格的话 p++ 
            else{
                char *p2 = p+1;
                while(*p2 && *p2 != ' '&& *p2 != ',' && *p2 != '.' && *p2 != '!' && *p2 != '?'){
                    p2++;
                }//相当于获得一一个单词的右边界吗? 
                int len = p2 - p; 
                strncpy(s0[i].m,p,len);
                strncpy(s0[i].m0,p,len);
                s0[i].m[len] = s0[i].m0[len] = 0;
                i++;
                p = p2;
            }
        }
        int num = 0;
        int k;
        for(k = 0;k < i ;k++){
            int flag = 0;
            int j;
            for(j = 0;j < num;j++){
                if(strcmp(s0[k].m,s0[j].m0) == 0){
                    flag = 1;
                }
            }
            if(flag == 0){
                strcpy(s0[num].m0,s0[k].m);
                num++;
            }
        }
        qsort(s0,num,sizeof(s0[0]),cmp);
        printf("case #%d:\n",cnt);
        int x;
        for(x = 0;x < num;x++){
            printf("%s ",s0[x].m0);
        }
        printf("\n");
        cnt++;
        free(s);
    }
}