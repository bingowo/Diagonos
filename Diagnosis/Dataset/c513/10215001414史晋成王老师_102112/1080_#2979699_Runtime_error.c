#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct bigint 
{int cnt,v[1000];};
void DIV2(struct bigint *n)
{ int carry=0,i,t;
if(n->v[n->cnt-1]<2)
{ n->cnt--;
  carry=1;
}
for(i=n->cnt-1;i>=0;i--)
{ t=10*carry+n->v[i];
    n->v[i]=t/2;
    carry=t%2;
}
    
}

void mul2add(struct bigint *n,int d)
{ int carry=d,i;
  for(i=0;i<n->cnt;i++)
  { int t=carry+n->v[i]*2;
     n->v[i]=t%10;
     carry=t/10;
      
  }
    if(carry>0) n->v[n->cnt++]=carry;
}

int main()
{ char line[1002]; int i,j,t; struct bigint n;
 scanf("%d\n",t);
 for(i=0;i<t;i++)
 { scanf("%s\n",line);
   n.cnt=strlen(line);
   for(j=0;j<n.cnt;j++)
     n.v[j]=line[n.cnt-j-1]-'0';
     int s[334],cnt=0;
   while (n.cnt>0) 
   {
	s[cnt++]=n.v[0]%2;
	DIV2(&n);
   }
   if(n.cnt==0) n.cnt++;
   printf("case #%d:\n",i);
   for(j=n.cnt-1;j>=0;j--)
   printf("%d",n.v[j]);
   printf("\n");
 }
    
}