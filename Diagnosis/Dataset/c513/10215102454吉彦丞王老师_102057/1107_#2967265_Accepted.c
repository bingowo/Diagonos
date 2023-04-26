#include<stdio.h>
int main()
{
    int number;
    scanf("%d",&number);
    
    for(int i=0;i<number;i++)
    {
		int a[5][5];
    	for(int j=0;j<5;j++)
    	{
        	for(int k=0;k<5;k++)
        	{
        		a[j][k]=0;
			}
		}
        int b[3][3];
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                scanf("%d",&b[j][k]);
                a[j+1][k+1]=b[j][k];
            }
        }
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                b[j][k]=a[j][k+1]+a[j+1][k+1]+a[j+1][k]+a[j+1][k+2]+a[j+2][k+1];
            }
        }
        int c[3][3];
        printf("case #%d:\n",i);
        for(int j=0;j<3;j++)
        {
        	for(int k=0;k<3;k++)
        	{
        		c[j][k]=(b[j][k]+1)%2;
        		printf("%d ",c[j][k]);
			}
			printf("\n");
		}
		
    }
	return 0;
}