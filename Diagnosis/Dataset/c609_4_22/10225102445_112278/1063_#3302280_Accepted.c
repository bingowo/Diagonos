#include<stdio.h>
long long int p(int n,long long int b[])
{b[0]=1;b[1]=2;b[2]=4;b[3]=8;
if(n==1) {return 1;}
else if(n==2){return 2;}
else if(n==3)  {return 4;}
else if(n==4) {return 8;}
else
{   for(int c=5;c<=n;c++)
    {b[c-1]=b[c-2]+b[c-3]+b[c-4]+b[c-5];}

    return b[n-1];
}


}
int main()
{int i,v,n;
long long int k;
scanf("%d",&i);
    for(v=0;v<i;v++)
    {scanf("%d",&n);
    long long int b[n+10];
    for(int q=0;q<n;q++){b[q]=0;}
     k=p(n,b);
      printf("case #%d:\n",v);
     printf("%lld\n",k);
    }

}
