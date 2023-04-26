#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdio.h>
int club(int a){      //club函数用来计算1的位数
	int num=0,n;//n为二进制数
while(n){
n=n&(n-1);
num++;}
    return num;
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
    
    

void Sort(int *p, int n){
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
       printf("case #%d:\n",j);
      for(t=0;t<m;t++){
          scanf("%d",&a[t]);}
          Sort(a,m);
          int i;
        for (i=0;i<m;i++) printf("%d ",a[i]);
        printf("\n");
      
  }
  return 0;
}