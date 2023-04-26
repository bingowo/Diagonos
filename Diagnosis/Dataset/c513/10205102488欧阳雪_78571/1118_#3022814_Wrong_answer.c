#include<stdio.h>
int b[250][250]={0};

int W,H;
void R_trans(int a[250][250])
{
    int temp=W;
    W=H;
    H=temp;
	for(int i=1;i<=H;i++)
	{
		int t=W;
		for(int j=1;j<=W;j++)
		{
		
			b[i][j]=a[t][i];
			//printf("i j t b a:%d %d %d %d %d\n",i,j,t,b[i][j],a[t][i]);
		    t--;
		    //printf("%d ",b[i][j]);
		}
		//printf("\n");
	}

}
void L_trans(int a[250][250])
{
    int temp=W;
    W=H;
    H=temp;
    //printf("H W:%d %d\n",H,W);
    int tl=H;
	for(int i=1;i<=H;i++)
	{
		
		for(int j=1;j<=W;j++)
		{
			b[i][j]=a[j][tl];
		//	printf("i j tl b a:%d %d %d %d %d\n",i,j,tl,b[i][j],a[j][tl]);
		
		//	printf("%d ",b[i][j]);
		}
		tl--;
		//printf("\n");
	}
}
void copy(int a[250][250])
{
	for(int i=0;i<250;i++)
	{
		for(int j=0;j<250;j++)
		{
			a[i][j]=b[i][j];
		}
	}
}
int main()
{
	int D;
	char c;
	int a[250][250];
	scanf("%d%d%d",&W,&H,&D);
	scanf(" %c",&c);
	int i,j;
	for(i=1;i<=H;i++)
	{
		for(j=1;j<=W;j++)
		{
			scanf("%d",&a[i][j]);
	    }
	}
	
	int t=D/90;
	t%=4;
	//printf("t:%d\n",t);
	int k1=0,k2=0;
	if(t==0)
	{
	
	//	printf("H W:%d %d \n",H,W);
	for(i=1;i<=H;i++)
	{
		for(j=1;j<=W;j++)
		{
			printf("%d ",a[i][j]);
	    }
	    printf("\n");
	}
	}
	else
	{
		
	int k=0;
	if(c=='R')
	{
		for(k=0;k<t;k++)
		{
			R_trans(a);
			copy(a);//修改数组 
		}
	}
	if(c=='L')
	{
		for(k=0;k<t;k++)
		{
			L_trans(a);
			copy(a);
		}
	}
	printf("%d %d\n",W,H);
	for(k1=1;k1<=H;k1++)
	{
		for(k2=1;k2<=W;k2++)
		{
			printf("%d ",b[k1][k2]);
		}
		printf("\n");
	}
}
}