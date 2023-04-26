#include <stdio.h>
#include <stdlib.h>
static char dic[255];   
int cmp(const void *a, const void *b){
    char *pa, *pb;
    pa = (char*)a, pb = (char*)b;
    while(pa && pb){
        char tempA = *pa, tempB = *pb;
        if(dic[tempA] > dic[tempB]) return 1;
        if(dic[tempA] < dic[tempB]) return -1;
        pa++,pb++;
    }
    if(pa) return -1;
    if(pb) return 1;
    return 0;
}

int main()
{
    char c;

    while((c=getchar()) != EOF){
        /**< initialize */
        char str[101][21];
        int i = 0,j = 0;
        dic[c] = 1;
        dic[c-'A'+'a'] = 1;
        for(int k = 2; k <= 26; k++){  
            c=getchar();
            dic[c] = k;
            dic[c-'A'+'a'] = k;
        }
        c=getchar();   
        while((c = getchar()) != '\n'){
            if(c == ' ') {
                c = getchar();
                str[i++][j] = '\0';
                j = 0;
            }
            str[i][j++] = c;
        }
        str[i++][j] = '\0';
        qsort(str,i,sizeof(str[0]),cmp);
        printf("%s",str[0]);
        for(int k = 1; k < i; k++){
            printf(" %s",str[k]);
        }
        printf("\n");
    }
    return 0;
}