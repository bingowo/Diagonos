#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct
{
    char*p;int cnt;
}DNA;


int main()
{
    DNA*dna;int n,i;char**d;
    scanf("%d\n", &n);
    d=(char**)malloc(n*sizeof(char*));
    for(i=0;i<n;i++)scanf("%s\n",d[i]);
    int m = 0;
    dna = (DNA*)malloc(n*sizeof(DNA));
    dna[0].p = d[0];
    dna[0].cnt = 1;
    for(i=1;i<n;i++)
    {
        if(strcmp(d[i],d[i-1])==0)
            dna[m].cnt++;
        else
        {
            m++;
            dna[m].p = d[i];
            dna[m].cnt = 1;
        }
    }


    for(i=0;i<=m;i++)
        printf("%s\n",dna[i].p);
    free(dna);
    for(i=0;i<n;i++) free(d[i]);
    free(d);

}