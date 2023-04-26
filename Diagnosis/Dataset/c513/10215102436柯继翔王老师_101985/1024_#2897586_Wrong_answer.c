#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int N,M,G;
    int a[10];
    struct student{
        char number[12];
        int score;
    }stu[500],ans[500];
    for(int i = 0;i < T;i++){
        scanf("%d%d%d",&N,&M,&G);
        for(int j = 0;j < M;j++){
            scanf("%d",&a[j]);
        }
        for(int j = 0;j < N;j++){
            int n,m;
            scanf("%s %d",stu[j].number,&n);
            stu[j].score = 0;
            for(int k = 0;k < n;k++){
                scanf("%d",&m);
                stu[j].score += a[m - 1];
            }
        }
        int count = 0;
        for(int j = 0;j < N;j++){
            if(stu[j].score >= G)ans[count++] = stu[j];
        }
        for(int j = 0;j < count - 1;j++){
            for(int k = j;k < count;k++){
                if(ans[k].score < ans[k + 1].score){
                    struct student temp = ans[k];
                    ans[k] = ans[k + 1];
                    ans[k + 1] = temp;
                }else if(ans[k].score == ans[k + 1].score){
                    if(strcmp(ans[k].number,ans[k + 1].number) > 0){
                        struct student temp = ans[k];
                        ans[k] = ans[k + 1];
                        ans[k + 1] = temp;
                    }
                }
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",count);
        for(int j = 0;j < count;j++){
            printf("%s %d\n",ans[j].number,ans[j].score);
        }
    }
    return 0;
}
