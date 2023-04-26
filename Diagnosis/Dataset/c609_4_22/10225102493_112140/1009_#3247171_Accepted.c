#include <stdio.h>
#include <stdlib.h>



int count1(int a)
{
    int p=0;
    int i;
    for(i=0;i<16&&(a!=0);i++)
    {
        p=p+(a&1);
        a>>=1;
    }

    return p;
}



int main()
{
    int n,i,j,al,z;
    scanf("%d",&n);
    i=0,j=0,z=0;
    int a[1000];
    int c=getchar();
    for(j=0;j<n;j++)
    {
       i=0;
       z=0;
        while((c=getchar())!='\n')
     {
        a[i]=c;
        z=z+count1(a[i]);
        i++;

      }
      al=8*i;
      for(i=2;i<=z;i++)
      {
          while((z%i==0)&&(al%i==0))
          {z/=i,al/=i;}
      }
      printf("%d/%d\n",z,al);


    }

    return 0;
}
