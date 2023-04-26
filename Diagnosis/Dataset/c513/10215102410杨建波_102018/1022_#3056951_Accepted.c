#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct address{
    char* name;
    char* domain;
};

int cmp(const void *a, const void *b){
    struct address p1,p2;
    p1 = *(struct address*)a;
    p2 = *(struct address*)b;
    if(strcmp(p1.domain, p2.domain) == 0)
    return strcmp(p2.name, p1.name);
    else return strcmp(p1.domain, p2.domain);
}

int main(){
    int n;
    scanf("%d",&n);
    struct address* ad ;
    ad = (struct address*)malloc(sizeof(struct address)*n);
    char s[1000001], *p;
    int len;
    for(int j = 0;n > j;j++){
        scanf("%s",s);
        len = strlen(s);
        int i = 0;
        while(s[i] != '@')i++;
        s[i] = '\0';
        p = (char*)malloc(sizeof(char)*(i+1));
        strcpy(p,s);
        
        ad[j].name = p;

        // printf("1:%s\n",ad[j].name);

        p = (char*)malloc(sizeof(char)*(len-i));
        strcpy(p, s+i+1);
        
        ad[j].domain = p;
        
        // printf("2:%s\n",ad[j].domain);
    }
    qsort(ad,n,sizeof(struct address),cmp);
    // printf("\n");
    for(int i = 0;i < n;i++){
        printf("%s@%s\n",ad[i].name,ad[i].domain);
    }
    for(n;n>0;n--){
        free(ad[n-1].name);
        free(ad[n-1].domain);
    }
    free(ad);
}