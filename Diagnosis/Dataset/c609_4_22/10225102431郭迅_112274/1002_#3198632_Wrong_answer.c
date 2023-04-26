#include<stdio.h>
int bin(int n)
{
	int max=1,t=1,i=0;
	int s[32];
	for(i=0;n>=1;i++){
		s[i]=n%2;
		n/=2;
	}
	int m=0,b=0;
	while(m<i-1){
		if(s[m]!=s[m+1]){m++;t++;	
		}
		else{
			if(t>max){max=t;
			}
			t=1;m++;b=m;
		}
	if(t==i){max=t;
	}
	else if((t==m-b+1)&&t!=1){max=t;}
	}	
	return max;
}
int main()
{
	int t;
	scanf("%d",&t);
	int a[t];
	for(int i=0;i<t;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<t;i++){
		printf("case #%d:\n",i);
		printf("%d\n",bin(a[i])); 
	}
}