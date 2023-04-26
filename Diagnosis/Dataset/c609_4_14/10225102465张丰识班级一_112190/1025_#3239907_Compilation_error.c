#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp (const void*a,const void*b) {
  int *x=*(int **)a;
  int *y=*(int **)b;
  if (x[1]!=y[1]) {
    return x[1]>y[1]?1:-1;
  }
  else {
    if (x[2]!=y[2] )
        return x[2]>y[2]?1:-1;
    else {
        if (x[3]!=y[3])
        return x[3]<y[3]?1:-1;
        else return x[0]>y[0]?1:-1;
    }
  }

}
void solve(int t) {
     int a[200]={0};
  int b[200]={0};
  int c[200];
  int d=0;
  int e=0;
  int f=0;
  int s[200][4]={{0,0}};
  while ((m!=0)&&(n!=0)) {

    if (m==0&&n==0) {
        break;
    }
    for (int j=1;j<=n;j++) {
        s[j][1]=j;
    }
     for (int i=0;i<m;i++) {
        scanf ("%d%d%d", &a[i],&b[i],&c[i]);
        if (c[i]==1) {
              s[a[i]][1]+= 3;
              s[b[i]][1]-= 3;
              s[a[i]][2]+=1;
              s[b[i]][3]+=1;
        }
        else if (c[i]==0) {
               s[a[i]][1] += 1;
               s[b[i]][1] -=1;
        }
        else {
            s[a[i]][1] -=1;
             s[b[i]][1] +=1;
             s[a[i]][3]+=1;
              s[b[i]][2]+=1;
        }
     }
     qsort (s,n,sizeof(s[0]),cmp);
     for (int k=0;k<n;k++) {
        printf ("%d ", s[k][0]);

     }
     printf ("\n");
}
}
int main () {
  int m;
  int n;
  while (1) {
      scanf ("%d %d", &n,&m);
      if (m==0&&n==0)
      break;
      solve(1);
  }
   return 0;  
  
  }
  
