#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float v[58];

int cmp(const void *a,const void *b){
    char *x=(char*)a;
    char *y=(char*)b;
    if(v[*x-'A']!=v[*y-'A']) return v[*y-'A']-v[*x-'A'];
    else{
        return *y-*x;
    }
}


int main()
{
   int t;
   scanf("%d",&t);
   //float v[58]={0};
   for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        for(int j=0;j<26;j++){
            scanf("%f",&v[j]);
            v[j+32]=v[j];
        }
        char s[101];
        scanf("%s",s);
        int len;
        len=strlen(s);
        qsort(s,len,sizeof(s[0]),cmp);
        printf("%s\n",s);
   }
    return 0;
}
