#include<stdio.h>
#include<math.h>
int main()
{
	int t,i=0,j,m=1;
	scanf("%d",&t);
	while(t>0){
        long long int n,b;
        scanf("%lld",&n);
        b=n;
        if(n==0)printf("0");
        else{
            if(n<0){
                printf("-");
                n=-n;
            }
            while(n>2332||m=0){
               m=n%2333;
               n=n/2333;
               i++;
            }
            int a[i];
            for(j=i;j>0;j--){
                a[j]=b%2333;
                b=b/2333;
            }
            for(j=1;j<i+1;j++) printf("%d ",a[j]);
        }
        printf("\n");
        t--;
	}
	return 0;
}
