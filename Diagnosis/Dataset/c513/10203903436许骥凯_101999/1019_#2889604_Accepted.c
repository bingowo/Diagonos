#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int id;
    int score;
    int win;
    int lost;
}Team;


void initial(Team *teams, int len){
    for (int i = 0; i != len; i++){
        teams[i].id = i + 1;
        teams[i].score = 0;
        teams[i].win = 0;
        teams[i].lost = 0;
    }
}

void judge(Team *teams, int t1, int t2, int res){
    if (res == 0) {teams[t1].score++; teams[t2].score++;}
    else if (res == 1) {teams[t1].score += 3, teams[t1].win++; teams[t2].score -= 1, teams[t2].lost++;}
    else{teams[t1].score -= 1, teams[t1].lost++; teams[t2].score += 3, teams[t2].win++;}
}

int compare(const void *p1, const void *p2){
    Team team1 = *(Team*)p1;
    Team team2 = *(Team*)p2;
    if (team1.score == team2.score){
        if (team1.win == team2.win){
            if (team1.lost == team2.lost)
                return team1.id - team2.id;
            return team1.lost - team2.lost;
        }
        return team2.win - team1.win;
    }
    return team2.score - team1.score;
}

void output(Team *teams, int len){
    for (int i = 0; i != len; i++)
        if (i != len - 1) printf("%d ", teams[i].id);
        else printf("%d\n", teams[i].id);
}

int main(){
    do{
        int num, occ;
        scanf("%d %d", &num, &occ);
        Team *teams = (Team *) malloc(sizeof(Team) * num);
        initial(teams, num);
        for (int i = 0; i != occ; i++){
            int t1, t2, res;
            scanf("%d%d%d", &t1, &t2, &res);
            t1--, t2--;
            judge(teams, t1, t2, res);
        }
        qsort(teams, num, sizeof(teams[0]), compare);
        output(teams, num);
        free(teams);
    }while(getchar() != EOF);
}