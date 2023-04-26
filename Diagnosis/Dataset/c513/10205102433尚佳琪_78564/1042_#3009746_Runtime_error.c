#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    return *(char*)a-*(char*)b;
}
typedef struct node
{
    char s[20];
}NODE;
int cmp2(const void *a,const void *b)
{
    NODE s1=*(NODE*)a;
    NODE s2=*(NODE*)b;
    return strcmp(s1.s,s2.s);
}
int numc=0;
void f(char b[],int start,char z[],NODE c[])
{
    if(start>strlen(b))
        return ;
    if(strcmp(z,"")!=0)
    {
        int i;
        for(i=0;i<strlen(z);i++)
        {
            c[numc].s[i]=z[i];
        }
        c[numc].s[i]='\0';
        numc++;
    }
    char z2[20];
    int i;
    for(i=0;i<strlen(z);i++)
    {
        z2[i]=z[i];
    }
    z2[i]=b[start];
    z2[i+1]='\0';
  //  printf("%d\n",numc);
    f(b,start+1,z2,c);
    f(b,start+1,z,c);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int q=0;q<t;q++)
    {
        char a[50];
        char b[20];
        NODE c[70000];
        scanf("%s",a);
        int len=strlen(a);
        qsort(a,len,sizeof(a[0]),cmp);
        int temp=0;
        b[temp++]=a[0];
        for(int i=1;i<len;i++)
        {
            if(a[i]!=a[i-1])b[temp++]=a[i];
        }
        b[temp]='\0';
       // printf("%s\n",b);
       char z[20];
       z[0]='\0';
       f(b,0,z,c);
       qsort(c,numc,sizeof(c[0]),cmp2);
      /* for(int i=0;i<numc;i++)
      {
          printf("%s\n",c[i].s);
      }
      printf("\n");*/
       NODE d[70000];
       int numd=0;
       strcpy(d[numd++].s,c[0].s);
       for(int i=1;i<numc;i++)
      {
            if(strcmp(c[i].s,c[i-1].s)!=0)
              //  printf("%s",c[i].s);
               strcpy(d[numd++].s,c[i].s);
      }
      printf("case #%d:\n",q);
      for(int i=0;i<numd;i++)
      {
          printf("%s\n",d[i].s);
      }
      numc=0;
    }
    return 0;
}
