//1053 高精度+低精度
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ans[110], len;
void add1(){  //+1
    int temp=1, pos=0;
    while(pos<len){
        ans[pos] += temp;
        temp = ans[pos]/10;
        ans[pos++] %= 10;
        if(temp==0) break;
    }
    if(temp!=0){
        ans[len++] = temp;
    }
}

void add2(int pos){  //从pos位开始加1
    int temp=1;
    while(pos<len){
        ans[pos] += temp;
        temp = ans[pos]/10;
        ans[pos++] %= 10;
        if(temp==0) break;
    }
    if(temp!=0){
        ans[len++] = temp;
    }
}

int same(){ //判断是否重复(高位往低位找)
    int i;
    for(i=len-1; i>0; i--){
        if(ans[i]==ans[i-1]) return i-1;
    }
    return -1;//返回重复处 位权小的位置
}
int main(){
    int T;
    char s1[105];
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        printf("case #%d:\n", i);
        scanf("%s", s1);
        memset(ans, 0, sizeof(ans));
        len = strlen(s1);
        if(len==1){
            printf("%d\n", (char)s1[0]-48+1);
            continue;
        }
        for(int i=0; i<len; i++){
            ans[i] = (char)s1[len-i-1]-48;
        }
        add1(); //先加1
        int ret = same(); //查重复
        while(ret!=-1){
            add2(ret);
            ret = same();
        }
        for(int i=0; i<len; i++) printf("%d", ans[len-i-1]);
        printf("\n");
    }
    return 0;
}