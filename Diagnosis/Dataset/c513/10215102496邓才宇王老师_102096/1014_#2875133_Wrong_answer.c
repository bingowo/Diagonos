#include <stdio.h>
#include <stdlib.h>

int main()
{
   int A,B;
   scanf("%d %d",&A,&B);
   int a1=A/B;
   int a2=A-B*a1;
   char s1[50];
   int i,j;
   for(i=0;i<50;i++) s1[i]=3+'0';
   char s2[50];
   for(j=0;j<50;j++) s2[j]=3+'0';
   i=49,j=49;
   while(a1/3)
   {
       s1[i--]=a1%3+'0';
       a1=a1/3;
   }
    if(a1!=0) s1[i]=a1+'0';
   while(a2/3)
   {
       s2[j--]=a2%3+'0';
       a2=a2/3;
   }
   if(a2!=0) s2[j]=a2+'0';
   char s3[50];
   for(int k=0;k<50;k++) s3[k]=0+'0';
   int num=1;
   for(int q=0;q<50;q++)
   {
       if(s1[q]!='3') s3[num++]=s1[q];
   }
   if(s2[49]!='3')
   {
       s3[num]='.';
       num=num+1;
   }
   for(int w=0;w<50;w++)
   {
       if(s2[w]!='3') s3[num++]=s2[w];
   }
   printf("%d\n",num);
//            for(int z=0;z<50;z++)
//   {
//       printf("%c",s1[z]);
//   }
//   printf("\n");
    int C=0;
    for(int z=num-1;z>=0;z--)
    {
        if(s3[z]!='.')
        {
                if(s3[z]-'0'+1+C>=3)
            {
                s3[z]=s3[z]-'0'-2+C+'0';
                C=1;
            }
            else
            {
                s3[z]=s3[z]-'0'+1+C+ '0';
                C=0;
            }
        }

    }
//    if(C==1)
//    {
//
//    }
//           for(int z=0;z<50;z++)
//   {
//       printf("%c",s3[z]);
//   }
    char s4[50];
    for(int a=0;a<50;a++) s4[a]=3+'0';
    int b=0;
    while(b<50)
    {
        int n=0;
        if(s3[b]=='2')
        {
            s4[b]='1';
            n++;
            b++;
        }
        if(s3[b]=='1')
        {
            s4[b]='0';
            n++;
            b++;
        }
        if(s3[b]=='0')
        {
            s4[b]='2';
            b++;
            n++;
        }
        if(s3[b]=='.')
        {
            s4[b]='.';
            b++;
            n++;
        }
    }
    int z=0;
    if(s4[0]=='0') z=1;
    while(z<num)
    {
        printf("%c",s4[z]);
        z++;
    }
}
