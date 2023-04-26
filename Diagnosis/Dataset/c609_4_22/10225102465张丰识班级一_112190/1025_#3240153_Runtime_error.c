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
void solve(int n,int m) {
     int a;
  int b;
  int c;


  int s[200][4]={{0,0}};
  for (int p=0;p<200;p++) {
    for (int q=0;q<4;q++) {
        scanf ("%d", s[p][q]);
    }
  }



    for (int j=1;j<=n;j++) {
        s[j][1]=j;
    }
     for (int i=0;i<m;i++) {
        scanf ("%d%d%d", &a,&b,&c);
        if (c==1) {
              s[a][1]+= 3;
              s[b][1]-= 3;
              s[a][2]+=1;
              s[b][3]+=1;
        }
        else if (c==0) {
               s[a][1] += 1;
               s[b][1] -=1;
        }
        else {
            s[a][1] -=1;
             s[b][1] +=1;
             s[a][3]+=1;
              s[b][2]+=1;
        }
     }
     qsort (s,n,sizeof(s[0]),cmp);
     for (int k=0;k<n;k++) {
        printf ("%d ", *(s+k));

     }
     printf ("\n");
}

int main () {
   int n;
  int m;
  scanf ("%d %d", &n,&m);
  while (1) {
      if (m==0&&n==0) {
    break;
  }
      else
      solve(n,m);
  }
   return 0;

  }

