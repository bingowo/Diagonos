#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(char* s1, char* s2) {
    if(strlen(s1) > strlen(s2)) return 1;
    else if(strlen(s1) == strlen(s2))
        return strcmp(s1, s2);
    else return -1;
}

int sort_cmp(const void* a, const void* b) {
    char *s1 = *(char**)a, *s2 = *(char**)b;
    return cmp(s1, s2);
}

int bifind(char **dic, char *s, int end) {
    int start = 0, mid = (start+end) / 2;
    int t = cmp(dic[mid], s);
    while(start <= end) {
        if(t > 0) end = mid-1;
        else if(t < 0) start = mid+1;
        else return mid;
        mid = (start + end) / 2;
        t = cmp(dic[mid], s);
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    char **dic = (char**)malloc(4000*sizeof(char*));
    char s[5001];
    for(int i=0; i<n; ++i) {
        dic[i] = (char*)malloc(15);
        scanf("%s",dic[i]);
    }
    scanf("%s",s);
    qsort(dic, n,sizeof(dic[0]) , sort_cmp);
    int i = 0, maxl = strlen(dic[n-1]);
    while(s[i]) {
        char t[15]; int k = 0;
        for(; k<maxl && s[i+k]; ++k) t[k] = s[i+k];
        t[k] = '\0';
        int L = strlen(t);
        while(L > 1) {
            k = bifind(dic, t, n-1);
            if(k != -1) break;
            else t[--L] = '\0';
        }
        if(i) printf(" ");
        if(L == 1) printf("%c",t[0]);
        else {
            printf("%s",dic[k]);
        }
        i += L;
    }
    printf("\n");
    for(int i=0; i<n; ++i) free(dic[i]);
    free(dic);
    return 0;
}
