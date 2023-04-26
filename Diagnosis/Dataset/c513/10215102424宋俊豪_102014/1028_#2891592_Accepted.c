#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int cmp1(const void *a,const void *b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    return x-y;
}
int cmp2(const void *a,const void *b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    return y-x;
}
int main()
{
    char s[2];
    int a[101],cnt=0;
    scanf("%s",s);
    while(~(scanf("%d",&a[cnt])))
    {
        for(int i=0; i<cnt; i++)
            if (a[i]==a[cnt])
            {
                cnt--;
                break;
            }
            cnt++;
    }
    if(s[0]=='A')
    qsort(a,cnt,sizeof(int),cmp1);
    else if(s[0]=='D')
    qsort(a,cnt,sizeof(int),cmp2);
    for(int i=0;i<cnt-1;i++)
        printf("%d ",a[i]);
      printf("%d",a[cnt-1]);
      return 0;
}
