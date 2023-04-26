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
        {  int s=0;
            for(int q=2;q<=lu;q++)
            {  for(int w=0;w<q;w++)
                { for(int e=0;e<q-w;e++)
                    s+=a[x-w][y-e];
                }
              if(s>=k)
              {  count+=lu-q+1;
                  break;
              }

            }
        }
        if(ru>1)
        {  int s=0;
            for(int q=2;q<=ru;q++)
            {  for(int w=0;w<q;w++)
                { for(int e=0;e<q-w;e++)
                    s+=a[x+w][y-e];
                }
              if(s>=k)
              {  count+=ru-q+1;
                  break;
              }

            }
        }
        if(ld>1)
        {  int s=0;
            for(int q=2;q<=ld;q++)
            {  for(int w=0;w<q;w++)
                { for(int e=0;e<q-w;e++)
                    s+=a[x-w][y+e];
                }
              if(s>=k)
              {  count+=ld-q+1;
                  break;
              }

            }
        }
        if(rd>1)
        {  int s=0;
            for(int q=2;q<=rd;q++)
            {  for(int w=0;w<q;w++)
                { for(int e=0;e<q-w;e++)
                    s+=a[x+w][y+e];
                }
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
