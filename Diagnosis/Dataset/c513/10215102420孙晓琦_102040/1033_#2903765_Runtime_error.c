# include<stdio.h>
# include<stdlib.h>
# include <string.h>
typedef struct
{
    int day;
    char* mouth;
    int mou;
    int year;
    int record;
}RECORD;

RECORD maya[10001];

char* mouths[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};


int mouthchange(char *mouth)
{
    for (int i=0;;i++)
    {
        if (!strcmp(mouth,mouths[i]))return i;
    }
}

int cmp(const void* a,const void* b)
{
    RECORD m1,m2;
    m1=*((RECORD *)a);
    m2=*((RECORD *)b);
    return (m1.record - m2.record);
}
int main()
{
   int t,n;
   scanf("%d",&t);
   for (int j=0;j<t;j++)
   {
       scanf("%d",&n);
       for (int i=0;i<n;i++)
       {
           scanf("%d. %c %d",&maya[i].day,maya[i].mouth,&maya[i].year);
           maya [i].mou=mouthchange(maya[i].mouth);
           maya[i].record=maya[i].year * 10000 + maya[i].mou * 100 + maya[i].day;
       }
        qsort(maya,n,sizeof(maya[0]),cmp);
        for (int i=0;i<n;i++)
        printf("%d. %c %d",maya[i].day,*maya[i].mouth,maya[i].year);
   }
   return 0;
}
