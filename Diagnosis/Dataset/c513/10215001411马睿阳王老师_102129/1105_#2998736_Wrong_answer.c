#include <stdio.h>
#include <stdlib.h>


int main()
{int H,W;
 int i=0,j=0,k=0,t=0,h=0;
 int q=0,w=0;
 scanf("%d%d",&W,&H);
 int s[200][200]={0};
 int d[8]={0};
 int l[8]={0};
 int a[200][200]={0};
 for(i=0;i<H;i++)//竖向
 {
      for(j=0;j<W;j++)//横向
     {scanf("%d",&s[i][j]);}
  }
  ///开始计算
  //先转换成0,1形式
  for(i=0;i<=H-3;i++)//竖向
  {
  for(j=0;j<=W-3;j++)//横向
  {
      if(s[i][j]>=s[i+1][j+1]) d[0]=1;
      else d[1]=0;
       if(s[i][j+1]>=s[i+1][j+1]) d[1]=1;
      else d[2]=0;
       if(s[i][j+2]>=s[i+1][j+1]) d[2]=1;
      else d[3]=0;
       if(s[i+1][j+2]>=s[i+1][j+1]) d[3]=1;
      else d[4]=0;
       if(s[i+2][j+2]>=s[i+1][j+1]) d[4]=1;
      else d[5]=0;
       if(s[i+2][j+1]>=s[i+1][j+1]) d[5]=1;
      else d[6]=0;
       if(s[i+2][j]>=s[i+1][j+1]) d[6]=1;
      else d[7]=0;
       if(s[i+1][j]>=s[i+1][j+1]) d[7]=1;
      else d[8]=0;
  //再计算LBP值
  for(t=0;t<8;t++)//从t开始算
  {
      for(k=t;k<8;k++)
       l[t]=l[t]*2+d[k];
      if(t==0)  k=0;
      else
      {for(k=0;k<t;k++)
        l[t]=l[t]*2+d[k];
      }
  }
  for(q=0;q<8;q++)
  d[q]=0;
  //比较LBP的值，用a[]储存
  for(h=0;h<7;h++)
  {
      if(l[h]>l[h+1]) a[i][j]=l[h];
      else a[i][j]=l[h+1];
  }
  for(q=0;q<8;q++)
  l[q]=0;
  }
  ///输出a
  for(i=0;i<=H-3;i++)
  {
      for(j=0;j<=W-3;j++)
      {printf("%d",a[i][j]);}
      printf("\n");
  }
  }
return 0;
}
