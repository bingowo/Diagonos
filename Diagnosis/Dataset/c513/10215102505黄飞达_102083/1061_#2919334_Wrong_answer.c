#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ll long long
//用结构体装字符串，计算其代表的最小值并装入，然后排序输出。
//计算函数calc：搞个table映射数组。初始化table[s[0]]为1,while循环找到第二个字母记为0，后面就正常从2到n
//最后，总的有n种字符，n进制。slen个字符，位权pow(n,slen-i-1)。

typedef struct num{
    char s[16];
    ll num;
}num;

ll calc(char s[]){
    int table[128] = {0};
    int slen = strlen(s), species = 1;
    table[s[0]] = 1;
    int i = 0;
    for (i; i < slen; i++){
        if (table[s[i]]!=1) {
            i++;
            species++;
            break;
        }
    }
    for (i; i < slen; i++){
        if (table[s[i]] == 0) table[s[i]] = species++;
    }
    ll val = 0;
    for (int i = 0; i < slen; i++){
        val += table[s[i]]*pow(species, slen-i-1);
    }
    return val;
}

int cmp(const void*a, const void* b){
    num x = *(num*)a;
    num y = *(num*)b;
    if (x.num!=y.num) return x.num < y.num ? -1 : 1;
    else return strcmp(x.s, y.s);
}

int main(){
    int N;
    scanf("%d ", &N);
    num arr[10005];
    for (int i = 0; i < N; i++) {
        num n;
        memset(n.s, 0, 16);
        scanf("%s", &n.s);
        n.num = calc(n.s);
        arr[i] = n;
    }
    qsort(arr, N, sizeof(num), cmp);
    for (int i = 0; i < N; i++) printf("%s\n", arr[i].s);
    return 0;
}