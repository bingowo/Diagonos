#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char s[21];
    int num;
};

int countalpha(char *s);
int cmp(const void *a, const void *b);

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        int n;
        scanf("%d",&n);
        struct data d[100];
        for(int i = 0; i < n; i++){
            scanf("%s",d[i].s);
            d[i].num = countalpha(d[i].s);
        }
        qsort(d,n,sizeof(d[0]),cmp);
        printf("case #%d:\n", t);
		for (int i = 0; i < n; i++){
			printf("%s\n",d[i].s);
		}
    }
    return 0;
}

int countalpha(char *s){
    int allchar[256];
    int length = strlen(s);
    int count = 0;
    for(int i = 0; i < 256; i++){
        allchar[i] = 0;
    }
    for(int i = 0; i < length; i++){
        if(allchar[s[i]] == 0){
            allchar[s[i]] = 1;
            count++;
        }
    }

    return count;
}


int cmp(const void *a, const void *b){
    struct data d1;
    struct data d2;
    d1 = (*(struct data *)a);
    d2 = (*(struct data *)b);
    if(d1.num > d2.num){
        return -1;
    }else if (d1.num < d2.num){
        return 1;
    }else if(d1.num == d2.num){
        return strcmp(d1.s,d2.s);
    }
}
