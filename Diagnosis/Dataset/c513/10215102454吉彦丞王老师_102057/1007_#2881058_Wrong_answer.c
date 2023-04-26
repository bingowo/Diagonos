#include<stdio.h>
int main()
{
    int number;
    scanf("%d",&number);
    int q[number];
    long long int a[number];
    int s[number][32];
    int result[number];
    for(int i=0;i<number;i++)
    {
        scanf("%lld",&a[i]);
        int length=0;
        while(a[i]>0)
        {
            s[i][length]=a[i]%2;
            a[i]=a[i]/2;
            length++;
        }
        int n=1;
        int j=0;
        while(j<length-1)
        {
            if(s[i][j]^s[i][j+1]==1)
            {
                n++;
                j++;
            }
            else
            {
            	j++;
			}
        }
        q[i]=n;
    }
    for(int i=0;i<number;i++)
    {
        printf("case #%d:\n",i);
        printf("%d\n",q[i]);
    }
        
}