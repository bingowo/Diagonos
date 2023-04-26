#include <stdio.h>
int big(int m,int n){
    int tmp=0;
    while (tmp = m % n)
    {
        m = n;
        n = tmp;
    }return n;
}
int srch(char t){
  int k,l;
  k=0;
  for(int z=0;z<8;z++)
  {
      l=(t>>z)&1;
      if(l==1)k++;
  }
  return k;
}
int main(){
    int n;
    int sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char a[100]="\0";
      char t;
      int j=0;
      gets(a);
      j=sizeof(a)/sizeof(a[0]);
        for(int q=0;q<j;q++)
            sum=sum+srch(a[q]);
            int all=8*j;
        int x=big(sum,all);
        printf("%d/%d\n",sum/x,all/x);

}
return 0;
}