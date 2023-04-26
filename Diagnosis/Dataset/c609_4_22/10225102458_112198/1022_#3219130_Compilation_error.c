#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{char *a;char *b;char *ab;}str;
int cmp(const void*a,const void* b)
{
    str* aa=(str*)a;
    str* bb=(str*)b;
    if(strcmp(aa->b,bb->b)==0){
        return -strcmp(aa->a,bb->a);
    }
    else return strcmp(aa->b,bb->b);
}
int main()
{
    int n,cnt;
    scanf("%d",&n);
    getchar();
    str *s=(str*)malloc(sizeof(str)*n);
    char ss[1000001];
    for(int i=0;i<n;i++){
        scanf("%s",ss);
        int dex=0;
        for(int i=0;i<strlen(ss);i++){
        if(ss[i]=='@'){cnt=i;break;}
        }
        char* m=(char*)malloc(sizeof(char)*strlen(ss)+1);
        char* n=(char*)malloc(sizeof(char)*strlen(ss)+1);
        char* mn=(char*)malloc(sizeof(char)*strlen(ss)+1);
        strcpy(mn,ss);
        for(int i=cnt+1;i<strlen(ss)+1;){n[dex++]=ss[i++];}
        ss[cnt]='0';
        strcpy(m,ss);
        s[i].a=m;
        s[i].b=n;
        s[i].ab=mn;

    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(int j=0;j<n;j++){
        printf("%s%s\n",s[j].a，s[j].b);
    }
    free(s);
    return 0;

}
