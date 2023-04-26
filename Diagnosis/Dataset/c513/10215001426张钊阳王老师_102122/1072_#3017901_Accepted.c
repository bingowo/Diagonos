#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long abss(long long a)
{
    if(a<0) return -a;
    else return a;
}

int i;
int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    int step;
    char s[2000];
    memset(s,'\0',2000);
    step=step0(x,y);//step是计算的总步数
    judge(s,x,y,step);
    printf("%d",step);
    if(step!=-1)
    {
        printf("\n");
    int l=strlen(s);
    for(int i=l-1;i>=0;i--)
        {
            if(s[i]=='E') printf("W");
            else if(s[i]=='W') printf("E");
            else if(s[i]=='S') printf("N");
            else if(s[i]=='N') printf("S");
        }
    }

    return 0;
}

int step0(long long x,long long y)
{
    int step=0;
    if(x<0) x=-x;
    if(y<0) y=-y;
    if(x==0&&y==0)
    {return 0;}
    long long distance=x+y;
    if(distance %2 !=0)
        {
            for(int j = 1; j <= 64; j++)
            {
                if(distance <= (1LL<< j))
                {
                    step += j;
                    break;
                }
            }
            return step;
        }
    else if(distance%2 ==0) return -1;
}

void judge(char *ans,long long x1,long long y1,int step)//step为走到这一步还剩的总步数
{
    if(x1==0&&y1==0) return;
    int flag;
    if(x1>0&&y1>=0) flag=1;
    else if(x1>=0&&y1<0) flag=4;
    else if(x1<0&&y1<=0) flag=3;
    else if(x1<=0&&y1>0) flag=2;
    long long abss(long long a);
    long long x=abss(x1);
    long long y=abss(y1);
    long long xa,ya;
    char temp[3];
    memset(temp,'\0',sizeof(temp));
    if(x>y) {//东西南北分别为: E W S N
        if(flag==1){temp[0]='W';strcat(ans,temp);x1-=(1LL<<step-1);judge(ans,x1,y1,step-1);}
        else if(flag==2){temp[0]='E';strcat(ans,temp);x1+=(1LL<<step-1);judge(ans,x1,y1,step-1);}
        else if(flag==3){temp[0]='E';strcat(ans,temp);x1+=(1LL<<step-1);judge(ans,x1,y1,step-1);}
        else if(flag==4){temp[0]='W';strcat(ans,temp);x1-=(1LL<<step-1);judge(ans,x1,y1,step-1);}
    }
    else if(y>x){
        if(flag==1){temp[0]='S';strcat(ans,temp);y1-=(1LL<<step-1);judge(ans,x1,y1,step-1);}
        else if(flag==2){temp[0]='S';strcat(ans,temp);y1-=(1LL<<step-1);judge(ans,x1,y1,step-1);}
        else if(flag==3){temp[0]='N';strcat(ans,temp);y1+=(1LL<<step-1);judge(ans,x1,y1,step-1);}
        else if(flag==4){temp[0]='N';strcat(ans,temp);y1+=(1LL<<step-1);judge(ans,x1,y1,step-1);}
    }
}

