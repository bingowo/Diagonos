#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n,i,j,number=0,len,k,flag;char message[61];int put[61];long long sum=0;
    scanf("%d",&n);
    while(number<n)
    {
        for(j=0;j<61;j++)put[j]=0;
        scanf("%s",message);
        sum=0;
        printf("case #%d:\n",number);number++;
        put[0]=1;k=2;flag=1;message[61]="\0";
        len=strlen(message);
        for(i=1;i<len;i++)
        {
            for(j=0;j<i;j++)
            {
                if(message[j]==message[i]){put[i]=put[j];break;}
                else if((message[j]!=message[i])&&flag==1){put[i]=0;flag=0;}
                else put[i]=k++;
            }
        }
        for(j=0;j<len;j++)sum=sum*k+put[j];
        printf("%lld\n",sum);
    }
}

