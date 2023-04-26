#include <stdio.h>
#include <string.h>
/*int main()
{
    char s[101];
    scanf("%s",s);
    char *p=s;
    int x=0,y=0;
    while(*p)
    {
        if(*p=='U')y++;
        else if(*p=='D')y--;
        else if(*p=='L')x--;
        else if(*p=='R')x++;
        p++;
    }
    p=s;
    //printf("%d %d\n",x,y);
    int count;
    scanf("%d\n",&count);
    while(count--)
    {
        int m,n,x1=0,y1=0,flag=0,t1=0,t2=0;
        scanf("%d %d",&m,&n);

        while(*p)
        {
            //printf("%d %d！！%d %d\n",x1,y1,m,n);
            if(x1==m&&y1==n){printf("Yes\n");flag=1;}
            if(*p=='U')y1++;
            else if(*p=='D')y1--;
            else if(*p=='L')x1--;
            else if(*p=='R')x1++;
            p++;
            if(flag==1){break;}
        }p=s;x1=0;y1=0;if(flag==1){continue;}




            if(x!=0)t1=m/x;
            if(y!=0)t2=n/y;
            if(t1>0&&t2>0)
            {
                if(t1>t2)t1=t2;
                else t2=t1;
            }
            if(x!=0&&m/x>0)
            x1=x*t1;
            else if(y!=0&&n/y>0) x1=x*t2;
            else x1=x;
            if(y!=0&&n/y>0)
            y1=y*t2;
            else if(x!=0&&m/x>0) y1=y*t1;
            else y1=y;
        //printf("%d %d！！%d %d\n",x1,y1,m,n);
        while(*p)
        {
            //printf("%d %d！！%d %d\n",x1,y1,m,n);
            if(x1==m&&y1==n){printf("Yes\n");flag=1;}
            if(*p=='U')y1++;
            else if(*p=='D')y1--;
            else if(*p=='L')x1--;
            else if(*p=='R')x1++;
            p++;
            if(flag==1){break;}
        }p=s;
        if(flag==0)
            {


        if(x!=0)t1=m/x;
            if(y!=0)t2=n/y;
            if(t1>0&&t2>0)
            {
                if(t1>t2)t2=t1;
                else t1=t2;
            }
            if(x!=0&&m/x>0)
            x1=x*t1;
            else if(y!=0&&n/y>0) x1=x*t2;
            else x1=x;
            if(y!=0&&n/y>0)
            y1=y*t2;
            else if(x!=0&&m/x>0) y1=y*t1;
            else y1=y;
        //printf("%d %d！！%d %d\n",x1,y1,m,n);
        while(*p)
        {
            //printf("%d %d！！%d %d\n",x1,y1,m,n);
            if(x1==m&&y1==n){printf("Yes\n");flag=1;}
            if(*p=='U')y1++;
            else if(*p=='D')y1--;
            else if(*p=='L')x1--;
            else if(*p=='R')x1++;
            p++;
            if(flag==1){break;}
        }p=s;
        if(flag==0)
            {printf("No\n");}


        }

    }

}*/

int solution(int t,int r)                 //单个方程求解m
{
    if (t==0&&r!=0) return -2;             //无解
    if (t==0&&r==0) return -1;           //任意解
    if (r%t!=0||r/t<0) return -2;           //解为负数或非整数，非法解
    return r/t;                                      //返回解
}



int main()
{
    struct point
    {    int a,b; };
    struct point pos[200];
    char s[200];
    scanf("%s",s);    int len=strlen(s);
pos[0].a=0;pos[0].b=0;   //记录起始位置(0,0)
for(int i=1;i<=len;i++)        //记录第一轮命令序列经过的每一个位置点
{
    switch(s[i-1])
    {
        case 'U':pos[i].a=pos[i-1].a;pos[i].b=pos[i-1].b+1;break;
        case 'D':pos[i].a=pos[i-1].a;pos[i].b=pos[i-1].b-1;break;
        case 'L':pos[i].a=pos[i-1].a-1;pos[i].b=pos[i-1].b;break;
       case 'R':pos[i].a=pos[i-1].a+1;pos[i].b=pos[i-1].b;break;
      }
 }
 int count;
    scanf("%d\n",&count);
for(int i=0;i<count;i++)
     {
         int flag=0,a,b;
         scanf("%d%d",&a,&b);
         for(int j=0; j<=len; j++)
        {
            int m1,m2;
            m1=solution(-pos[len].a,pos[j].a-a);      //求解第一个方程m1
            m2=solution(-pos[len].b,pos[j].b-b);      //求解第二个方程m2
            if (m1 == -2||m2 == -2) continue;                                    //无解情况
            if (m1 == -1||m2 == -1||m1 == m2)                //判断两坐标轴的解是否相同
            {   flag=1;  break;  }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
     }

}
