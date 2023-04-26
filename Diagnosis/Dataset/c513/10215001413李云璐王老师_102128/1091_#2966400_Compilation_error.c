#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[20];
    int n;
    scanf("%s",s);
    scanf("%d",&n);
    int len=strlen(s),a,b,z=0,f1=1,f2=1,i=0;
    while(i<len)
    {
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
    }
    int ss1[10000]={0},ff1[10000]={0},ss2[10000]={0},ff2[10000]={0},ss3[10000]={0},ff3[10000]={0};
    ss1[0]=1;ff1[0]=1;ff3[0]=1;ss3[0]=1;ss2[0]=1;ff2[0]=1;
    int wei1=1,wei2=1,wei3=1,wei4=1,flag1=1,flag2=1;
    int yu1=0,yu2=0;
    for(int k=0;k<n;k++)
    {
        yu1=0;
        for(int l=0;l<wei1;l++)
        {
            ss1[l]=(ss2[l]*a+yu1)%10;
            yu1=(ss2[l]*a+yu1)/10;
        }
        while(yu1>0){ss1[wei1]=yu1;wei1++;yu1/=10;}
        for(int l=0;l<wei2;l++)
        {
            
            ss3[l]=(ff2[l]*b+yu1)%10;
            yu1=(ff2[l]*b+yu1)/10;
        }
        while(yu1>0) {ff1[wei2]=yu1;wei2++;yu1/=10;}
        if(wei2>wei1) flag1*=-1;
        else if(panduan())    
        int maxz1=(wei1>wei2)?wei1:wei2;
        int jie=0;
        for(int l=0;l<maxz;l++)
        {
            ss2[l]=ss1[l]-ss3[l]-jie;
            if(ss2[l]<0) {ss[l]+=10;jie=1;}
            else jie=0;
        }
        yu2=0;
        for(int l=0;l<wei3;l++)
        {
            ff1[l]=(ff2[l]*a+yu2)%10;
            yu2=(ff2[l]*a+yu2)/10;
        }
        while(yu2>0) {ff1[wei3]=yu2;wei3++;yu2/=10;}
        for(int l=0;l<wei4;l++)
        {
            ff3[l]=(ss2[l]*b+yu2)%10;
            yu(ss2[l]*b+yu2)/10;
        }
        while(yu2>0) {ff3[wei4]=yu2;wei4++;yu2/=10;}
        int maxf=(wei3>wei4)?wei3:wei4;
        yu2=0;
        for(int l=0;l<maxf;l++)
        {
            ff2[l]=(ff1[l]+ff3[l]+yu2)%10;
            yu2=(ff1[l]+ff3[l]+yu2)/10;
        }
        if(yu2>0) {ff2[maxf]=yu2;maxf++;}
        
    }
    fz(ss2,maxz);
    fz(ff2,maxf);
    int p=0;
    while(ss2[p]==0&&ss2[p]) p++;
    if(p==maxz) printf("0");
    else if(p==maxz-1) printf("%d",ss2[p]);
    else for(int l=p;l<maxz;l++)
        printf("%d",ss2[l]);
    
    
    




}
