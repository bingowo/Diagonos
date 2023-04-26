#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100000
int cmp(const void *a,const void *b) { return *(int*)a-*(int*)b; }

void solve()  
{
    int n,d,ans=0,fn[N],a[N],i,j; PAIR f[N][100]; char s[101];
  scanf("%d",&n); for (i=0;i<n;i++) fn[i]=stat((scanf("%s",s),s),f[i]);
  if (allSameLength_Char(f,n,fn))
  { for (i=0;i<fn[0];i++)
    { for (j=0;j<n;j++) a[j]=f[j][i].cnt;
      qsort(a,n,sizeof(a[0]),cmp);
      for (j=0;j<n;j++) ans+=abs(a[j]-a[n/2]);
    }
    printf("%d\n",ans);
  } 
  else printf("-1\n");

}
int main()
{  int i,t;    
   scanf("%d\n",&t);
   for (i=0;i<t;i++)   { printf("case #%d:\n",i);  solve();   }
   return 0;
}