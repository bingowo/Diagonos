#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n,m,i,j,number=0,len,k,flag;char message[61];int put[61];long long sum=0;
    scanf("%d",&n);
    while(number<n)
    {
        
        scanf("%s",message);
        sum=0;
        printf("case #%d:\n",number);number++;
        put[0]=1;k=2;flag=1;message[61]="\0";
        len=strlen(message);
        for(i=1;i<len;i++)
        {


               for(j=0;j<i;j++) if(message[i]==message[j]){put[i]=put[j];break;}
             if(j>=i&&flag==1){put[i]=0;flag=0;}
             else if(j>=i&&flag==0) put[i]=k++;

        }
        for(j=0;j<len;j++)sum=sum*k+put[j];
        printf("%lld\n",sum);
    }
}

