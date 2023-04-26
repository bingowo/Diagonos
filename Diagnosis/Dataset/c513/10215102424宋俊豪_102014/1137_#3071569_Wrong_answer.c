#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    int f,cnt,v[300];
}bigint;
int com(bigint x,bigint y)
{
    if(x.cnt>y.cnt)
        return 1;
    else if(x.cnt<y.cnt)
        return -1;
    else
    {
        for(int i=x.cnt-1;i>=0;i--)
            if(x.v[i]>y.v[i])
               return 1;
           else if(x.v[i]<y.v[i])
            return -1;
    }
    return 0;
}
bigint add(bigint s,bigint t)
{
    bigint r;
    r.f=1;
    r.cnt=0;
    int i,carry=0;
    for(i=0;i<s.cnt&&i<t.cnt;i++)
    {
        int temp=s.v[i]+t.v[i]+carry;
        r.v[i]=temp%10;
        carry=temp/10;
    }
    while(i<s.cnt)
    {
        int temp=s.v[i]+carry;
        r.v[i++]=temp%10;
        carry=temp/10;
    }
     while(i<t.cnt)
    {
        int temp=t.v[i]+carry;
        r.v[i++]=temp%10;
        carry=temp/10;
    }
    if(carry)
    {
        r.v[i++]=carry%10;
    }
    r.cnt=i;
    return r;
}
bigint mins(bigint s,bigint t)
{
    bigint r;
    r.f=1;
    r.cnt=0;
    int i,carry=0;
    for(i=0;i<s.cnt&&i<t.cnt;i++)
    {   if(s.v[i]<0)
         {
             s.v[i]+=10;s.v[i+1]--;
         }
        int temp=s.v[i]-t.v[i];
        if(temp<0)
        {r.v[i]=temp+10;s.v[i+1]--;}
        else
        {
            r.v[i]=temp;
        }

    }
    while(i<s.cnt)
    {
        r.v[i]=s.v[i];
        i++;
    }
    i--;
    while(r.v[i]==0)
        i--;

    r.cnt=i+1;
    return r;
}
int main()
{
   char a[105],b[105];int big;
   scanf("%s%s",a,b);

   bigint x,y;
   x.f=1,y.f=1;x.cnt=0,y.cnt=0;
   if(a[0]=='-')
   {
       x.f=-1;
       for(int i=strlen(a)-1;i>=1;i--)
        x.v[x.cnt++]=a[i]-'0';

   }
   else
   {
       for(int i=strlen(a)-1;i>=0;i--)
        x.v[x.cnt++]=a[i]-'0';
   }
   if(b[0]=='-')
   {
       y.f=-1;
       for(int i=strlen(b)-1;i>=1;i--)
        { y.v[y.cnt++]=b[i]-'0';}

   }
   else
   {
       for(int i=strlen(b)-1;i>=0;i--)
        y.v[y.cnt++]=b[i]-'0';

   }
   if(y.f*x.f>0)
   {
      bigint r=add(x,y);
      if(y.f>0)
      {
          for(int i=r.cnt-1;i>=0;i--)
            printf("%d",r.v[i]);

      }
      else
      {    printf("-");
          for(int i=r.cnt-1;i>=0;i--)
            printf("%d",r.v[i]);
      }
   }
   else
   {
       big=com(x,y);

       if(big==0)
        printf("0");
       else if(x.f<0&&y.f>0)
       {
           if(big>0)
           {
                bigint r=mins(x,y);   //a<0 гр╦Э╢С
                printf("-");
               for(int i=r.cnt-1;i>=0;i--)
               printf("%d",r.v[i]);
           }
           else
           {
               bigint r=mins(y,x);
               for(int i=r.cnt-1;i>=0;i--)
               printf("%d",r.v[i]);
           }
       }
       else    //a>0,b<0
       {
           if(big>0)
           {
                bigint r=mins(x,y);   //a<0 гр╦Э╢С

               for(int i=r.cnt-1;i>=0;i--)
               printf("%d",r.v[i]);
           }
           else
           {
               bigint r=mins(y,x);
               printf("-");
               for(int i=r.cnt-1;i>=0;i--)
               printf("%d",r.v[i]);
           }
       }
   }


return 0;








}
