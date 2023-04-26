#include<stdio.h>
#include<string.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    getchar();
    for(i = 0;i < T;i++){
        int j = 0;
        char s[61] = {};
        scanf("%s",&s);
        getchar();
        //判断最小进制数
        int n = 0,k = 0;
        char* p = s;
        int trans[128];
        for(k = 0;k < 128;k++){
            trans[k] = -1;
        }
        char t;
        trans[*p] = 1;
        t = *p;
        p++;
        while((*p != '\0')&&(*p == t)){
            p++;
        }
        if(*p != '\0'){
            trans[*p] = 0;
            n = 2;
        }
        while(*p != '\0'){
            if(trans[*p] == -1){
                trans[*p] = n;
                n++;
            }
            p++;
        }
        //进制转换
        long long int r = 0;
        p = s;
        while(*p != '\0'){
            r = r * n + trans[*p];
            p++;
        }
        printf("case #%d:\n",i);
        printf("%lld\n",r);
    }

    return 0;
}
