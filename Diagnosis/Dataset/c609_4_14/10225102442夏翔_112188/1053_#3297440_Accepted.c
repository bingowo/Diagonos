//1053 高精度+低精度
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ans[110], len;

void add(int pos){  //从pos位开始加1
    int temp=1;
    while(pos<=len){
        ans[pos] += temp;
        temp = ans[pos]/10;
        ans[pos++] %= 10;
        if(temp==0) return;
    }
    if(temp!=0){
        ans[++len] = temp; //注意ans[0]是-1
    }
}

int same(){ //判断是否重复(高位往低位找)
    int i;
    for(i=len; i>=2; i--){
        if(ans[i]==ans[i-1]) return i-1;//返回重复处 位权小的位置
    }
    return -1;
}
int main(){
    int T, flag;
    char s1[105];
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        printf("case #%d:\n", i);
        scanf("%s", s1);
        memset(ans, 0, sizeof(ans));
        ans[0] = -1; //个位之前
        len = strlen(s1);
        if(len==1){
            printf("%d\n", (char)s1[0]-48+1);
            continue;
        }
        for(int j=1; j<=len; j++){
            ans[j] = (char)s1[len-j]-48;
        }
        add(1); //先从个位+1
        int ret = same(); //查重复
        while(ret!=-1){
            add(ret);
            for(ret--; ret>=1; ret--){ //位权最高的重复位置+1后，后面用0101代替
                if(ans[ret+1]!=0) ans[ret] = 0;
                else ans[ret] = 1;
            }
            ret = same();
        }
        for(int j=1; j<=len; j++) printf("%d", ans[len-j+1]);
        printf("\n");
    }
    return 0;
}