#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

typedef long long ll;
typedef unsigned long long ull;

#define N 505
char tab[N][N];
char str[N],*wrd;
int r[N];
int n;

void Init(){
    n=0;
    for(int i=0;i<N;i++) r[i]=i;
}

int Find(){
    for(int i=0;i<n;i++)
        if(!strcmp(wrd,tab[i]))
            return 1;
    return 0;
}

int Cmp(const int* pa, const int* pb){
    return strcmp(tab[*pa],tab[*pb]);
}

int main(){
    int pros;
    scanf("%d",&pros);
    gets(str);
    for(int cnt=0;cnt<pros;cnt++){
        Init();
        gets(str);
        wrd=strtok(str," ,.!?");
        strcpy(tab[n++],wrd);
        while(wrd=strtok(NULL," ,.!?")){
            if(!Find()){
                strcpy(tab[n],wrd);
                n++;
            }
        }
        qsort(r,n,sizeof(r[0]),Cmp);

        printf("case #%d:\n",cnt);
        for(int i=0;i<n;i++){
            if(i) printf(" ");
            printf("%s",tab[r[i]]);
        }
        printf("\n");
    }

    return 0;
}
