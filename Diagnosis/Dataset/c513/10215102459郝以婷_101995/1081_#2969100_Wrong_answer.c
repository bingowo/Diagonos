#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,n,i,a,r,j,carry,k,p;
    scanf("%d",&T);
    int result[96]={1};
    for(i=0;i<T;i++)
    {
        scanf("%d %d",&a,&n);
        r=0;
        carry=0;
        j=1;
        result[0]=1;
        for(k=1;k<95;k++)
            result[k]=0;
        k=1;
        if(n!=0&&a!=1)
        {
            result[0]=a;
            if(a<=3)
            {
                while(result[0]*a<10&&j<n)
                {
                    result[0]=result[0]*a;
                    j++;
                }
            }
            for(;j<n;j++)
            {
                //result[r+1]=result[r]*a-(result[r]*a-(result[r]*a)%10);result[r]=(result[r]*a-(result[r]*a)%10)/10;
                //printf("%d cc\n",j);
                while(result[r]!=0)
                {
                    //printf("%d %d\n",r,result[r+1]);
                    if(result[r]*a+carry<10)
                    {
                        result[r]=result[r]*a+carry;
                        carry=0;
                        r++;
                    }
                    else
                    {
                        p=result[r];
                        result[r]=result[r]*a+carry-(result[r]*a+carry-(result[r]*a+carry)%10);
                        carry=(p*a+carry-(p*a+carry)%10)/10;
                        if(result[r+1]==0)
                            {result[r+1]=carry;r++;carry=0;}
                        r++;
                    }
                 }
                 k=r;
                 r=0;
             }
        }
        printf("case #%d:\n",i);
        for(j=k-1;j>=0;j--)
        {
            printf("%d",result[j]);
        }
        printf("\n");
    }
    return 0;
}
