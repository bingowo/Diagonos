#include<stdio.h>
int main()
{int n,a,num,i,j,k,d,h,l;
 int s[1005]={0};
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {scanf("%d%d",&a,&num);
  if(num==0) {printf("case #%d:\n",i);printf("1\n");}
  else
  {for(j=0;j<num;j++)
    { s[0]=1;
     for(k=1;k<=l;k++)
     {s[k]=s[k]*a+s[k-1]/10;
      s[k-1]%=10;
      if(k==l) l++;
     }
     s[0]=a;
    }
  }
  if(s[l]!=0) l++;
  l--;
  for(j=0;j<=l/2;j++)
  {d=s[j];s[j]=s[l-j];s[l-j]=d;}
  printf("case #%d:\n",i);
  for(j=0;j<=l;j++)
  printf("%d",s[j]);
  printf("\n");
  for(j=0;j<=l;j++)
  s[j]=0;
  }

 return 0;
}
