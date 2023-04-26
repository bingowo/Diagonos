#include <stdio.h>
#include <stdlib.h>

// 0 0 represents eof

typedef struct{
    int score = 0;
    //int rank;
    int wins = 0;
    int loses = 0;
    int number;
} TEAMS;

int cmp(const void *a, const void *b){
    //rules:1.score big 2.wins big 3. loses small 4. number small
    TEAMS* A = (TEAMS*)a;
    TEAMS* B = (TEAMS*)b;

    if(A->score > B->score) return -1;
    if(A->score < B->score) return 1;

    if(A->wins > B->wins) return -1;
    if(A->wins < B->wins) return 1;

    if(A->loses > B->loses) return 1;
    if(A->loses < B->loses) return -1;

    if(A->number > B->number) return 1;
    if(A->number < B->number) return -1;

    return 0;
}

int main()
{
    int teams, matches;
    while(scanf("%d%d",&teams,&matches) != EOF && teams != 0 && matches != 0){
        TEAMS* input;
        input = (TEAMS*)malloc(teams*sizeof(TEAMS));

        for(int i = 0; i < teams; i++){
            input[i].number = i+1;
        }

        for(int i = 0; i < matches; i++){
            int a, b, c;
            scanf("%d%d%d",&a,&b,&c);

            if(c == 0){
                input[a].score ++;
                input[b].score ++;
            }
            if(c > 0){
                input[a].score += 3;
                input[a].wins ++;
                input[b].score -= 1;
                input[b].loses ++;
            }
            if(c < 0){
                input[a].score -= 1;
                input[a].loses ++;
                input[b].score += 3;
                input[b].wins ++;
            }
        }

        TEAMS* p = input;
        qsort(p,teams,sizeof(TEAMS),cmp);

        printf("%d",input[0].number);
        for(int i = 1; i < teams; i++){
            printf(" %d",input[i].number);
        }
        printf("\n");
    }

    return 0;
}
