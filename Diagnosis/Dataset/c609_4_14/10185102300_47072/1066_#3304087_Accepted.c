#include <stdio.h>
#define N 10

int isPossible(int a, int *w, int n)
{  if (!a) return 1;
   if (!n) return 0;
   return isPossible(a-*w,w+1,n-1)||isPossible(a+*w,w+1,n-1)||isPossible(a,w+1,n-1);
}

int main()
{ int i,n,w[N],total=0;
  for (scanf("%d",&n),i=0;i<n;i++) scanf("%d",w+i),total+=w[i];
  for (i=1;i<=total;i++) printf("%1d",isPossible(i,w,n)); printf("\n");
  return 0;
}