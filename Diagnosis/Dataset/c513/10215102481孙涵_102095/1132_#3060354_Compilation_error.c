#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * itor(int n, int r);
void baseconvertion(int N, int R);

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        int n,r;
        scanf("%d %d",&n,&r);
        printf("case #%d:\n",t);
        char *s;
        s = itor(n,r);
        int ans = 0;
        for(int i = 0; i < strlen(s); i++){
            char j;
            int m;
            j = *(s + i);
            if(j >= '0' && j <= '9'){
                m = j - '0';
            }else if(j >= 'a' && j <= 'z'){
                m = j - 'a' + 10;
            }else if(j >= 'A' && j <= 'Z'){
                m = j - 'A' + 10;
            }
            ans = ans + m;
        }
        baseconvertion(ans,r);
    }
    return 0;
}


char * itor(int n, int r){
    static char ans[500] = {"\0"};
    itoa(n,ans,r);
    return ans;
}


void baseconvertion(int N, int R){
    char s;//某一位上的符号
    char baseR[100] = {0};
    int num;//余数
    int left = N;//商
    int sign = 1;//符号位
    int pl = 0; //显示总位数同时指向当前下标
    if(N < 0){
        sign = -1;
        left = -1 * left;
    }
    do{
        num = left % R;
        left = left / R;
        if(num >= 0 && num <= 9){
            s = num + '0';
            baseR[pl] = s;
        }else{
            s = ( num - 10 ) + 'A';
            baseR[pl] = s;
        }
        pl++;
    }while(left != 0);
    if (sign == -1){
        printf("-");
    }
    for (pl--; pl >= 0; pl--){
        printf("%c",baseR[pl]);
    }
    printf("\n");
}

