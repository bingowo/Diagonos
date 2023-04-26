#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*a,const void *b)
{
    return (*(int*)a)-(*(int*)b);
}
void move(char *a,char* b)
{
    int i,j,n,m;
    for(j = 0;j<strlen(b);j++)
    {n = 0;
    for(i = 0;i<strlen(a);i++)
    {
        if(a[i]==b[j]) {m = i;break;}
    }
    for(i = 0;i<strlen(a);i++)
    {
        if(i!=m) a[n++] = a[i];
    }
    a[n] = '\0';

    } //printf("%s ",a);
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(j = 0;j<T;j++)
    {
        char s[21];
        scanf("%s",s);
        int a[7],n = 0;
        while(strlen(s)!=0)
        {
            if(strchr(s,'Z')!=NULL) {a[n++] = 0;move(s,"ZERO");}
            else if(strchr(s,'W')!=NULL) {a[n++] = 2;move(s,"TWO");}
            else if(strchr(s,'U')!=NULL) {a[n++] = 4;move(s,"FOUR");}
            else if(strchr(s,'X')!=NULL) {a[n++] = 6;move(s,"SIX");}
            else if(strchr(s,'G')!=NULL) {a[n++] = 8;move(s,"EIGHT");}
            else if(strchr(s,'O')!=NULL) {a[n++] = 1;move(s,"ONE");}
            else if(strchr(s,'H')!=NULL) {a[n++] = 3;move(s,"THREE");}
            else if(strchr(s,'F')!=NULL) {a[n++] = 5;move(s,"FIVE");}
            else if(strchr(s,'V')!=NULL) {a[n++] = 7;move(s,"SEVEN");}
            else {a[n++] = 9;move(s,"NINE");}
        }
        qsort(a,n,4,cmp);
        printf("case #%d:\n",j);
        for(i = 0;i<n;i++)
            printf("%d",a[i]);
        printf("\n");

    }
    return 0;
}
