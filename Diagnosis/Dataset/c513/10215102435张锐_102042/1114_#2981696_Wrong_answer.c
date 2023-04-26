#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int a=0,b=0,c=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='x')
        {
            int j;int t=1;
            for(j=i-1;;j--) if(!isdigit(s[j])) break;
            if(s[j]=='-') t=-1;
            int temp=0;int bo=1;
            if(j==i-1&&s[i-1]!='-') temp=1,bo=0;
            if(j==i-1&&s[i-1]=='-') temp=-1,bo=0;
            else
            {
                j++;
                while(isdigit(s[j])) temp=temp*10+(s[j++]-'0');
            }
            if(s[i+1]=='^')
            {
                if(s[i+2]=='2'&&bo==1) a=temp*t;
                if(s[i+2]=='2'&&bo==0) a=temp;
            }
            else b=temp*t;
        }
        if(i==len-1&&isdigit(s[i])&&s[i-1]!='^')
        {
            int j;int t=1;
            for(j=i-1;;j--) if(!isdigit(s[j])) break;
            if(s[j]=='-') t=-1;
            int temp=0;
            {
                j++;
                while(isdigit(s[j])) temp=temp*10+(s[j++]-'0');
            }
            c=temp*t;
        }
    }
    int a1=0,c1=0,a2=0,c2=0;
    if(b==0) printf("No Answer!\n");
    else if(c==0)
    {
        a1=1,c1=0,a2=a,c2=b;
        printf("%d %d %d %d\n",a1,c1,a2,c2);
    }
    else
    {
        int aa[100][2]={0},cc[100][2]={0};int pa=0,pc=0;
        for(int i=1;i<=abs(a);i++)
        {
            int ta=a;
            if(a<0) ta=-a;
            if(ta%i==0)
            {
                if(a>0)
                {
                    aa[pa][0]=i,aa[pa++][1]=ta/i;
                    aa[pa][0]=-i,aa[pa++][1]=-ta/i;
                }
                if(a<0)
                {
                   aa[pa][0]=-i,aa[pa++][1]=ta/i;
                   aa[pa][0]=i,aa[pa++][1]=-ta/i;
                }
            }
        }
        for(int i=1;i<=abs(c);i++)
        {
            int tc=c;
            if(c<0) tc=-c;
            if(tc%i==0)
            {
                if(c>0)
                {
                    cc[pc][0]=i,cc[pc++][1]=tc/i;
                    cc[pc][0]=-i,cc[pc++][1]=-tc/i;
                }
                if(c<0)
                {
                   cc[pc][0]=-i,cc[pc++][1]=tc/i;
                   cc[pc][0]=i,cc[pc++][1]=-tc/i;
                }
            }
        }
        for(int i=0;i<pa;i++)
        {
            for(int j=0;j<pc;j++)
            {
                if(aa[i][0]*cc[j][1]+aa[i][1]*cc[j][0]==b) {a1=aa[i][0],c1=cc[j][0],a2=aa[i][1],c2=cc[j][1];break;}
                if(aa[i][0]*cc[j][0]+aa[i][1]*cc[j][1]==b) {a1=aa[i][0],c1=cc[j][1],a2=aa[i][1],c2=cc[j][0];break;}
            }
            if(a1!=0) break;
        }
        if(a1==0) printf("No Answer!\n");
        else
        {
            if(a1>a2)
            {
                int ta=a1,tc=c1;
                a1=a2,c1=c2;a2=ta,c2=tc;
            }
            if(a1==a2&&c1>c2)
            {
                int tc=c1;c1=c2;c2=c1;
            }
            printf("%d %d %d %d\n",a1,c1,a2,c2);
        }
    }
    return 0;
}
