#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

typedef struct
{int nian;
int yue;
int ri;
int shi;
int fen;
int size;
char* name;
}TEAM;
//建立
TEAM*Input(int n)
{
    TEAM*s;
    s=(TEAM*)malloc(n*sizeof(TEAM));
    for(int i=0;i<n;i++)
    {scanf("%d-%d-%d %d:%d",
    &s[i].nian,&s[i].yue,&s[i].ri,&s[i].shi,&s[i].fen);
     scanf("%d %s",&s[i].size,s[i].name);}
}
//输入

void SORTTIME(TEAM*a,int n)
{int comparetime(const void*a1,const void*a2)
{
   TEAM a=*(TEAM*)a1;
   TEAM b=*(TEAM*)a2;
   if(a.nian!=b.nian) return a.nian-b.nian;
   else if(a.yue!=b.yue) return a.yue-b.yue;
   else if(a.ri!=b.ri) return a.ri=b.ri;
   else if(a.shi!=b.shi) return a.shi-b.shi;
   else if(a.fen!=b.fen) return a.fen-b.fen;
   else return strcmp(a.name,b.name);
}
qsort(a,n,sizeof(TEAM),comparetime);
}
//时间比较
void SORTSIZE(TEAM*a,int n)
{int comparesize(const void*a1,const void*a2)
{
   TEAM a=*(TEAM*)a1;
   TEAM b=*(TEAM*)a2;
   if(a.size!=b.size) return a.size-b.size;
   else return strcmp(a.name,b.name);
}
qsort(a,n,sizeof(TEAM),comparesize);
}
//大小比较
void SORTNAME(TEAM*a,int n)
{int comparename(const void*a1,const void*a2)
{
   TEAM a=*(TEAM*)a1;
   TEAM b=*(TEAM*)a2;
   return strcmp(a.name,b.name);
}
qsort(a,n,sizeof(TEAM),comparename);
}
//文件名比较
void OUTPUT(TEAM*a,int n)
{
    for(int k=0;k<n;k++)
        {printf("%d-%d-%d %d:%d ",
        a[k].nian,a[k].yue,a[k].ri,a[k].shi,a[k].fen);
        int count=0,l=a[k].size;
        while(l!=0)
        {
            l=l/10;
            count++;
        }
        for(int k=0;k<16-count;k++) printf(" ");
        printf("%d %s",a[k].size,a[k].name);}

}
//输出
int main()
{
   int n;
   while((scanf("%d\n",&n))!=EOF)
   {
       TEAM *s=NULL;
       s=Input(n);
       char c,d,e,f;
       scanf("LIST /%c%c%c%c\n",&c,&d,&e,&f);
       if(c=='N') SORTNAME(s,n);
       if(c=='S') SORTSIZE(s,n);
       if(c=='T') SORTTIME(s,n);
       OUTPUT(s,n);
       printf("\n\n");
   }
   return 0;
}
