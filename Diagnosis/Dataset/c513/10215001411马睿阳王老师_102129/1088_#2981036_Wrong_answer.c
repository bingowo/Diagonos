#include<stdio.h>
#include<string.h>
int main()
{int T,i=0,m=1,n=1,large=1,small=1;
 long long int P=1;
 scanf("%d",&T);
 for(i=0;i<T;i++)
 {scanf("%d%d",&m,&n);
 if(n==0)
    {printf("case #%d:\n",i);
     printf("1\n");
    }

 else{
  if(m>2*n) {large=m-n;small=n;}
  else {large=n;small=m-n;}
  for(i=m;i>large;i--)
      {if(i==small*2)
            {P=P*2;
             small--;
            }
       else P=P*i;
      }
  while(small>=1)
       {P=P/small;
        small--;
       }
  printf("case #%d:\n",i);
  printf("%lld\n",P);
 }
 }
return 0;
}
