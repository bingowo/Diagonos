#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char table []="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz";
int cmp (const void *a,const void *b)
{
    char *A=*(char**)a;
    char *B=*(char**)b;
    int i=0;
    while (A[i]!='@')
    {
        i++;
    }
    i++;
    int j=0;
    while (B[j]!='@')
    {
        j++;
    }
    j++;
    if (strchr(table,A[i])>strchr(table,B[j])) return 1;
    else if (strchr(table,A[i])<strchr(table,B[j])) return -1;
    else
    {
        i=0;j=0;
        if (strchr(table,A[i])<strchr(table,B[j])) return 1;
        else if (strchr(table,A[i])>strchr(table,B[j])) return -1;
        else
        {
            while (strchr(table,A[i])==strchr(table,B[j]))
                   {
                       i++;j++;
                       if (strchr(table,A[i])<strchr(table,B[j])) return 1;
                       else if (strchr(table,A[i])>strchr(table,B[j])) return -1;

                   }
        }
    }

}
int main()
{ int n;
scanf ("%d",n);
char **s,c;
    s=(char**)malloc(sizeof(char*)*(n+1));
    int i=0;
for (int k=0;k<n;k++)
{

    int j=0;
    s[i]=(char*)malloc(sizeof(char)*(10000));
    getchar();
    scanf ("%c",&c);
    while (c!='\n')
        {s[i][j++]=c;
         scanf ("%c",&c);
        }
    i++;

}
qsort(s,i+1,sizeof(s[0]),cmp);
for (int p=0;p<n-1;p++)
{
    printf("%s\n",s[p]);
}
for (int p=0;p<n;p++) free(s[i]);
free(s);
return 0;
}
