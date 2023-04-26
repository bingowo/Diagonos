#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{ char s[110000],c[10000][10000]; int i,j,x,y,a[110000],count,f,k;
 gets(s);
    i=0;j=0;count=0;
    a[0]=0;f=0;
    while(s[i])
    { if (s[i]=='0'&&s[i+1]=='x') 
    { j=i+2;
     while((s[j]>='0'&&s[j]<='9')||(s[j]>='a'&&s[j]<='f'))
    { count++; c[count-1][f]=s[j];j++;f++;
        }
       f=0; 
    }
    i++;
    }
    if(count==0) printf("-1");
    else{
    for(k=0;k<count;k++)
    printf("%s ",c[k]);
}}