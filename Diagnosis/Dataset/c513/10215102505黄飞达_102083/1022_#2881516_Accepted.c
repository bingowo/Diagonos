#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long

//char s[1000000];

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
    scanf("%lld", &n);
    struct email *E = NULL;
    char c = getchar();
    for (ll k = 0; k < n; k++){
        char *temp = NULL;
        char *tempa = NULL;
        char *tempb = NULL;
        ll index = 0;
        c = getchar();
        while (c != '\n'){
            temp = (char*)realloc(temp, sizeof(char)*(index+2));
            temp[index++] = c;
            c = getchar();
        }
        temp[index++] = '\0';
        E = (struct email*)realloc(E, n*sizeof(struct email));
        E[k].a = NULL, E[k].b = NULL;
        ll i, j, templen = strlen(temp);
        for (i = 0; temp[i] != '@'; i++){
            tempa = (char*)realloc(tempa, sizeof(char)*(i+1));
            tempa[i] = temp[i];
        }
        tempa = (char*)realloc(tempa, sizeof(char)*(i+2));
        tempa[i] = '\0';
        i++;
        for (j = i; j < templen; j++){
            tempb = (char*)realloc(tempb, sizeof(char)*(j-i+1));
            tempb[j-i] = temp[j];
        }
        tempb = (char*)realloc(tempb, sizeof(char)*(j-i+2));
        tempb[j-i] = '\0';
        //printf("%s@%s\n", tempa, tempb);
        E[k].a = (char*)realloc(E[k].a, sizeof(char)*(strlen(tempa)+1));
        E[k].b = (char*)realloc(E[k].b, sizeof(char)*(strlen(tempb)+1));
        strcpy(E[k].a, tempa);
        strcpy(E[k].b, tempb);
        free(temp);
        free(tempa);
        free(tempb);
    }    
    qsort(E, n, sizeof(E[0]), cmp);
    for (ll i = 0; i < n; i++){
        printf("%s@%s\n", E[i].a, E[i].b);
    }
    free(E);
    return 0;
}