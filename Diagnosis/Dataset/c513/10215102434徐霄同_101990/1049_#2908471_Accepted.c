#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    char *a0=(char*)a;
    char *b0=(char*)b;
    return strcmp(a0,b0);
}
int main()
{
    char w[501][501];
    char s[501],c[501];
    int t,i,j,k,p,l,n,f;
    scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++){
        gets(s);
        l=strlen(s);
        n=0;
        memset(c,0,sizeof(c));
        k=0;
        for(j=0;j<=l;j++){
            if(j<l && s[j]!=' ' && s[j]!=',' && s[j]!='.' && s[j]!='!' && s[j]!='?'){
                c[k]=s[j];
                k++;
            }
            else if(k!=0){
                f=0;
                for(p=0;p<n;p++)
                    if(strcmp(w[p],c)==0)
                        f=1;
                if(f==0){
                    strcpy(w[n],c);
                    n++;
                }
                k=0;
                memset(c,0,sizeof(c));
            }
        }
        qsort(w,n,sizeof(w[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++){
            printf("%s",w[j]);
            if(j==n-1)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}
