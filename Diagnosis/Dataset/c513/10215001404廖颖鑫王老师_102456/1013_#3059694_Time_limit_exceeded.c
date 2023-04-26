#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int easy(int x,int y)
{
    int i=x;
    if(x<0)
    {
        while(x%i!=0||y%i!=0)
            {i++;
            if(i==0)i=1;}
       return i;
    }
    if(x>0)
    {
       while(x%i!=0||y%i!=0)
       {
           i--;
       }
       return i;
    }
}

int main()
{
    char m[100];
    int i,sz,sum1=0,k=0,B1,C1,flag;
    scanf("%s",m);
    sz=sizeof(m);
   for(i=0;i<sz;i++)
    {
         while(m[i]!='.')
     {
        sum1=sum1*3;
        {
            if(m[i]==1)sum1+=m[i];
            if(m[i]==0)sum1+=0;
            if(m[i]==2)sum1-=m[i];
        }
     }
      B1=B1*3;
      if(m[i]!='.')
      {
       if(m[i]==1)B1+=m[i];
       if(m[i]==0)B1+=0;
       if(m[i]==2)B1-=m[i];
       k++;
      }
    }
    C1=pow(3,k);
    flag=easy(B1,C1);
    if(sum1>0)
    {
        if(B1!=0)
        {
         if(B1>0)printf("%d %d %d",sum1,B1/flag,C1/flag);
         if(B1<0)sum1-=1,B1=C1+B1;
         {
             if(sum1==1)printf("%d %d",B1/flag,C1/flag);
             else printf("%d %d %d",sum1,B1/flag,C1/flag);
         }
        }
        else printf("%d",sum1);
    }
    if(sum1<0)
    {
        if(B1!=0)
        {
         if(B1>0)sum1+=1,B1=C1-B1;
         {
             if(sum1==-1)printf("%c%d %d",'-',B1/flag,C1/flag);
             else printf("%c%d %d %d",'-',sum1,B1/flag,C1/flag);
         }
         if(B1<0)printf("%c%d %d %d",'-',sum1,B1/flag,C1/flag);
        }
        else printf("%d",sum1);
    }
      if(sum1==0)
        {if(B1<0)printf("%c%d %d",'-',B1/flag,C1/flag);
        if(B1>0)printf("%d %d",B1/flag,C1/flag);
        else printf("0");}

        return 0;

}
