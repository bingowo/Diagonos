#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[21];
    int len;
}S;

int cmp(const void *a,const void *b)
{
    S x=*(S*)a;
    S y=*(S*)b;
    if(x.len!=y.len)return y.len-x.len;
    else return strcmp(x.s,y.s);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        S a[101];
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%s",a[j].s);
            a[j].len=0;
            char key[128]={0};
            for(int k=0;a[j].s[k]!=0;k++){
                if(key[(int)a[j].s[k]]==0){
                        a[j].len++;
                        key[(int)a[j].s[k]]=1;
                }
            }
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++){
            printf("%s\n",a[j].s);
        }
    }
    return 0;
}
