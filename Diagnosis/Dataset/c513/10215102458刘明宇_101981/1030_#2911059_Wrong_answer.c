#include <stdio.h>
#include <stdlib.h>
#define M 10000

struct data{
    char m[M];
};

int cmp(const void *a,const void *b){
    struct data p1,p2;

    if(p1.m[0] == p2.m[0]) return atoi(p1.m) - atoi(p2.m);
    else{
        return p2.m[0] - p1.m[0];
    }
}

struct data s1[10001];
long long int p[10001];

int main()
{
    int T;
    scanf("%d", &T);
    int cnt = 0;
    while(T-->0){
        int N;
        scanf("%d\n", &N);
        for(int i = 0;i < N;i++){
            scanf("%lld",&p[i]);
        }//把整数输入进去
        //sprintf(str,"%ld",ii); 把整数ii转化为字符串并储存在str中
        long long int s[10001];//转化成字符串储存起来
        for(int i = 0;i < N;i++){
            if(p[i] < 0){
                s[i] = -p[i];
                break;
            }
            else{
                s[i] = p[i];
            }
        }//全是正数了
        for(int j =0;j < N;j++){
            sprintf(s1[j].m,"%lld",s[j]);
        }//s1里面都是字符串
        //printf("%s",s1[0].m);
        qsort(s1,N,sizeof(char),cmp);
        printf("case #%d:\n",cnt);
        for(int i = 0;i < N;i++){
            printf("%s\n",s1[i].m);
        }
        cnt++;
    }
}
