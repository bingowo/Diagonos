#include<stdio.h>
#include<math.h>
int main(){
      int n;  
      while(~scanf("%d",&n)&&n)
    {  
        double a=n*log10(n);  
        printf("%d\n",(int)pow(10.0, a-(long long)a));
	}
return 0;}