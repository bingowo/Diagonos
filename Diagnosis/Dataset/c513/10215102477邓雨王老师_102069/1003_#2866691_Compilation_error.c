#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdio.h>
unsigned club(unsigned n){      //club函数用来计算1的位数
    unsigned m=0;
    while(n>0){
        if(n%2==1){
            m=m+1;
            n=(n-1)/2;
        }
        else{

            n=n/2;
        }
    }
    return m;
}

int cmp(const void* i,const void* j){
    int m=0;
    unsigned x,y;
    x=*(unsigned*)i;
    y=*(unsigned*)j;
    if(club(x)>club(y)){
        return -1;
    }
    else if(club(x)==club(y)){
        if(x>y){
            return 1;
        }
        else{
            return -1;
        }
    }
    else{
        return 1;
    }
    }
    
    

void Sort(unsigned *p, unsigned n){
    qsort(p,
	      n,
		  sizeof(int),
		  cmp
		  );
}


int main()
{ int chance;
  scanf("%d",&chance);
  int j;
  for(j=0;j<chance;j++){
      int m;
      scanf("%d",&m);
      int t,a[15000];
      for(t=0;t<m;t++){
          scanf("%d",&a+t);
          Sort(a,m);
          printf("case #%d:\n",chance);
          for (i=0;i<n;i++) printf("%d ",a[i]);
          printf("\n");
      }
  }
  return 0;
}