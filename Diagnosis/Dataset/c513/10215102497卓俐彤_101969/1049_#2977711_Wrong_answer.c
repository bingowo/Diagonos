#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct word{
    char w[20];
    int flag;
};

int cmp(const void*a,const void*b){
    struct word d1,d2;
    d1=*((struct word*)a);
    d2=*((struct word*)b);
    return strcmp(d1.w,d2.w);
}

int main(){
    int T;
    scanf("%d",&T);
    char c=getchar();
    for(int t=0;t<T;t++){
        int letter_num=0,temp=0;
        struct word words[300];
        while((c=getchar())!='\n'){
            if(isalpha(c)){
                words[letter_num].w[temp++]=c;
            }else{
                words[letter_num].w[temp]='\0';
                letter_num++;
                temp=0;
            }
        }
        words[letter_num].w[temp]='\0';
        qsort(words,letter_num,sizeof(words[0]),cmp);
        int flag1=0,flag2=1;
        words[0].flag=1;
        while(flag1<letter_num&&flag2<letter_num){
            if(strcmp(words[flag1].w,words[flag2].w)==0){
                words[flag2++].flag=0;
            }else{
                words[flag2].flag=1;
                flag1=flag2;
                flag2++;
            }
        }
        printf("case #%d:\n",t);
        for(int i=0;i<letter_num;i++){
            if(words[i].flag)printf("%s%c",words[i].w,i==flag1?'\n':' ');
        }
    }
    return 0;
}
