#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    char ban[3][15] = {"a","of an","the for and"};
    for(int i=0; i<T; ++i) {
        char c;
        int cnt = 0;
        do{
            char word[101];
            scanf("%s",word);
            int k = strlen(word);
            if(k<=3 && strstr(ban[k-1], word))
                continue;
            ++cnt;
        }while((c=getchar()) != '\n');
        printf("case #%d:\n%d\n",i,cnt);
    }
    return 0;
}
