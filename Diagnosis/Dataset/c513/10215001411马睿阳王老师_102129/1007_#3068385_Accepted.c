#include<stdio.h>

int max(int a,int b)
{
    if(a>=b) return a;
    else return b;
}

int main()
{
    int T,i=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int a,b[1000]={0},j=0,h=0,d=0,c[50][1000]={0},m=1,n=0,l[50]={0},s=0;
        scanf("%d",&a);
        while(a)
        {
            b[j]=a%2;
            a/=2;
            j++;
        }
        h=j;
        if(h==1)
        {
            printf("case #%d:\n",i);
            printf("1\n");
        }
        else
        {
            for(j=0;j<h/2;j++)
           {
              d=b[j];
              b[j]=b[h-j-1];
              b[h-j-1]=d;
           }
           c[0][0]=b[0];
           for(j=1;j<h;j++)
          {

             if(b[j]==b[j-1])
            {
                l[n]=m;//长度为m，从0到m-1
                m=1;
                n++;
                c[n][0]=b[j];
                
            }
            else if(b[j]!=b[j-1])
            {
                c[n][m]=b[j];
                m++;
                l[n]=m;
            }

          }

          s=max(l[0],l[1]);
          for(m=2;m<=n;m++)
          {
             if(l[m]>=s) s=l[m];
          }
          printf("case #%d:\n",i);
          printf("%d\n",s);
        }
    }
    return 0;
}
