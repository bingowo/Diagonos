#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{ char s[110000],c[100000][100]; int i,j,x,y,count,f,k,l,d; long long int a[110000];
 gets(s);
    i=0;j=0;count=0;
    a[0]=0;f=0;
    while(s[i])
    { if (s[i]=='0'&&s[i+1]=='x') 
    { j=i+2;  if ((s[j]>='0'&&s[j]<='9')||(s[j]>='a'&&s[j]<='f')) count++; 
     while((s[j]>='0'&&s[j]<='9')||(s[j]>='a'&&s[j]<='f'))
    { c[count-1][f]=s[j];j++;f++;
        }
       f=0; 
    }
    i++;
    }
    if(count==0) printf("-1");
    else{
    for(k=0;k<count;k++)
   { l=strlen(c[k]); a[k]=0;
    for(d=0;d<=l-1;d++)
    { if(c[k][d]<='9'&&c[k][d]>='1') a[k]=a[k]*16+c[k][d]-'0';
    else if (c[k][d]<='f'&&c[k][d]>='a') a[k]=a[k]*16+c[k][d]-'a'+10;}
    }
    for(k=0;k<count;k++)
    printf("%lld ",a[k]);
}
        
    }