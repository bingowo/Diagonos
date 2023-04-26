#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main()
{
    void readst(char *s,int l,int *a);
    char s[1000][100];
    int j=0,n;
    while(gets(s[j]))
    {
        j++;
    }
    n=j;

    for(int z=0;z<n;z++)//研究s[z]
    {
        int t[50];

        char mm[100];
        char nn[100];

        int t1[50];
        int t2[50];

        int a[100];

        memset(t1,0,50);
        memset(t2,0,50);
        memset(a,0,100);
        int i=0,j=0;
        int l=strlen(s[z]);
        while(s[z][i]!=' ')
        {
            mm[j]=s[z][i];
            j++;i++;
        }
        mm[j]='\0';
        i++;j=0;

        while(i<l)
        {
            nn[j]=s[z][i];
            j++;i++;
        }
        nn[j]='\0';
        //分割完成
        char m[100];
        char n[100];
        if(mm[0]!='-'){
            m[0]='+';
            m[1]='\0';
            strcat(m,mm);
        }
        else strcat(m,mm);

        if(nn[0]!='-'){
            n[0]='+';
            n[1]='\0';
            strcat(n,nn);
        }
       else strcat(n,nn);

       int l1=strlen(m),l2=strlen(n);

       readst(m,l1,t1);
       readst(n,l2,t2);


       i=0;j=0;
       for(i=0;i<50;i++)
       {
           if(t1[i]!=0)
           {
               for(j=0;j<50;j++)
               {
                   int time;
                   int temp;
                   if(t2[j]!='0') {
                        temp=t1[i]*t2[j];
                        time=i+j;
                   }
                   a[time]+=temp;
               }
           }
       }
       for(int u=50;u>=0;u--)
       {
           if(a[u]!=0) printf("%d ",a[u]);
       }
       printf("\n");
       memset(a,0,100);
    }
    return 0;
}

void readst(char *s,int l,int *a)
{
    int i;
    for(i=0;i<l;)
    {
        if(s[i]=='-'||s[i]=='+')
           {
               int flag;
               if(s[i]=='-') flag=0;
               else flag=1;
               i++;
               int t=0;
               int temp=0;
               while(s[i]!='x'&&i<l) {t++;i++;}
               for(int r=1;r<=t;r++)
               {
                   if(r==1) temp+=s[i-r]-'0';
                   else temp+=(s[i-r]-'0')*(int)pow(10,r-1);
               }
               if(t==0) temp=1;
               int time=0;
               t=0;
               if(i==l) time=0;
               else {
                    if(s[i+1]!='^') {time=1;i++;}
                    else{
                        i+=2;
                        while(s[i]!='+'&&s[i]!='-'&&i<l) {t++;i++;}
                        for(int r=1;r<=t;r++)
                            {
                            if(r==1) time+=s[i-r]-'0';
                            else time+=(s[i-r]-'0')*pow(10,r-1);
                            }
                        }
               }

               if(flag==0) a[time]-=temp;
               else if(flag==1) a[time]+=temp;

           }
    }
}
