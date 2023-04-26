#include<stdio.h>
#include<string.h>

int main()
{
    int n,i=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        char a[121],b[1000000]={0};
        gets(a);
        int j=0,k=0,t= 0,l=0,m=0,d=0;
        l=strlen(a);
        for(j=0;j<l;j++)
        {
            while(a[j])
            {
                b[k]=a[j]%2;
                a[j]/=2;
                k++;
            }
        }
        for(k=0;k<8;k++)
        {
           if(b[k]==1) t++;
        }
        m=8*l;
        int h=2;
        if(m%t==0)
       {
         h=m/t;
         printf("1/");
         printf("%d\n",h);
       }
        else
       {
          while(h<t)
          {
              if(t%h==0&&m%h==0)
              {
                t=t/h;
                m=m/h;
              }
              h++;
          }
          printf("%d",t);
          printf("/");
          printf("%d",m);
       }
    }
    return 0;
}
