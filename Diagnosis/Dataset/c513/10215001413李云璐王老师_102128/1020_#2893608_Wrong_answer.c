#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct
{int nian;
int yue;
int ri;
int shi;
int fen;
int size;
char name[64];
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
     return s;
}
//输入

void SORTTIME(TEAM*a,int n)
{int comparetime(const void*a1,const void*a2)
{
   TEAM a=*(TEAM*)a1;
   TEAM b=*(TEAM*)a2;
   if(a.nian!=b.nian) return a.nian-b.nian;
   else if(a.yue!=b.yue) return a.yue-b.yue;
   else if(a.ri!=b.ri) return a.ri-b.ri;
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
void OUT(TEAM*a,int n)
{
    for(int k=0;k<n;k++)
        {printf("%d-",a[k].nian);
        if(a[k].yue<10) printf("0%d-",a[k].yue);
        else printf("%d-",a[k].yue);
        if(a[k].ri<10) printf("0%d ",a[k].ri);
        else printf("%d ",a[k].ri);
        if(a[k].shi<10) printf("0%d:",a[k].shi);
        else printf("%d:",a[k].shi);
        if(a[k].fen<10) printf("0%d",a[k].fen);
        else printf("%d",a[k].fen);
        
        int count=0,l=a[k].size;
        while(l!=0)
        {
            l=l/10;
            count++;
        }
        for(int k=0;k<=16-count;k++) printf(" ");
        printf("%d %s\n",a[k].size,a[k].name);}
        printf("\n");

}
//输出
int main()
{
   int n;
   while(scanf("%d\n",&n)!=EOF)
   {
       TEAM *s=NULL;
       s=Input(n);
       char c1[10],c2[10];
       scanf("%s%s",c1,c2);
       
       if(c2[1]=='N') SORTNAME(s,n);
       if(c2[1]=='S') SORTSIZE(s,n);
       if(c2[1]=='T') SORTTIME(s,n);
       OUT(s,n);
       
      
   }
   return 0;
}
