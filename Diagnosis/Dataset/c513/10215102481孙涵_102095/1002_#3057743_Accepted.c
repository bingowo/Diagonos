#include <stdio.h>
#include <stdlib.h>

long long int getNum(int * arr, char * s);
int * getArr(char *s);

int main(){
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        char s[61];
        scanf("%s",s);
        int *arr;
        arr = getArr(s);
        long long int ans;
        ans = getNum(arr, s);
        printf("case #%d:\n",t);
        printf("%lld",ans);
        printf("\n");
    }
    return 0;
}

int * getArr(char *s){
    int pl = 0; //指向当前位置
    int num;//当前最高位数字
    int R;//表示是多少进制的
    char c;//表示当前pl所指向的字符
    static int arr[256];//字符表 下表为ASCII码 元素为对应的数字
    for (int i = 0; i < 256; i++){
        arr[i] = -1;
    }
    arr[(int)(*s)] = 1;//先手动规定第一个字符是1
    num = 1;
    R = 1;
    pl++;
    //接下来定0
    while( *(s + pl) != '\0' &&  (*(s + pl) == *(s + pl - 1))){
        pl++;
    }//找到第一个和首位字符不一样的字符 用pl指向该字符
    if( *(s + pl) != '\0'){
        c = *(s + pl);
        arr[(int)c] = 0;
        pl++;
        num = 0;
        R = 2;
    }
    if(pl != 0){
        R = 2;
    }//这个是1111111仍然位2进制的情况
    num = 2;
    while( *(s + pl) != '\0' ){
        c = *(s + pl);
        if(arr[(int)c] == -1){
            arr[(int)c] = num;
            num++;
            R++;
        }
        pl++;
    }
    //循环结束时
    //num比最高位数字多1
    //R刚好就是进制;
    arr[0] = R;
    return arr;
}

long long int getNum(int * arr, char * s){
    long long int ans;//存储答案
    int pl;//指向当前元素
    int R = *arr;//进制数
    int num;//每一位对应的数字
    char c;//每一位对应的符号

    pl = 0;
    c = *(s + pl);
    num = arr[(int)(c)];
    ans = num;
    pl++;
    while( *(s + pl) != '\0'){
        c = *(s + pl);
        num = arr[(int)(c)];
        ans = ans * R + num;
        pl++;
    }
    return ans;
}
