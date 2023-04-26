#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int search(char *s, char c){  //查找c是s里的第几个（0开始）
    for(int i=0;;i++)
        if(s[i]==c) return i; 
}
int f(char *arr){ //算几进制
    int count=0;
    for(int i=48; i<=57; i++)
        if(strchr(arr,(char)i)) count++;
    for(int i=65; i<91; i++)
        if(strchr(arr,(char)i)) count++;
    for(int i=97; i<123; i++)
        if(strchr(arr,(char)i)) count++;
    if(count>=2) return count;
    else return 2;
}
int main(){
    int T;
    char *arr, *s;  //分别存储神秘字符，和按出现顺序排序的字符
    int *num; //每个字符代表数字多少，与s相对
    long long sum;
    int len; 
    int r;  //进制
    int count=0;
    arr = malloc(sizeof(char)*61);
    num = malloc(sizeof(int)*61);
    s = malloc(sizeof(char)*61);
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%s", arr);
        len=strlen(arr);
        count = 0;
        r = f(arr);
        strcpy(s,"");
        s[0] = arr[0];
        num[count++] = 1;
        for(int j=1; j<len; j++){  
            if(!strchr(s,arr[j])){
                s[count] = arr[j];
                if(count==1) num[count] = 0;
                else num[count] = count;
                count++;
            }
        }
        sum = 0;
        for(int j=0; j<len; j++){
            sum = sum*r+num[search(s,arr[j])];
        }
        printf("case #%d:\n", i);
        printf("%lld\n", sum);
    }
    free(s);
    free(arr);
    return 0;
}