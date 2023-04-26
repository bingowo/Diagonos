#include <stdio.h>
#include <stdlib.h>

long long int getMin(int *a, char* s);
int* getNum(char* s);

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        char s[61];
        scanf("%s",s);
        int *a = getNum(s);
        int min = getMin(a, s);
        printf("case #%d:\n",t);
        printf("%lld\n",min);
    }
    return 0;
}

int* getNum(char* s){
    static int a[122];
    for(int i = 0; i < 121; i++){
        a[i] = -1;
    }
    int pl = 0;//指针 指向当前字符串位置
    int num = 0;//表示当前最大的数字
    a[(int)(*s)] = 1;
    pl++;
    while (*(s + pl) != '\0'){
        if(a[(int)(*(s + pl))] == -1){
            if(num == 1){
                num++;
            }
            a[(int)(*(s + pl))] = num;
            num++;
            pl++;
        }else{
            pl++;
        }
    }
    if(pl == 0){
        num = 1;
    }else if( pl >= 1 && (num == 0 || num == 1)){
        num = 2;
    }else if(pl ==  num){
        num = pl +1;
    }else{
        num ++;
    }
    a[121] = num;
    return a;
}


long long int getMin(int *a, char *s){
    long long int min = 1;//放最小值;
    int pl = 1;//指向当前字符;
    int num = *(a + 121);
    while(*(s + pl) != '\0'){
        min = min * num + (int)(*(a + (int)(*(s + pl))));
        pl++;
    }
    return min;
}
