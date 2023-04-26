#include<stdio.h>
#include<string.h>

void DivMod(int N, int R, char *res, char *table){
    int i = 0;
    do{
        res[i++] = table[N % R];
        N /= R;
    }while(N);
    res[i] = '\0';
}

void reverse(char *res){
    int lo = 0, hi = strlen(res) - 1;
    while(lo <= hi){
        int temp = res[lo];
        res[lo++] = res[hi];
        res[hi--] = temp;
    } 
}

void Print(char *res, int sig){
    if (sig) printf("-");
    for (int i = 0; res[i] && printf("%c", res[i]); ++i);
    printf("\n");
}

int main(){
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char res[100] = {0};
    int T; scanf("%d", &T);
    for (int i = 0; i != T; ++i){
        int N, R; scanf("%d%d", &N, &R);
        int sig = 0;
        if (N < 0){
            sig = 1;
            N = -N;
        }
        DivMod(N, R, res, table);
        reverse(res);
        Print(res, sig);
    }
    return 0;
}