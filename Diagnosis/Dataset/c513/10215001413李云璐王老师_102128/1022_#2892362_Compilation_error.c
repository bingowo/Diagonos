#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

typedef struct
{char yong[1000001];
char zhu[1000001];
}PEOPLE;

PEOPLE*INPUT(int n)
{
    PEOPLE s;
    s=(PEOPLE*)malloc(n*sizeof(PEOPLE));
    char c;
    while((c=getchar())!='@')
    {
        scanf("%s",s.yong);
    }
    while((c=getchar())!=' ')
    {
        scanf("%s",s.zhu);
    }
    return s;

}

void sort(PEOPLE*s,int n)
{
    int compare(const void*a1,const void*a2)
    {
        PEOPLE a=*(PEOPLE*)a1;
        PEOPLE b=*(PEOPLE*)a2;
        if(strcmp(a.zhu,b.zhu)!=0) return strcmp(a.zhu,b.zhu);
        else return strcmp(b.yong,a.yong);

    }
    qsort(s,n,sizeof(PEOPLE),compare);
}

int main()
{
  int n;
  scanf("%d\n",&n);
  for(int i=0;i<n;i++)
  {
      PEOPLE*s=NULL;
      s=INPUT(n);
      sort(s,n);
      for(int k=0;k<n;k++)
        printf("%s@%s\n",s.yong,s.zhu);
  }
  return 0;
}
