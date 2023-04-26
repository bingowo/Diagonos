#include<stdio.h>
int main()
{
    int n,m,j;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int sec[32];
        j=0;
        int num;
        scanf("%d",&num);
        while(num!=0)
        {
            sec[j]=num%2;
            num/=2;
            j++;
        }
        int max=0;
        for(int p=0;p<j;p++)
        {
            for(m=p;m<j-1;m++)
            {
                if (sec[m]==sec[m+1]) break;
            }
            if(m-p+1>max) {max=m-p+1;}
        }
        printf("case #%d:\n%d\n",i,max);
    }
}
