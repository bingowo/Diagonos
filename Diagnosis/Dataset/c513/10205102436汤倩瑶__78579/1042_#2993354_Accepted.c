#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
char ss[20];
}node;
int cmp(const void*a,const void*b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
    return strcmp(p1.ss,p2.ss);


}
int main()
{
    int T;
    scanf("%d",&T);
    char s[20];

    for(int i=0;i<T;i++)
    {  char ans[20]={0};
    int a[128]={0};
    scanf("%s",s);
    int l=strlen(s);
    for(int j=0;j<l;j++)
    {
        a[s[j]]=1;
    }
    int cnt=0;
    for(int j=0;j<128;j++)
    {
        if(a[j])
        ans[cnt++]=(char)j;
    }
   ans[cnt]='\0';
   int p=1;
   for(int j=0;j<cnt;j++)p*=2;
   node *anss=(node*)malloc(sizeof(node)*p);
   for(int j=1;j<p;j++)
   {int k=0;
       int b[20]={0};
       int tmp=j;
       while(tmp!=0)
       {
           b[k++]=tmp%2;
           tmp/=2;
       }
       int cnt2=0;
       for(int t=0;t<k;t++)
       {
           if(b[t]==1)anss[j-1].ss[cnt2++]=ans[t];

       }
       anss[j-1].ss[cnt2]='\0';
   }
   qsort(anss,p-1,sizeof(anss[0]),cmp);
     printf("case #%d:\n",i);
     for(int j=0;j<p-1;j++)
     {
         printf("%s\n",anss[j].ss);

     }
     free(anss);
    }


    return 0;
}
