#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

typedef struct
{int nian;
int yue;
int ri;
int shi;
int fen
int size;
char* name;
}FILE;

Input*(int n)
{
    FILE*s;
    s=(FILE*)malloc(n*sizeof(FILE));
    for(int i=0;i<n;i++)
    {scanf("%d-%d-%d %d:%d",
    &s[i],nian,&s[i].yue,&s[i].ri,&s[i].shi,&s[i].fen);
     scanf("%d %s",&s[i].size,&s[i].name);}
}

void SORTTIME(FILE*a,int n)
{int comparetime(const void*a1,const void*a2)
{
   FILE a=*(FILE*)a1;
   FILE b=*(FILE*)a2;
   if(a.nian!=b.nian) return a.nian-b.nian;
   else if(a.yue!=b.yue) return a.yue-b.yue;
   else if(a.ri!=b.ri) return a.ri=b.ri;
   else if(a.shi!b.shi) return a.shi-b.shi;
   else if(a.fen!=b.fen) return a.fen-b.fen;
   else return stricmp(a.name,b.name);
}
qsort(a,n,sizeof(FILE),comparetime);
}
void SORTSIZE(FILE*a,int n)
{int comparesize(const void*a1,const void*a2)
{
   FILE a=*(FILE*)a1;
   FILE b=*(FILE*)a2;
   if(a.size!=b.size) return a.size-b.size;
   else return stricmp(a.name,b.name);
}
qsort(a,n,sizeof(FILE),comparesize);
}
void SORTNAME(FILE*a,int n)
{int comparename(const void*a1,const void*a2)
{
   FILE a=*(FILE*)a1;
   FILE b=*(FILE*)a2;
   return stricmp(a.name,b.name);
}
qsort(a,n,sizeof(FILE),comparename);
}
void OUTPUT(FILE*a,int n)
{
    for(int k=0;k<n;k++)
        {printf("%d-%d-%d %d:%d ",
        a[k].nian,a[k].yue,a[k].ri,a[k].shi,a[k].fen);
        int count=0,l=a[k].size;
        for(l!=0)
        {
            l=l/10;
            count++;
        }
        for(int k=0;k<16-count;k++) printf(" ");
        print("%d %s",a[k].size,a[k].name);}

}
int main()
{
   int n;
   while((scanf("%d\n",&n))!=EOF)
   {
       FILE *s=NULL;
       s=Input(n);
       char c,d,e,f;
       scanf("LIST /%c%c%c%c\n",&c,&d,&e,&f);
       if(c=='N') SORTNAME(s,n);
       if(c=='S') SORTSIZE(s,n);
       if(c=='T') SORTTIME(s,n);
       OUTPUT(s,n);
       prinf("\n\n");
   }
   return 0;
}