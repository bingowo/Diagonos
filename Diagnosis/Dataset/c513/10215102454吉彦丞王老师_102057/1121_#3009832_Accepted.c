#include<stdio.h>
#include<math.h>
int main(){
    int number;
    scanf("%d",&number);
    int a[number];
    for(int i=0;i<number;i++){
        scanf("%d",&a[i]);
    }
    int n=(int)(pow(3,number));
    int c[n];
    int b[number];
    for(int i=0;i<n;i++){
        c[i]=0;
    }
    int sum=0;
    for(int i=0;i<number;i++){
    	b[i]=0;
        sum=sum+a[i];
    }
    for(int i=0;i<n;i++)
    {
        int m=i;
        int t=number-1;
        while(m>0){
            b[t]=m%3;
            m=m/3;
            t--;
        }
        for(int j=0;j<number;j++){
            if(b[j]==1){
                c[i]=c[i]+a[j];
            }
            else if(b[j]==0)
            {
                c[i]=c[i]+0;
            }
            else{
            	c[i]=c[i]-a[j];
			}
        }
    }
    int d[sum];
    for(int i=0;i<sum;i++){
        d[i]=0;
    }
    for(int i=0;i<n;i++){
        if(c[i]<1){
            continue;
        }
        else{
            if(d[c[i]-1]==0){
                d[c[i]-1]=1;
            }
        }
    }
    for(int i=0;i<sum;i++){
    	printf("%d",d[i]);
	}
    return 0;
}