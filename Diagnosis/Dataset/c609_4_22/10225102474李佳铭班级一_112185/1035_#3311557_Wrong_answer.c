#include<stdio.h>
#include <string.h>

//当遇到一组相同的字符时，返回它们的最后一个下标
int end(char* t){
    int len = strlen(t);
    int i;
    for(i = 0; i < len;i++){
        if(*(t + i) != *(t + i + 1)){
            break;
        }
    }
    return i;
}

//消除相同的字符，返回一个新的字符串
char* newString(char* s){
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        int j = end(s + i);
        if(j == 0){
            continue;
        }
        strcpy(s + i,s + i + j + 1);
        len = len - j - 1;
        i--;
    }
}

//在pos + 1位置增加一个与pos位置相同的字符
char* insert(char*s,int pos){
    int i;
    for(i = strlen(s) + 1;i > pos; i--){
        s[i] = s[i - 1];
    }
    return s;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++){
        char s[105];
        char t[105];
        scanf("%s",s);
        int len1 = strlen(s);
        int max = 0;
        for(int j = 0; j < len1;j++){
            j = j + end(s+j);
            strcpy(t,s);
            insert(t,j);
            newString(t);
            int count1;
            int count2;
            do{
                count1 = strlen(t);
                newString(t);
                count2 = strlen(t);
            }while(count1 != count2);
            max = (len1 + 1 - strlen(t)) > max ? (len1 + 1 - strlen(t)) : max;
        }
        printf("case #%d:\n%d",i,max);
        if(i != T - 1){
            printf("\n");
        }


    }
}
