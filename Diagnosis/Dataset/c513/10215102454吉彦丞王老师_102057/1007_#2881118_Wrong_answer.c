#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
	char a,b;
	a=*((char *)pa);
	b=*((char *)pb);
	return (a-'0')-(b-'0');
} 
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
        char sb[50];
        int t=0;
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
            	sb[t]=n+'0';
            	t++;
            	n=1;
			}
        }
        if(n==length)
        {
        	q[i]=n;
		}
		else
		{
        	int l=strlen(sb);
        	qsort(sb,l,sizeof(char),cmp);
        	q[i]=sb[l-1]-'0';
    	}
    }
    for(int i=0;i<number;i++)
    {
        printf("case #%d:\n",i);
        printf("%d\n",q[i]);
    }
    return 0;
}