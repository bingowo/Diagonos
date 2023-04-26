#include <stdio.h>
#include <stdlib.h>

int main()
{ int n,m,k,a[200][200],count=0;
  scanf("%d %d %d",&n,&m,&k);
  for(int i=0;i<n;i++)
  {  for(int j=0;j<m;j++)
     scanf("%d",&a[i][j]);
  }
  int x=0,y=0;
  for(;x<m;x++)
  { for(;y<n;y++)
      { int up,down,left,right;
        up=y+1;
        down=n-y;
        left=x+1;
        right=m-x;
        int lu,ld,ru,rd;
        if(up>left) lu=left;
        else lu=up;
        if(up>right) ru=right;
        else ru=up;
        if(down>left) ld=left;
        else ld=down;
        if(down>right) rd=right;
        else rd=down;

        if(lu>1)
        {  int s=a[y][x];
            for(int q=2;q<=lu;q++)
            {  for(int w=1;w<=q;w++)
                 s+=a[y-q+w][x+1-w];
                if(s>=k)
              {  count+=lu-q+1;
                  break;
              }
            }
        }
        if(ru>1)
        {  int s=a[y][x];
            for(int q=2;q<=lu;q++)
            {  for(int w=1;w<=q;w++)
                 s+=a[y-q+w][x+w-1];
                if(s>=k)
              {  count+=ru-q+1;
                  break;
              }
            }
        }
        if(ld>1)
        { int s=a[y][x];
            for(int q=2;q<=lu;q++)
            {  for(int w=1;w<=q;w++)
                 s+=a[y+q-w][x+1-w];
                if(s>=k)
              {  count+=ld-q+1;
                  break;
              }
            }
        }
        if(rd>1)
        {  int s=a[y][x];
            for(int q=2;q<=lu;q++)
            {  for(int w=1;w<=q;w++)
                 s+=a[y+q-w][x+w-1];
                if(s>=k)
              {  count+=rd-q+1;
                  break;
              }
            }
        }
      }
    }
  printf("%d",count);
  return 0;
}
