#include <stdio.h>
#include <stdlib.h>

void base(char * s);

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        char s[15];
        scanf("%s",&s);
        printf("case #%d:\n",t);
        base(s);
    }
}

void base(char * s){
    long long int ans = 0;
    int length = 0;//字符串长度
    int pl = 0;//指向当前的位置
    int R = 1;//表示当前进行位的权重
    char c;//当前位置的符号
    int i = 0;
    while(*(s + i) != '\0'){
        i++;
    }
    i--;
    for(;i >= 0; i--){
        c = *(s + i);
        if (c == '-'){
            ans = ans + (-1) * R;
        }else if(c == '1'){
            ans = ans + 1 * R;
        }
        R = R * 3;
    }
    printf("%lld\n",ans);
}
