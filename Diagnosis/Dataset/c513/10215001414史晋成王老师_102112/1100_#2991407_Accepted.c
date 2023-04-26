#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct point
{int a,b;};

int solution(int t,int r)
{ if(t==0&&r!=0) return-2;
  if(t==0&&r==0) return-1;
  if(r%t!=0||r/t<0) return-2;
  return r/t;
    
}
int main()
{ int i,j,n,t,m,a,b,l,flag,m1,m2;
  struct point pos[200];
char s[1000];
scanf("%s",s);
l=strlen(s);
pos[0].a=0; pos[0].b=0;
for(i=0;i<l;i++)
{ switch(s[i])
   { case 'U':pos[i+1].a=pos[i].a; pos[i+1].b=pos[i].b+1;break;
     case 'D':pos[i+1].a=pos[i].a; pos[i+1].b=pos[i].b-1;break;
     case 'L':pos[i+1].a=pos[i].a-1; pos[i+1].b=pos[i].b;break;
     case 'R':pos[i+1].a=pos[i].a+1; pos[i+1].b=pos[i].b;break;
   }
    
}
scanf("%d",&t);
for(i=0;i<t;i++)
{ scanf("%d%d",&a,&b);
  for(j=0;j<=l;j++)
  {  flag=0;
     m1=solution(-pos[l].a,pos[j].a-a);
     m2=solution(-pos[l].b,pos[j].b-b);
     if(m1==-2||m2==-2) continue;
     if(m1==-1||m2==-1||m1==m2)
     {flag=1;break;}      
  }
  if(flag) printf("Yes\n");
  else printf("No\n");
}

    
}