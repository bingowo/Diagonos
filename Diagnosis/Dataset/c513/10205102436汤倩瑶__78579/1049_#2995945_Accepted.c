#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
char s[20];
}node;
int cmp(const void*a,const void*b)
{
    node p1=(*(node*)a);
    node p2=(*(node*)b);
    return strcmp(p1.s,p2.s);

}
int main()
{
    int T;
    char s[505];
    scanf("%d",&T);
    gets(s);
    for(int i=0;i<T;i++)
    {node p[500]={0};
    gets(s);
    int l=strlen(s);
    int cnt=0;
    int j=0;
    int k=0;
    while(j<l)
    {
        if(s[j]>='a'&&s[j]<='z'){p[cnt].s[k++]=s[j];j++;}
        else if(s[j+1]>='a'&&s[j+1]<='z'){cnt++;k=0;j++;}
        else j++;
    }
qsort(p,cnt+1,sizeof(p[0]),cmp);
  printf("case #%d:\n",i);
  printf("%s ",p[0].s);
  for(int t=1;t<=cnt;t++)
  {
      if(strcmp(p[t].s,p[t-1].s))
    printf("%s ",p[t].s);
  }
printf("\n");
    }
}
