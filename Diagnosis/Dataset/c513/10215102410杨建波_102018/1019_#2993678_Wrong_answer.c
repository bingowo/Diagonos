#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int cmp(const void *a,const void *b);
struct que{
    int num;
    int score ;
    int win ;
    int lose ;
};
int main(){
    int n, m;
    scanf("%d %d",&n, &m);
    while(n && m){
        struct que *p = (struct que*)malloc(n*sizeof(struct que));
        for(int i = 0;i < n;i++){
            (*(p+i)).num = i+1;
            (*(p+i)).score = 0;
            (*(p+i)).win = 0;
            (*(p+i)).lose = 0;
        }
        int a, b, c;
        for(m; m > 0; m--){
            scanf("%d %d %d",&a, &b, &c);
            if(c == 1){
                (*(p+a-1)).score += 3;
                (*(p+a-1)).win++;
                (*(p+b-1)).score--;
                (*(p+b-1)).lose++;
            }
            else if(c == -1){
                (*(p+a-1)).score--;
                (*(p+a-1)).lose++;
                (*(p+b-1)).score += 3;
                (*(p+b-1)).win++;
            }
            else {
                (*(p+a-1)).score++;
                (*(p+b-1)).score++;
            }
        }
        qsort(p , n, sizeof(struct que), cmp);
        for(int i = 0; i < n;i++)
            printf("%d ",(*(p+i)).num);
        printf("\n");
        free(p);
        p = NULL;
    }
}

int cmp(const void *a,const void *b){
    if((*(struct que*)a).score > (*(struct que*)b).score)
        return -1;
    else if((*(struct que*)a).score < (*(struct que*)b).score)
        return 1;
    else if((*(struct que*)a).win > (*(struct que*)b).win)
        return -1;
    else if((*(struct que*)a).win < (*(struct que*)b).win)
        return 1;
    else if((*(struct que*)a).lose < (*(struct que*)b).lose)
        return -1;
    else if((*(struct que*)a).lose > (*(struct que*)b).lose)
        return 1;
    else if((*(struct que*)a).num > (*(struct que*)b).num)
        return 1;
    else return -1;
}