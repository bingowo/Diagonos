#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//list:A-Z a-z 0-9

struct list{
    int count;
    int location;
};

int main(){
    char str[1000001];
    scanf("%s",str);
    int str_begin=0,str_end=1,flag=0;
    struct list lists[63];
    for(int i=0;i<63;i++){
        lists[i].location=0;
        lists[i].count=0;
    }
    int len=0,maxlen=0;
    int index=0,row=1;
    for(int i=0;i<strlen(str);i++){
        if(maxlen==62)break;
        if(isdigit(str[i])){
            index=str[i]+52-'0';
        }else if(islower(str[i])){
            index=str[i]+26-'a';
        }else index=str[i]-'A';
        if(lists[index].count!=row){
            lists[index].location=i;
            lists[index].count=row;
            len++;
        }else{
            row++;
            if(maxlen<len){
                maxlen=len;
                str_begin=flag;
                str_end=i;
            }
            flag=lists[index].location+1;
            i=flag-1;
            len=0;
        }
    }
    if(maxlen<len){
        maxlen=len;
        str_begin=flag;
        str_end=(int)strlen(str);
    }
    for(int i=str_begin;i<str_end;i++){
        printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}
