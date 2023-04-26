#include<stdio.h>
#include<string.h>
#define L 500
int l=0,q1=0,q2=0,sign=1;

void input(int a[],int b[])///输入
{int i1=0,i2=0,j1,j2,k1,k2,c1=0,c2=0,x=0,i=0,j=0,d1=0,d2=0;
 char s1[2*L+1];char s2[2*L+1];
 scanf("%s",s1);
 scanf("%s",s2);

 while(s1[i1]&&s1[i1]!='.') i1++;
 for(j1=i1-1,k1=L;j1>=0;j1--,k1--)
 a[k1]=s1[j1]-'0';
 for(j1=i1+1,k1=L+1;j1<strlen(s1);j1++,k1++)
 a[k1]=s1[j1]-'0';
 q1=k1;

 while(s2[i2]&&s2[i2]!='.') i2++;
 for(j2=i2-1,k2=L;j2>=0;j2--,k2--)
 b[k2]=s2[j2]-'0';
 for(j2=i2+1,k2=L+1;j2<strlen(s2);j2++,k2++)
 b[k2]=s2[j2]-'0';
 q2=k2;
 ////符号问题
 c1=strlen(s1);
 c2=strlen(s2);
 d1=c1-q1+L+1;
 d2=c2-q2+L+1;
 if(d1>d2) sign=1;
 else if(d1<d2) sign=-1;
 else
      i=0;
      while(i<L)
        {if(a[i]>b[i])
               {break;
                sign=1;
               }
         else if(a[i]<b[i])
              {break;
               sign=-1;
              }
         else
           {i++;}
        }
       if(i==L)
            {if(c1>c2) sign=1;
             else if(c1<c2) sign=-1;
             else
                {while(j<c1)
                  {if(a[j]>b[j]) {sign=1;break;}
                   else if(a[j]<b[j]) {sign=-1;break;}
                   else {j++;}
                  }
                 if(j==c1) sign=0;
                 else j=0;
                }

             }
        else i=0;
  printf()


}