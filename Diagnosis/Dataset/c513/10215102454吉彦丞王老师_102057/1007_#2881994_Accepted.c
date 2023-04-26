#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
	int a,b;
	a=*((int *)pa);
	b=*((int *)pb);
	return a-b;
} 
int main()
{
    int number;
    scanf("%d",&number);
    int q[number];
    long long int a[number];
    long long int s[number][32];
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
        int sb[100];
        int t=0;
        int nmd=1;
        while(j<length-1)
        {
            if(s[i][j]!=s[i][j+1])
            {
                n++;
                j++;
                nmd++;
            }
            else
            {
            	j++;
            	sb[t]=n;
            	t++;
            	n=1;
			}
        }
        if(n>=length/2)
        {
        	q[i]=n;
		}
		else
		{
        	qsort(sb,t,sizeof(int),cmp);
        	q[i]=sb[t-1];
    	}
    }
    for(int i=0;i<number;i++)
    {
        printf("case #%d:\n",i);
        printf("%d\n",q[i]);
    }
    return 0;
}