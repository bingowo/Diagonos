#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


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
    getchar();
    while(T-->0){
            
        char s[501];
        gets(s);
        int i = 0;
        char *p = s;
        struct data s0[501];//来存放单词
        for(int y = 0;y < 501;y++){
            s0[y].m = 0;
            s0[y].m0 = 0;
        }
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
        //printf("i is %d\n",i);//i代表单词的个数
        int flag = 0;
        int num = 0;
        //strcpy(s0[0].m0,s0[0].m);//先把第一个复制过去
        for(int k = 0;k < i ;k++){
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
        //int k = 0;
        //int j = 0;
        //if(strcmp(s[k].m.s0[j].m0) != 0){

        //}
        //printf("num is %d\n",num);
        qsort(s0,num,sizeof(s0[0]),cmp);
        printf("case #%d:\n",cnt);
        for(int x = 0;x < num;x++){
            printf("%s ",s0[x].m0);
        }
        printf("\n");
        cnt++;
    }
}