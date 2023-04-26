#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 101
#define M 301

typedef struct{ //for easier, use array instead of pointer
    char ori[M];
    char y[M];    //yuming
}LINK;

int cmp(const void *one, const void *two){
    LINK a = *(LINK*)one, b = *(LINK*)two;
    if(strcmp(a.y,b.y) != 0) return strcmp(a.y,b.y);
    else return strcmp(a.ori,b.ori);
}

int main()
{
    int R,T;
    scanf("%d",&T);

    LINK link[N];
    int cnt = 0;

    for(R = 0; R < T; R++){
        char s[M];
        scanf("%s",s);

        //check http or https
        if(s[4] == 's') continue;

        int len = strlen(s);
        strcpy(link[cnt].ori, s);

        for(int i = 8; i < len; i++){
            if(s[i] == '/'){
                strncpy(link[cnt++].y, s,i);
                break;
            }
        }
    }

    qsort(link,cnt,sizeof(LINK),cmp);

    for(int i = 0; i < cnt; i++){
        printf("%s\n",link[i].ori);
    }

    return 0;
}
