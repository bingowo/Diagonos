#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int triangle(int r,int c,int len,int d,int k);
int square(int r,int c,int len,int all);
int s[220][220];

int square(int r,int c,int len,int all)
{
    if(len <2)return 0;
    int res = 0;
    res+=triangle(r,c,len,0,all);//左上
    res+=triangle(r,c+len-1,len,1,all);//右上
    res+=triangle(r+len-1,c,len,2,all);//左下
    res+=triangle(r+len-1,c+len-1,len,3,all);//右下
    return res;
}
int triangle(int r,int c,int len,int d,int k)
{
    int res =0;
    int r_;
    switch (d)
    {
    case 0:

        r_=r;
        for(int i =len;i>0;i--)
        {
            for(int n = c;n<c+i;n++)
                {res+=s[r_][n];}
                r_+=1;
        }
        if(res >k&&(len>=3)) return 1+ triangle(r+1,c,len-1,d,k)+triangle(r,c+1,len-1,d,k)+square(r,c,len-2,k);
       else if(res>k&&len==2)return 1;
        else if(res==k)return 1;
        else return 0;
        break;
    case 1:
         r_=r;
        for(int i =len;i>0;i--)
        {
            for(int n = c;n>c-i;n--)
                {res+=s[r_][n];}
                r_+=1;
        }
        if(res >k&&(len>=3)) return 1+ triangle(r-1,c,len-1,d,k)+triangle(r,c+1,len-1,d,k)+square(r,c,len-2,k);
         else if(res>k&&len==2)return 1;
        else if(res==k)return 1;
        else return 0;
        break;
    case 2:
         r_=r;
        for(int i =len;i>0;i--)
        {
            for(int n = c;n<c+i;n++)
                {res+=s[r_][n];}
                r_-=1;
        }
        if(res >k&&(len>=3)) return 1+ triangle(r+1,c,len-1,d,k)+triangle(r,c-1,len-1,d,k)+square(r,c,len-2,k);
        else if(res>k&&len==2)return 1;
        else if(res==k)return 1;
        else return 0;
        break;
    case 3:
         r_=r;
        for(int i =len;i>0;i--)
        {
            for(int n = c;n>c-i;n--)
                {res+=s[r_][n];}
                r_-=1;
        }

        if(res >k&&(len>=3)) return 1+ triangle(r-1,c,len-1,d,k)+triangle(r,c-1,len-1,d,k)+square(r,c,len-2,k);
        else if(res>k&&len==2)return 1;
        else if(res==k)return 1;
        else return 0;
        break;

    }
}
int main()
{
        int r,c,all;
        scanf("%d%d%d",&r,&c,&all);
        for(int i = 0;i<r;i++)
        {
            for(int z = 0;z <c ;z++)
            {
                scanf("%d",&s[i][z]);
            }
        }
        int min = (r<c)?r:c;
        int res = 0;
        if(r<c)
        {
            for(int i =0;i<=c-min;i++)
            {
                res+=square(0,i,min,all);
            }
        }
        else if(r>c)
        {
            for(int k=0;k<=r-min;k++)
            {
                res+=square(k,0,min,all);
            }
        }
        else res+= square(0,0,min,all);
        printf("%d",res);
        return 0;
}

