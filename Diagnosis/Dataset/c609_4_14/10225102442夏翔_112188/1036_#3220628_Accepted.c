#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int search(char *s2){ //找到与第一个括号'('对应的括号')'
    int count=1;
    for(int i=1; i<strlen(s2); i++){
        if(s2[i]=='(') count++;
        else count--;
        if(count==0) return i;
    }
}

int Ssum(char *s1){
    char *str;
    int pos=search(s1);
    if(strlen(s1)==2) return 1; //递归结束条件
    if(pos==strlen(s1)-1){
        s1[pos] = '\0';  //切记不可太早改变s1[pos],否则strlen也会变
        return 2*Ssum(s1+1);
    }else if(pos>1){
        s1[pos] = '\0';
        return 2*Ssum(s1+1)+Ssum(s1+pos+1);
    }else{
        s1[pos] = '\0';
        return 1+Ssum(s1+pos+1);
    }
}
int main(){
    char *s;
    s = (char*)malloc(sizeof(char)*51);
    scanf("%s", s);
    printf("%d", Ssum(s));
    free(s);
    return 0;
}