#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int a[120];
		for(int q=0;q<120;q++) a[q]=0;
		int m=x,k=0;
		while(m) a[k++]=m%10,m/=10;
		for(int j=1;j<y;j++)
		{
			for(int j1=0;j1<k;j1++)
			{
				a[j1]*=x;
			}
			int carry=0;
			for(int j1=0;j1<k;j1++)
			{//printf("%d %d\n",a[j1],carry);
				a[j1]+=carry;
				int z=a[j1];
				if(a[j1]>=10) a[j1]%=10,carry=z/10;
				else carry=0;
			}
			if(carry>0) a[k++]=carry;
			
		}
		printf("case #%d:\n",i);
		if(y==0) printf("1");
		else
		{
			int t=k;
			while(a[t--]==0); 
			for(int j=t+1;j>=0;j--) printf("%d",a[j]);
		}
		printf("\n");
	}
	return 0;
 } 
//2951266543065275214875348022619773631435927251704383288510638846376769434334780203326109411004889
//
//29512665430652752148753480226197736314359272517043832886063884637676943433478020332709411004889

