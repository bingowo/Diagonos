#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++)
    {
        char s1[50];
        scanf("%s",s1);
        int len=strlen(s1);
        int z=0,e=0,r=0,o=0,t=0,w=0,h=0,f=0,u=0,v=0,i=0,s=0,x=0,g=0,n=0;
        for(int j=0;j<len;j++)
        {
            if(s1[j]=='Z') z++;
            if(s1[j]=='E') e++;
            if(s1[j]=='R') r++;
            if(s1[j]=='O') o++;//0
            if(s1[j]=='N') n++;
            if(s1[j]=='T') t++;
            if(s1[j]=='W') w++;
            if(s1[j]=='H') h++;
            if(s1[j]=='F') f++;
            if(s1[j]=='U') u++;
            if(s1[j]=='I') i++;
            if(s1[j]=='V') v++;
            if(s1[j]=='S') s++;
            if(s1[j]=='X') x++;//6
            if(s1[j]=='G') g++;
        }
        int num0=z,num1=o-z-w-u,num2=w,num3=t-w-g,num4=u,num5=f-u,num6=x,num7=s-x,num8=g,num9=i-num5-num6-num8;
        printf("case #%d:\n",k);
        for(int j=0;j<num0;j++) printf("0");
        for(int j=0;j<num1;j++) printf("1");
        for(int j=0;j<num2;j++) printf("2");
        for(int j=0;j<num3;j++) printf("3");
        for(int j=0;j<num4;j++) printf("4");
        for(int j=0;j<num5;j++) printf("5");
        for(int j=0;j<num6;j++) printf("6");
        for(int j=0;j<num7;j++) printf("7");
        for(int j=0;j<num8;j++) printf("8");
        for(int j=0;j<num9;j++) printf("9");
        printf("\n");
    }
    return 0;
}
