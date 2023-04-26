#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdio.h>
int club(long long n){      //club函数用来计算1的位数
	int num=0;
while(n){
n=n&(n-1);
num++;}
    return num;
}


int cmp(const void* i,const void* j){
    int m=0;
    long long x,y;
    x=*(long long*)i;
    y=*(long long*)j;
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
    
    

void Sort(long long *p, int n){
    qsort(p,
	      n,
		  sizeof(long long),
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
      int t;
      long long a[15000];
       printf("case #%d:\n",j);
      for(t=0;t<m;t++){
          scanf("%lld",&a[t]);}
          Sort(a,m);
          int i;
        for (i=0;i<m;i++) printf("%lld ",a[i]);
        printf("\n");
      
  }
  return 0;
}