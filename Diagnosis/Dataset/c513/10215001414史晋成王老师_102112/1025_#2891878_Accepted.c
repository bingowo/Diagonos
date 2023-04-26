#include <stdio.h>
#include <string.h>
#include<stdlib.h>
struct Word
{
    char id[30];
    int diff;
    
};

int getDiff (const void* a)
{ struct Word x;
   x=*((struct Word*)a) ;
    int flag[26] = {0};
    int cnt = 0;
    for (int i = 0; x.id[i]!='\0';i++)
    {
        if (flag[x.id[i]-65]==0) cnt++;
        flag[x.id[i] - 65]++;
    }
    return cnt;
}

int cmp(const void* a, const void* b)
{
    struct Word* p1 = (struct Word*)a,* p2 = (struct Word*)b;
    int x;
  return (x= p2->diff - p1->diff)?x:strcmp(p1->id, p2->id);
}

int main()
{
    int t; scanf("%d",&t);
    for (int i = 0; i < t; i++)
    {
        struct Word a[1000];
        int n; scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
          scanf("%s",a[j].id);
            a[j].diff = getDiff(&a[j]);
        }
        qsort(a, n, sizeof(a[0]), cmp);
        printf("case #%d:\n",i);
        for (int j = 0; j < n; j++)
        { int k=0;
         while(a[j].id[k]) {printf("%c",a[j].id[k]); k++;}
        printf("\n");
        }
    }
}
