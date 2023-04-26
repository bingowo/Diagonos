#include<stdio.h>
int bin(int n)
{
	int max=0;
	int t=1;
	int s[32];
	int i=0;
	for(i=0;n>=1;i++){
		s[i]=n%2;
		n/=2;
	}
	int m=0;
	while(m<i-1){
		if(s[m]!=s[m+1]){m++;t++;
		}
		else{
			if(t>max){max=t;
			}
			t=1;m++;
		}
	}
	if(t==i){max=t;
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
