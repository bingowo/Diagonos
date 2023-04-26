#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void val1(int a)
{
    if(sqrt(a)*sqrt(a)==a)printf("%f %d %f %d",sqrt(a),0,sqrt(a),0);
    else printf("No Answer!");
}

void val2(int a,int c)
{
    if(c>0)printf("No Answer!");
    else 
    {
        int m=sqrt(c*-1),n=sqrt(a);
        if(m*m==c*-1&&n*n==a)printf("%d %d %d %d",n,m*-1,n,m);
        else printf("No Answer!");
    }
}

void val3(int a,int b)
{
    if(a==1&&b<0)printf("%d %d 1 0",a,b);
    else printf("1 0 %d %d",a,b);
}

void val4(int a,int b,int c)
{
    int a1,c1,a2,c2,flag=1;
    for(a1=1;a1<=sqrt(a)&&flag==1;a1++)
    {
        a2=a/a1;
        if(a1*a2!=a)continue;
        else
        {
                for(c1=-1*abs(c);c1<=abs(c);c1++)
                {
                    if(c1==0)continue;
                    c2=c/c1;
                    if(c1*c2!=c)continue;
                    else
                    {
                        if(a1*c2+a2*c1==b){printf("%d %d %d %d",a1,c1,a2,c2);flag=0;break;}
                    }
                }
            
        }
    }
    if(flag==1)printf("No Answer!");
}

int main()
{
    char s[50];scanf("%s",s);
    int i,j,a[3]={0},t;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='-')
        {
            if(s[i+1]=='x')
            {
                if(s[i+2]=='^'){a[2]=-1;i+=3;}
                else {a[1]=-1;i+=1;}
            }
            else
            {
                t=0;
                for(j=i+1;isdigit(s[j])&&j<strlen(s);j++)
                    t=t*10+s[j]-'0';
                if(j==strlen(s)){a[0]=t*-1;i=j;}
                else
                {
                    if(s[j+1]=='^'){a[2]=-1*t;i=j+2;}
                    else {a[1]=t*-1;i=j;}
                }
            }
        }
        else if(s[i]=='+')
        {
            if(s[i+1]=='x')
            {
                if(s[i+2]=='^'){a[2]=1;i+=3;}
                else {a[1]=1;i+=1;}
            }
            else
            {
                t=0;
                for(j=i+1;isdigit(s[j])&&j<strlen(s);j++)
                    t=t*10+s[j]-'0';
                if(j==strlen(s)){a[0]=t;i=j;}
                else
                {
                    if(s[j+1]=='^'){a[2]=t;i=j+2;}
                    else {a[1]=t;i=j;}
                }
            }
        }
        else if(isdigit(s[i]))
        {
            t=s[i]-'0';
            if(s[i+1]=='x')
            {
                if(s[i+2]=='^'){a[2]=t;i+=3;}
                else {a[1]=t;i+=1;}
            }
            else
            {
                t=0;
                for(j=i;isdigit(s[j])&&j<strlen(s);j++)
                    t=t*10+s[j]-'0';
                if(j==strlen(s)){a[0]=t;i=j;}
                else
                {
                    if(s[j+1]=='^'){a[2]=t;i=j+2;}
                    else {a[1]=t;i=j;}
                }
            }
        }
        else if(s[i]=='x')
        {
            if(s[i+1]=='^'){a[2]=1;i+=2;}
            else {a[1]=1;i+=1;}
        }
    }
    
    if(a[2]==0)printf("No Answer!");
    else
    {
        if(a[1]==0&&a[0]==0)val1(a[2]);
        if(a[1]==0&&a[0]!=0)val2(a[2],a[0]);
        if(a[1]!=0&&a[0]==0)val3(a[2],a[1]);
        if(a[1]!=0&&a[0]!=0)val4(a[2],a[1],a[0]);
    }
}
