#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ int n,m,k,i,j,r,a[1000][1000],b[100000],sum,ans,l,count,lb,rb;
scanf("%d %d %d",&n,&m,&k);
for(i=0;i<n;i++)
{ for(j=0;j<m;j++)
{ scanf("%d",&a[i][j]);
}
}
ans=0;count=0;
for(i=0;i<n;i++)
{ for(j=0;j<m;j++)
   { ans=a[i][j];
    for(r=1;i-r>=0&&j-r>=0;r++)
    { lb=j-r;
    rb=j;
    for(l=lb;l<=rb;l++)
     ans+=a[i-r][l];
     if(ans>=k) count++;
    }
   }
}
for(i=0;i<n;i++)
{ for(j=0;j<m;j++)
    {ans=a[i][j];
    for(r=1;i+r<n&&j-r>=0;r++)
    { lb=j-r;
    rb=j;
    for(l=lb;l<=rb;l++)
     ans+=a[i+r][l];
     if(ans>=k) count++;
    }
    }
}
for(i=0;i<n;i++)
{ for(j=0;j<m;j++)
    {ans=a[i][j];
    for(r=1;i+r<n&&j+r<m;r++)
    { lb=j;
    rb=j+r;
    for(l=lb;l<=rb;l++)
     ans+=a[i+r][l];
     if(ans>=k) count++;
    }}
}
for(i=0;i<n;i++)
{ for(j=0;j<m;j++)
   { ans=a[i][j];
    for(r=1;i-r>=0&&j+r<m;r++)
    { lb=j;
    rb=j+r;
    for(l=lb;l<=rb;l++)
     ans+=a[i-r][l];
     if(ans>=k) count++;
    }
   }
}



 printf("%d",count);  
  
}
