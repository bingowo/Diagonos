#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * baseconvertion(int N, int R);

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        int n,r;
        scanf("%d %d",&n,&r);
        char *s;
        s = baseconvertion(n,r);
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
        char * ans0;
        ans0 = baseconvertion(ans,r);
        printf("case #%d:\n",t);
        printf("%s\n",ans0);
    }
    return 0;
}



char * baseconvertion(int N, int R){
    char s;//某一位上的符号
    static char baseR[100] = {0};
    for(int i = 0; i < 100; i++){
        baseR[i] = 0;
    }
    int num;//余数
    int left = N;//商
    int sign = 1;//符号位
    int pl = 0; //显示总位数同时指向当前下标
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
    for(int k = 0; k < strlen(baseR) / 2; k++){
        int temp = baseR[k];
        baseR[k] = baseR[strlen(baseR) - k - 1];
        baseR[strlen(baseR) - k - 1] = temp;
    }
    return baseR;
}

