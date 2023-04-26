#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long

struct email{
    char* a;
    char* b;
};

int cmp(const void* a, const void *b){
    struct email x, y;
    x = *((struct email *)a);
    y = *((struct email *)b);
    if (strcmp(x.b, y.b) == 0) return strcmp(y.a, x.a);
    return strcmp(x.b, y.b);
}



int main(){
    ll n;
    scanf("%lld ", &n);
    struct email *E = (struct email*)malloc(n*sizeof(struct email));
    for (ll k = 0; k < n; k++){
        char s[1000];
        gets(s);
        char *tempa = strtok(s, "@");
        char *tempb = strtok(NULL, s);
        // printf("%s@%s\n", tempa, tempb);
        E[k].a = NULL, E[k].b = NULL;
        E[k].a = (char*)realloc(E[k].a, sizeof(char)*(strlen(tempa)+1));
        E[k].b = (char*)realloc(E[k].b, sizeof(char)*(strlen(tempb)+1));
        strcpy(E[k].a, tempa);
        strcpy(E[k].b, tempb);
        if (tempa == NULL) free(tempa);
        if (tempb == NULL) free(tempb);
    }    
    qsort(E, n, sizeof(E[0]), cmp);
    for (ll i = 0; i < n; i++){
        printf("%s@%s\n", E[i].a, E[i].b);
    }
    free(E);
    return 0;
}