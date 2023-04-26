#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct data{
    char ch;
    double f;
};

int cmp(const void *a,const void *b){
    struct data *d1 = (struct data*)a;
    struct data *d2 = (struct data*)b;
    if(d1->f == d2->f){
        return d2->ch - d1->ch;
    }
    else{
        if(d1->f > d2->f) return -1;
        else return 1;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    int cnt = 0;
    while(T-- >0){
        double alp[26];
        char ch;
        int i = 0;
        //输入使用频率
        while(ch != '\n'){
            scanf("%lf",&alp[i]);
            ch = getchar();
            i++;
        }
        char str[101];
        scanf("%s",str);
        int t = strlen(str);
        struct data res[101];
        for(int j = 0;j < t;j++){
            res[j].ch = str[j];
            if(str[j]<='Z' && str[j] >='A'){
                res[j].f = alp[str[j] - 65];
            }
            else if(str[j] <= 'z' && str[j] >= 'a'){
                res[j].f = alp[str[j] - 97];
            }
        }
        //printf("%d",t);

        qsort(res,t,sizeof(res[0]),cmp);
        printf("case #%d:\n",cnt);
        for(int m = 0;m < t;m++){
            printf("%c",res[m].ch);
        }
        printf("\n");
        cnt++;

    }
}
