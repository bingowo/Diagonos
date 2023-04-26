#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 21
#define R 200000

typedef struct{
    char s[M];
    int len;
    int time;
}DNA;

typedef struct{
    int cnt;
    int pos[R];
}INDEX;

int cmp(const void *one, const void *two){
    DNA a = *(DNA*)one, b = *(DNA*)two;
    if(a.time != b.time) return a.time - b.time;
    return strcmp(a.s,b.s);
}

int main()
{
    int n;  //ori num
    int i;  //real num
    scanf("%d",&n);

    DNA dna[R], temp;
    INDEX index[M];
    memset(dna,0,sizeof(DNA));
    memset(index,0,sizeof(INDEX));

    for(int k = 0; k < n; k++){
        scanf("%s",temp.s);
        int len = strlen(temp.s);

        int flag = 0;   //1 means repeat
        if(index[len].cnt != 0){
            for(int j = 0; j < index[len].cnt; j++){
                int pos = index[len].pos[j];
                if(temp.s[0] != dna[pos].s[0]) continue;
                if(strcmp(temp.s,dna[pos].s) == 0){
                    flag = 1;
                    dna[pos].time++;
                    break;
                }
            }
        }
        if(flag == 0){
            index[len].pos[index[len].cnt++] = i;
            dna[i].len = len;
            strcpy(dna[i].s,temp.s);
            dna[i++].time = 0;
        }

    }

    qsort(dna,i,sizeof(dna[0]),cmp);

    for(int k = 0; k < i; k++)
        printf("%s\n",dna[k].s);


    return 0;
}