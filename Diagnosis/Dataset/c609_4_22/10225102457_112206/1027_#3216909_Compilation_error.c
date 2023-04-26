#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int cmp(const void *p1,const void *p2);
typedef struct{
    long long num;
    int T;
    int score[11];
}STUDENT;

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int i = 0; i < T; i++){
        int N,M,G;
        scanf("%d%d%d",&N,&M,&G);
        
        STUDENT data[N];
        for(int v = 0; v < N; v++){
            scanf("%lld",data[v].num);
            scanf("%d",)
        }
        /*char input[110];
        scanf("%s",input);

        qsort(input,strlen(input),sizeof(char),cmp);

        printf("case #%d:\n",i);
        printf("%s\n",input);*/
    }

    return 0;
}


int cmp(const void *p1,const void *p2)
{
    
}
