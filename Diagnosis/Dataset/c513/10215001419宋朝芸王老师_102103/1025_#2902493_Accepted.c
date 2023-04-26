#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countDif(char *a){
    int alpha[26] = {0};
    int count = 0;
    char *p = a;

    while(*p){
        alpha[*p-'A'] = 1;
        p++;
    }

    for(int i = 0; i < 26; i++){
        count += alpha[i];
    }

    return count;
}

int cmp(const void *a, const void *b){
    char *pa = (char*)a, *pb = (char*)b;

    if(countDif(pa) != countDif(pb))
        return (countDif(pb) - countDif(pa));
    else return strcmp(pa,pb);
}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R <T; R++){
        int n;
        scanf("%d",&n);

        char input[101][21];
        for(int i = 0; i < n; i++){
            scanf("%s",input[i]);
        }

        qsort(input,n,sizeof(input[0]),cmp);

        printf("case #%d:\n",R);
        for(int i = 0; i < n; i++){
            printf("%s\n",input[i]);
        }
    }
    return 0;
}
