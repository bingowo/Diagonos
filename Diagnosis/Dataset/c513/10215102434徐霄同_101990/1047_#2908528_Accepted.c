#include <stdio.h>
#include <string.h>
typedef struct{
    char c;
    int n;
}rle;
int main()
{
    rle a[500];
    char s[501];
    int i,j,l,t,n;
    scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++){
        gets(s);
        l=strlen(s);
        n=0;
        a[0].c=s[0];
        a[0].n=1;
        for(j=1;j<l;j++){
            if(s[j]==a[n].c && a[n].n<255)
                a[n].n++;
            else{
                n++;
                a[n].c=s[j];
                a[n].n=1;
            }
        }
        printf("case #%d:\n",i);
        for(j=0;j<=n;j++)
            printf("%d%c",a[j].n,a[j].c);
        printf("\n");
    }
    return 0;
}
