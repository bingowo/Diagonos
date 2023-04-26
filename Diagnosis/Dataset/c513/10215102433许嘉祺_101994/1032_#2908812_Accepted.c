#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b){
    char *p1=*(char(*)[600])a,*p2=*(char(*)[600])b;
    int a1[50],b1[50];
    int na=0,nb=0;
    memset(a1,0,sizeof(a1));
    memset(b1,0,sizeof(b1));
    for (int i=0;i<strlen(p1)-2;i++)
    if (p1[i]==' ') na++;
        else a1[na]=a1[na]*10+p1[i]-'0';
    for (int i=0;i<strlen(p2)-2;i++)
    if (p2[i]==' ') nb++;
    else b1[nb]=b1[nb]*10+p2[i]-'0';
    int i=0;
    while (i<na&&i<nb)
        if (b1[i]>a1[i]) return 1;
        else if (b1[i]<a1[i]) return -1;
        else {i++;if (i==na) return 1;if(i==nb)return -1;}
}


int main()
{
    int t;
    scanf("%d",&t);
    char s[1000][600];
    for (int i=0; i<t; i++)
    {
        int n;
        scanf("%d",&n);
        char c=getchar();
        for (int j=0; j<n; j++) gets(s[j]);
        qsort(s,n,sizeof(s[0]),cmp);
        for (int j=0; j<n; j++)
        {
            for (int k=0; k<strlen(s[j])-3; k++)
                printf("%c",s[j][k]);
            printf("\n");
        }
    }
    return 0;
}
