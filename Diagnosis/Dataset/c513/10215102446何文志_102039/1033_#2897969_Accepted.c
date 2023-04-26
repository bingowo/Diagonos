#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct MayaTmie
{
    char s[30];
    char month[10];
    int d;
    int m;
    int y;
}mayaTime;

int getMonth(char s[])
{
    if(strcmp(s,"pop")==0){return 0;}
    else if(strcmp(s,"no")==0){return 1;}
    else if(strcmp(s,"zip")==0){return 2;}
    else if(strcmp(s,"zotz")==0){return 3;}
    else if(strcmp(s,"tzec")==0){return 4;}
    else if(strcmp(s,"xul")==0){return 5;}
    else if(strcmp(s,"yoxkin")==0){return 6;}
    else if(strcmp(s,"mol")==0){return 7;}
    else if(strcmp(s,"chen")==0){return 8;}
    else if(strcmp(s,"yax")==0){return 9;}
    else if(strcmp(s,"zac")==0){return 10;}
    else if(strcmp(s,"ceh")==0){return 11;}
    else if(strcmp(s,"mac")==0){return 12;}
    else if(strcmp(s,"kankin")==0){return 13;}
    else if(strcmp(s,"muan")==0){return 14;}
    else if(strcmp(s,"pax")==0){return 15;}
    else if(strcmp(s,"koyab")==0){return 16;}
    else if(strcmp(s,"cumhu")==0){return 17;}
    else if(strcmp(s,"uayet")==0){return 18;}
    return -1;
}

int cmp(const void *a,const void *b)
{
    mayaTime A = *(mayaTime*)a,B = *(mayaTime*)b;
    if(A.y!=B.y){return A.y-B.y;}
    else if(A.m!=B.m){return A.m-B.m;}
    else {return A.d - B.d;}
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        int N = 0;
        scanf("%d",&N);
        getchar();//important//
        mayaTime maya[N];memset(maya,0,N*sizeof(mayaTime));
        for(int j = 0;j<N;j++)
        {
            gets(maya[j].s);
            sscanf(maya[j].s,"%d. %[a-z] %d",&maya[j].d,maya[j].month,&maya[j].y);
            maya[j].m = getMonth(maya[j].month);
        }
        qsort(maya,N,sizeof(maya[0]),cmp);
        printf("case #%d:\n",i);
        for(int j = 0;j<N;j++)
        {
            //printf("%s, day = %d, month = %s, year = %d, m = %d\n"
                   //,maya[j].s,maya[j].d,maya[j].month,maya[j].y,maya[j].m);
            printf("%s\n",maya[j].s);
        }
    }
    return 0;
}
