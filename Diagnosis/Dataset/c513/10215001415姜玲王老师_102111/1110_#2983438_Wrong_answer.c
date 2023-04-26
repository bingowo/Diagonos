#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{

  char a[81];
  int a1[81]={0},a2[81]={0},b1[81]={0},b2[81]={0},k=0,j=0,i=0,h=0,num,l=0;
  char c;
  scanf("%s",a);
  int len=strlen(a);
  while(a[i]!='=')
  {num=0;
  if(a[i]>='0'&&a[i]<='9')
  {for(;a[i]>='0'&&a[i]<='9';i++)
        num=num*10+a[i]-'0';
        if(a[i]=='='||a[i]=='+'||a[i]=='-')
            {b1[j++]=num;continue;}
            else{c=a[i];a1[k++]=num;i++;continue;}}
  if(a[i]>='a'&&a[i]<='z')
            {c=a[i];i++;a1[k++]=1;continue;}
      if(a[i]=='+')
        {i++;
        if(a[i]>='a'&&a[i]<='z')
            {c=a[i];i++;a1[k++]=1;continue;}
            else
                {for(;a[i]>='0'&&a[i]<='9';i++)
                        num=num*10+a[i]-'0';
                    if(a[i]=='='||a[i]=='+'||a[i]=='-')
                    {b1[j++]=num;continue;}
                    else{c=a[i];a1[k++]=num;i++;continue;}}}
    if(a[i]=='-')
        {i++;
        if(a[i]>='a'&&a[i]<='z')
            {c=a[i];i++;a1[k++]=-1;continue;}
            else
                {for(;a[i]>='0'&&a[i]<='9';i++)
                        num=num*10+a[i]-'0';
                    if(a[i]=='='||a[i]=='+'||a[i]=='-')
                    {b1[j++]=-num;continue;}
                    else{c=a[i];a1[k++]=-num;i++;continue;}}}
  }
  i++;
  while(i<len)
  {num=0;
  if(a[i]>='0'&&a[i]<='9')
  {for(;a[i]>='0'&&a[i]<='9'&&i<len;i++)
        num=num*10+a[i]-'0';
        if(a[i]=='-'||a[i]=='+'||i>=len)
            {b2[l++]=num;continue;}
            else{c=a[i];a2[h++]=num;i++;continue;}}
    if(a[i]>='a'&&a[i]<='z')
            {c=a[i];i++;a2[h++]=1;continue;}
      if(a[i]=='+')
        {i++;
        if(a[i]>='a'&&a[i]<='z')
            {c=a[i];i++;a2[h++]=1;continue;}
            else
                {for(;a[i]>='0'&&a[i]<='9'&&i<len;i++)
                        num=num*10+a[i]-'0';
                    if(a[i]=='-'||a[i]=='+'||i>=len)
                    {b2[l++]=num;continue;}
                    else{c=a[i];a2[h++]=num;i++;continue;}}}
    if(a[i]=='-')
        {i++;
        if(a[i]>='a'&&a[i]<='z')
            {c=a[i];i++;a2[h++]=-1;continue;}
            else
                {for(;a[i]>='0'&&a[i]<='9'&&i<len;i++)
                        num=num*10+a[i]-'0';
                    if(a[i]=='-'||a[i]=='+'||a[i]>=len)
                    {b2[l++]=-num;continue;}
                    else{c=a[i];a2[h++]=-num;i++;continue;}}}
  }
  printf("%c=",c);
  double ans=0;
  int x=0,y=0;
  for( i=0;i<j;i++)
  {
      x+=b1[i];
  }
  for( i=0;i<l;i++)
  {
      x-=b2[i];
  }
  for(i=0;i<k;i++)
  {
      y-=a1[i];
  }
  for(i=0;i<h;i++)
  {
      y+=a1[i];
  }
  ans=x*1.0/y*1.0;
  if(x==0) printf("0.000");
  else{printf("%.3lf",ans);}
}

