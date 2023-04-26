#include<stdio.h>
#include<string.h>

typedef struct{
int x,y;
}pos;

int solution(int t,int r)
{if(t==0&&r!=0) return -2;//无解
 else if(t==0&&r==0) return -1;//任意解
 else if(r%t!=0||r/t<0) return -2;
 else return r/t;
}

int main()
{pos A[200];
 A[0].x=0;
 A[0].y=0;
 int q;
 char s[105];
 int i=0,j=0,k=0,l=0,c=0;
 scanf("%s",s);
 c=strlen(s);
 for(i=1;i<=c;i++)
 {switch(s[i-1])
         {case'U':A[i].x=A[i-1].x;A[i].y=A[i-1].y+1;break;
          case'D':A[i].x=A[i-1].x;A[i].y=A[i-1].y-1;break;
          case'L':A[i].x=A[i-1].x-1;A[i].y=A[i-1].y;break;
          case'R':A[i].x=A[i-1].x+1;A[i].y=A[i-1].y;break;
         }
 }
 scanf("%d",&q);
 int a,b;
 for(j=0;j<=c;j++)
    {
     int m1=0,m2=0,flag=0;
     scanf("%d %d",&a,&b);
     for(k=0;k<c;k++)
         {m1=solution(A[c].x,a-A[c].x);
          m2=solution(A[c].y,a-A[c].y);
          if(m1==-2||m2==-2) continue;
          if(m1==-1||m2==-1||m1==m2)
              {flag=1;break;}
         }
     if(flag==1) printf("Yes\n");
     else printf("No\n");

    }
 return 0;

}
