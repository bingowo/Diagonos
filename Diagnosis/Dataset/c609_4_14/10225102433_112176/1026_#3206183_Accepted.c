#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int kinds;
    char s[21];
}st;

int cmp(const void *a,const void *b)
{
    int pa = (*(st*)a).kinds;
    int pb = (*(st*)b).kinds;
    char *A = (*(st*)a).s;
    char *B = (*(st*)b).s;
    int res = strcmp(A,B);
    if(pa != pb){
        return pb-pa;
    }
    else{
        return res;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        int l;
        scanf("%d",&l);
        st a[l];
        for(int j = 0;j < l;j++){
            scanf("%s",a[j].s);
            char S[21] = {0};
            strcpy(S,a[j].s);
            a[j].kinds = 0;
            unsigned res = strlen(a[j].s);
            if(res == 1){
                a[j].kinds = 1;
            }
            else{
                for(int k = 0;k < res-1;k++){
                    for(int h = k+1;h < res;h++){
                        if(S[k] == S[h]){
                            S[h] = '1';
                        }
                    }
                }
                for(int y = 0;y < res;y++){
                    if(S[y] != '1'){
                        a[j].kinds++;
                    }
                }
            }
        }
        qsort(a,l,sizeof*a,cmp);
        printf("case #%d:\n",i);
        for(int p = 0;p < l;p++){
            printf("%s\n",a[p].s);
        }
    }

    return 0;
}