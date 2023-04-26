#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{ int a,b,c,zheng,fen,g=0,k,f; int z[100]={0},x[100]={0};
scanf("%d %d",&a,&b);
if(a>=b)
{zheng=a/b;
fen=a-zheng*b;
}
else if (a<b)
{  fen=a;zheng=0;
} int i=0,j=b/3;
while (zheng)
{ z[i]=zheng%3;
 zheng=zheng/3;
 i++;
}
while (fen)
{ x[j-1]=fen%3;
  fen=fen/3;
  j--;}
  for (c=b/3-1;c>=0;c--)
  { x[c]+=1; 
    if((x[c]>2)&&(c!=0)){x[c]-=3;x[c-1]+=1;}
    if((x[c]>2)&&(c==0)) {x[c]-=3; g=1;}
    x[c]-=1; if(x[c]==-1) x[c]=2;
  }
  if (g==1) z[i-1]+=1;
  for(c=0;c<i;c++)
  { z[c]+=1;
    if(z[c]>2){z[c]-=3;z[c+1]+=1;}
    z[c]-=1; if(z[c]==-1) z[c]=2;
    }
    if(z[i]==0) f=i-1;
    else f=i;
if (a<b)
{ printf("0.");
 for(k=b/3-1;b>=0;b--) printf("%d",x[k]);
}
if ((a>=b)&&(a%b==0))
{ for (c=f;c>=0;c--)
{printf("%d",z[c]);}}
else if ((a>=b)&&(a%b!=0))
{for (c=0;c<i;c++)
{printf("%d",z[c]);}  printf(".");
  for(k=b/3-1;b>=0;b--) printf("%d",x[k]);
}
    return 0;

}