#include<stdio.h>
#include<string.h>
void main()
{

    int y,i=0,n,z=0;
    long long int sum=0;
    char x[20];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int sum=0;
        printf("case #%d:\n",i);
        scanf("%s",x);
        
        while(x[z]!='\0')
        {
            z=0;
          z++;
        }

        for(int k=0;k<z;k++)
        {
            if(x[k]=='1') sum+=1*pow(3,(z-k-1));
            if(x[k]=='-') sum+=(-1)*pow(3,(z-k-1));
            if(x[k]=='0') sum+=0;
        }
        printf("%lld",sum);
        if(i!=n-1) printf("\n");

    }

}
