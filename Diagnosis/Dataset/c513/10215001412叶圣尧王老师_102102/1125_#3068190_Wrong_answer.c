#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int pows(int x,int y)
{
    int z=x;
    for(int i=0;i<y;i++)x=x*z;
    return x;
}

int gys(int x,int y)
{
    int temp;
    if(x<y){temp=x;x=y;y=temp;}
    temp=x%y;
    if(temp==0)return y;
    else return(y,temp);
}

int main()
{
    int pows(int x,int y);int gys(int x,int y);
    int T;scanf("%d",&T);int a,b=0,c=0,j,kb=0,kc=0;
    for(int i=0;i<T;i++)
    {
        char s[17];scanf("%s",s);
        for(j=0;j<strlen(s);j++)
        {
            if(s[j]=='.')
            {char s1[17];strncpy(s1,s,j);a=atoi(s1);break;}
        }j++;
        for(;j<strlen(s);j++)
        {
            if(isdigit(s[j])){b=b*10+s[j]-'0';kb++;}
            else break;
        }
        if(j==strlen(s)){c=0;kc=0;}
        else
        {
            j++;
            for(;j<strlen(s)-1;j++)
            {
                c=c*10+s[j]-'0';kc++;
            }
        }
        int d1=b*pows(10,kc)-b+c;
        int d2=pows(10,kb)*(pows(10,kc)-1);
        int m=gys(d1,d2);
        d1=d1/m;d2=d2/m;
        printf("case #%d:\n",i);
        printf("%d/%d\n",d1+d2*a,d2);
    }
}
