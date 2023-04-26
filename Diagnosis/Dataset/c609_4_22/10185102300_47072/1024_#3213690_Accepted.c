#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {  char s[100],name[64],time[17]; int size; } FILEINFO;

int namecmp(const void* e1,const void* e2)
{  FILEINFO *p1=(FILEINFO*)e1,*p2=(FILEINFO*)e2;
    return strcmp(p1->name,p2->name);
}

int sizecmp(const void* e1,const void* e2)
{  FILEINFO *p1=(FILEINFO*)e1,*p2=(FILEINFO*)e2; int delta;
    return (delta=p1->size - p2->size) ? delta : namecmp(e1,e2);
}

int timecmp(const void* e1,const void* e2)
{  FILEINFO *p1=(FILEINFO*)e1,*p2=(FILEINFO*)e2; int delta;
    return (delta=strcmp(p1->time,p2->time)) ? delta : namecmp(e1,e2);
}


void parse(FILEINFO *x)
{  int i=0,j=0;
    for (i=0;i<16;i++) x->time[j++]=x->s[i];x->time[j]=0;
    x->size=0;
    while (!isdigit(x->s[i])) i++;
    while (isdigit(x->s[i]))  x->size=x->size*10+x->s[i++]-'0';
    strcpy(x->name,x->s+i+1);
}

int main()
{  int i,n; FILEINFO a[10000];
           while(scanf("%d\n",&n),n)
           { char cmd[20];
               for  (i=0;i<n;i++)  fgets((a+i)->s,100,stdin),parse(a+i);
              fgets(cmd,12,stdin);
              if (strstr(cmd,"LIST /NAME")) qsort(a,n,sizeof(a[0]),namecmp);
              if (strstr(cmd,"LIST /SIZE")) qsort(a,n,sizeof(a[0]),sizecmp);
              if (strstr(cmd,"LIST /TIME")) qsort(a,n,sizeof(a[0]),timecmp);
 //             for  (i=0;i<n;i++)  printf("%s %s %d %s", (a+i)->s,(a+i)->time,(a+i)->size, (a+i)->name);
              for  (i=0;i<n;i++)  printf("%s", (a+i)->s);
              printf("\n");
           }


    return 0;
}