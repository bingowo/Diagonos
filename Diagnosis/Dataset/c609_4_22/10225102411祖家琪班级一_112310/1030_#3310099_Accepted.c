#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    double freq;
    char c;
} letter;
int cmp(const void*a,const void*b)
{
    letter *pa,*pb;
    pa = (letter*)a;
    pb = (letter*)b;
    if(pa->freq != pb->freq){
        if(pa->freq > pb->freq) return -1;
        else return 1;
    }
    else{
        if(pa->c-pb->c == 'A' - 'a' || pa->c-pb->c == 'a' - 'A') return pb->c-pa->c;
        else return tolower(pa->c)-tolower(pb->c);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        double table[26];
        int cnt=0;
        do{
            scanf("%lf",&table[cnt++]);
        }while(getchar() == ' ');
        char s[101];
        scanf("%s",s);
        int l = strlen(s);
        letter L[l];
        for(int j=0;j<l;j++){
            L[j].c = s[j];
            if(islower(s[j])) L[j].freq = table[s[j]-'a'];
            else L[j].freq = table[s[j] - 'A'];
        }
        qsort(L,l,sizeof(letter),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<l;j++){
            printf("%c",L[j].c);
        }
        if(i-T+1) printf("\n");
    }
    return 0;
}
