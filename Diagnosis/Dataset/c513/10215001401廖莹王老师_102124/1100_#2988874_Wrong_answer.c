#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int x;
    int y;
}point;
point p[150];
int x1=0,y1=0;
void weizhi(char s[150])
{
    int i=0;
    for(i=0;s[i];i++)
    {   p[i].x=0;p[i].y=0;
        switch(s[i])
        {
            case 'U':if(i==0){p[i].x=0;p[i].y=1;}else{p[i].x=p[i-1].x;p[i].y=p[i-1].y+1;}break;
            case 'D':if(i==0){p[i].x=0;p[i].y=-1;}else{p[i].x=p[i-1].x;p[i].y=p[i-1].y-1;}break;
            case 'L':if(i==0){p[i].x=-1;p[i].y=0;}else{p[i].x=p[i-1].x-1;p[i].y=p[i-1].y;}break;
            case 'R':if(i==0){p[i].x=1;p[i].y=0;}else{p[i].x=p[i-1].x+1;p[i].y=p[i-1].y;}break;
        }
    }
    return;
}
int pd(int a,int b,int l)
{
    int x=0,y=0,m=0,n=0;
    x=a-p[l].x;y=b-p[l].y;
    if((x>=0 && x1>=0)|| (x<=0 && x1<=0))
    {   if(x1==0){if(x!=0) return -1;}
        if(x1!=0)m=x%x1;if(m!=0)return -1;
        else
        {
            if((y>=0 && y1>=0)|| (y<=0 && y1<=0)){if(y1==0){if(y!=0) return -1;}if(y1!=0)n=y%y1;if(n!=0)return -1;else return 1;}
            else return -1;
        }


    }
   else return -1;

}
int main()
{
    char s[150]={0};
    scanf("%s",s);
    weizhi(s);
    int n=0,i=0;
    int j=strlen(s)-1;
    x1=p[j].x;y1=p[j].y;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int a=0,b=0,l=0,f=0;
        scanf("%d %d",&a,&b);
        for(l=0;l<=j;l++)
        {   if(a==0 && b==0){printf("Yes\n");break;}
           else
           {f=pd(a,b,l);
            if(f==1){printf("Yes\n");break;}
           }
        }
        if(f==-1)printf("No\n");
    }
    return 0;
}
