#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdio.h>
int club( n){      //club函数用来计算1的位数
    int m=0; //m表示二进制补码中1的个数
	if(n>0){
		int m=0;
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
	else if(n==0) return 0;
	else{
		int t=-n;
		while(t>0){
			if(t%2==1){
				m=m+1;
				t=(t-1)/2;
			}
			else{
				t=t/2;
			}
		}
		return 65-m;
	} 
}

int cmp(const void* i,const void* j){
    int m=0;
    int x,y;
    x=*(int*)i;
    y=*(int*)j;
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