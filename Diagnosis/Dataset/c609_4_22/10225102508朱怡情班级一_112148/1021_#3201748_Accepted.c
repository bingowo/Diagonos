#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char s[30];
char key[100];

int cmp(const void* a,const void* b)
{
    char *x=(char*)a;
    char *y=(char*)b;
    for(int i=0;x[i]!=0&&y[i]!=0;i++){
        int n=(int)toupper(x[i]);
        int m=(int)toupper(y[i]);
        if(key[n]!=key[m])return key[n]-key[m];
    }
    return strlen(x)-strlen(y);
}

int main()
{
    for(int i=65;i<92;i++)key[i]=-1;
    while(scanf("%s",s)!=EOF){
        for(int i=0;s[i]!=0;i++){
            int pos=(int)s[i];
            key[pos]=i;
        }
        char n[109][109];
        int k=0;
        while(scanf("%s",n[k])){
            k++;
            if(getchar()=='\n')break;
        }
        qsort(n,k,sizeof(n[0]),cmp);
        for(int j=0;j<k;j++){
            printf("%s ",n[j]);
        }
        printf("\n");
    }
    return 0;
}
