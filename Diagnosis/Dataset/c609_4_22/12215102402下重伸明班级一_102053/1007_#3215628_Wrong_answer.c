#include<stdio.h>
int tongji(int m)
{
    int i,x,k=0;
	for(i=0;i<64;i++)
	{
		x=(m>>i)&1;
		if(x==1)
			k++;
	}
	return k;
}


int main()
{
    int cas;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        int t,m,k;
        scanf("%d",&t);
        int a[t];
        for(int tt=0;tt<t;tt++)
        {
            scanf("%d",&a[tt]);
            m=a[tt];
            k=tongji(m);
            printf("%d\n",k);
            
            
        }   //保存所有数字
    }
    
}