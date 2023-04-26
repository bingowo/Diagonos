#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

void fz(int*a,int k)
{
    for(int i=0;i<k/2;i++)
    {
        int c;
        c=a[i];
        a[i]=a[k-i-1];
        a[k-i-1]=c;
    }
}

int scmp(int*a,int a1,int*b,int b1)
{
   if(a1!=b1) return a1-b1;
   else
   {
       char a2[10000],b2[10000];
       for(int i=0;i<a1;i++)
        a2[i]=a[i]+48;
        a2[a1]='\0';
       for(int i=0;i<b1;i++)
        b2[i]=b[i]+48;
       b2[b1]='\0';
       return strcmp(a,b);
    }
}

int main()
{
    char s[20];
    int n;
    scanf("%s",s);
    scanf("%d",&n);
    int len=strlen(s),a,b,z=0,f1=1,f2=1,i=0;

        if(s[i]=='-') {f1=-1;i++;}
        while(s[i]!='-'&&s[i]!='+'&&s[i]!='\0'&&s[i]!='i')
            {z=z*10+s[i]-48;i++;}
        if(s[i]=='i')
        {
            if(z==0) b=1*f1;
            else b=z*f1;
        }
        else
            {
                a=z*f1;
                if(s[i]=='-') f2=-1;
                i++;
                z=0;
                while(s[i]!='\0'&&s[i]!='i')
                    z=z*10+s[i]-48;
                if(s[i]='i')
                {
                    if(z==0) b=1*f2;
                    else b=z*f2;
                }
            }

    int ss1[10000]={0},ff1[10000]={0},ss2[10000]={0},ff2[10000]={0},ss3[10000]={0},ff3[10000]={0};
    ss1[0]=1;ff1[0]=1;ff3[0]=1;ss3[0]=1;ss2[0]=a;ff2[0]=b;
    int wei1=1,wei2=1,wei3=1,wei4=1,flagss1=1,flagss3=1,flagff1=(a>0)?1:-1,flagff3=(b>0)?1:-1,flag1=1,flag2=1;
    int yu1=0,yu2=0;
    int t,e;
    int maxz=1,maxf=1;
    for(int k=0;k<n-1;k++)
    {
        yu1=0;
        if(a<0) {t=-a;flagss1*=-1;}
        else t=a;
        for(int l=0;l<wei1;l++)
        {
            ss1[l]=(ss2[l]*t+yu1)%10;
            yu1=(ss2[l]*t+yu1)/10;
        }
        while(yu1>0){ss1[wei1]=yu1;wei1++;yu1/=10;}

        if(b<0) {e=-b;flagss3*=-1;}
        else e=b;
        for(int l=0;l<wei2;l++)
        {

            ss3[l]=(ff2[l]*e+yu1)%10;
            yu1=(ff2[l]*e+yu1)/10;
        }
        while(yu1>0) {ff1[wei2]=yu1;wei2++;yu1/=10;}
        maxz=(wei1>wei2)?wei1:wei2;
        if((flagss1==1&&flagss3==-1)||(flagss1==-1&&flagss3==1))
        {
            yu1=0;
            for(int l=0;l<maxz;l++)
            {
                ss2[l]=(ss1[l]+ss3[l]+yu1)%10;
                yu1=(ss1[l]+ss3[l]+yu1)/10;
            }
            while(yu1>0) {ss2[maxz]=yu1;maxz++;yu1/=10;}
            if(flagss1==1) flag1*=1;
            else flag1*=-1;
        }
        else
        {if(scmp(ss1,wei1,ss3,wei3)>0)
        {int jie=0;
        for(int l=0;l<maxz;l++)
        {
            ss2[l]=ss1[l]-ss3[l]-jie;
            if(ss2[l]<0) {ss2[l]+=10;jie=1;}
            else jie=0;
        }
        if(flagss1==1&&flagss3==1) flag1*=1;
        if(flagss1==-1&&flagss3==-1) flag1*=-1;}
        if(scmp(ss1,wei1,ss3,wei3)<=0)
        {
            int jie=0;
        for(int l=0;l<maxz;l++)
        {
            ss2[l]=ss3[l]-ss1[l]-jie;
            if(ss2[l]<0) {ss2[l]+=10;jie=1;}
            else jie=0;
        }
        if(flagss1==1&&flagss3==1) flag1*=-1;
        if(flagss1==-1&&flagss3==-1) flag1*=1;}}


        if(a<0){t=-a;flagff1*=-1;}
        else t=a;
        yu2=0;
        for(int l=0;l<wei3;l++)
        {
            ff1[l]=(ff2[l]*t+yu2)%10;
            yu2=(ff2[l]*t+yu2)/10;
        }
        while(yu2>0) {ff1[wei3]=yu2;wei3++;yu2/=10;}

        if(b<0) {e=-b;flagff3*=-1;}
        else e=b;
        for(int l=0;l<wei4;l++)
        {
            ff3[l]=(ss2[l]*e+yu2)%10;
            yu2=(ss2[l]*e+yu2)/10;
        }
        while(yu2>0) {ff3[wei4]=yu2;wei4++;yu2/=10;}
        maxf=(wei3>wei4)?wei3:wei4;
        if((flagff1==1&&flagff3==1)||(flagff1==-1&&flagff3==-1))
        {
        yu2=0;
        for(int l=0;l<maxf;l++)
        {
            ff2[l]=(ff1[l]+ff3[l]+yu2)%10;
            yu2=(ff1[l]+ff3[l]+yu2)/10;
        }
        if(yu2>0) {ff2[maxf]=yu2;maxf++;}
        if(flagff1==1) flag2*=1;
        else flag2*=-1;
        }
        else
        {
            if(scmp(ff1,wei3,ff3,wei4)>0)
            {
                int jie=0;
                for(int l=0;l<maxf;l++)
                {
                    ff2[l]=ff1[l]-ff3[l]-jie;
                    if(ff2[l]<0) {ff2[l]+=10;jie=1;}
                    else jie=0;
                }
                if(flagff1==1&&flagff3==-1) flag2*=1;
                if(flagff1==-1&&flagff1==1) flag2*=-1;
            }
            if(scmp(ff1,wei3,ff3,wei4)<0)
            {
                int jie=0;
                for(int l=0;l<maxf;l++)
                {
                    ff2[l]=ff3[l]-ff1[l]-jie;
                    if(ff2[l]<0) {ff2[l]+=10;jie=1;}
                    else jie=0;
                }
                if(flagff1==1&&flagff3==-1) flag2*=-1;
                if(flagff1==-1&&flagff1==1) flag2*=1;
            }
        }

    }
    fz(ss2,maxz);
    fz(ff2,maxf);
    int p=0;
    while(ss2[p]==0&&ss2[p]) p++;
    for(int d=p;d<maxz;d++)
        printf("%d",ss2[d]);
    printf("\n");
    p=0;
    while(ff2[p]==0&&ff2[p]) p++;
    for(int d=p;d<maxf;d++)
        printf("%d",ff2[d]);
    return 0;
}
