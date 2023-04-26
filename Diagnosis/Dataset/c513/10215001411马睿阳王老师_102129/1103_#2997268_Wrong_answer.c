#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{char s[3];int num;}val;

char s1[3]={"IN"},s2[4]={"MOV"},s3[4]={"ADD"},s4[4]={"SUB"},s5[4]={"MUV"},s6[4]={"DIV"},s7[4]={"OUT"};

int main()
{
     int i=0,j=4,k=0,h1=0,h2=0,sign=1,sum=0,h=0;
     char imp[20]={0},s[4]={0},ele1[20]={0},ele2[20]={0};
     val cp[4]={"AX",0,"BX",0,"CX",0,"DX",0};
     while(scanf("%s",s)!=EOF)
     {
         scanf("%s",imp);
         sign=1;
         ele1[0]="0\n";
         ele2[0]="0\n";
         int len=strlen(imp);
         for(i=0;imp[i]!=','&&i<len;i++)
         ele1[i]=imp[i];
         ele1[i]='\0';
         for(i+=1,k=0;i<len;i++,k++)
         {
             if(imp[i]=='-') {sign=-1;k--;}
             else ele2[k]=imp[i];
         }
         ele2[k]='\0';
         if(strcmp(s,s1)==0)
         {
             for(h=0,sum=0;h<k;h++)
                 sum=sum*10+ele2[h]-'0';
             for(h=0;h<j;h++)
             {
                 if(strcmp(ele1,cp[h].s)==0)
                 {
                     cp[h].num=sign*sum;
                 }
             }
         }

         else if(strcmp(s,s2)==0)
         {
             for(h=0;h<j;h++)
             {
                 if(strcmp(ele1,cp[h].s)==0) {h1=h;}
                 if(strcmp(ele2,cp[h].s)==0) {h2=h;}
             }
             cp[h1].num=cp[h2].num;
         }
         else if(strcmp(s,s3)==0)
         {
             for(h=0;h<j;h++)
             {
                 if(strcmp(ele1,cp[h].s)==0) h1=h;
                 if(strcmp(ele2,cp[h].s)==0) h2=h;
             }
             cp[h1].num+=cp[h2].num;
         }
         else if(strcmp(s,s4)==0)
         {
             for(h=0;h<j;h++)
             {
                 if(strcmp(ele1,cp[h].s)==0) {h1=h;}
                 if(strcmp(ele2,cp[h].s)==0) {h2=h;}
             }
             cp[h1].num-=cp[h2].num;
         }
         else if(strcmp(s,s5)==0)
         {
             for(h=0;h<j;h++)
             {
                 if(strcmp(ele1,cp[h].s)==0) {h1=h;}
                 if(strcmp(ele2,cp[h].s)==0) {h2=h;}
             }
             cp[h1].num*=cp[h2].num;
         }
          else if(strcmp(s,s6)==0)
         {
             for(h=0;h<j;h++)
             {
                 if(strcmp(ele1,cp[h].s)==0) {h1=h;}
                 if(strcmp(ele2,cp[h].s)==0) {h2=h;}
             }
             cp[h1].num/=cp[h2].num;
         }
         else if(strcmp(s,s7)==0)
         {
             for(h=0;h<j;h++)
             {
                 if(strcmp(ele1,cp[h].s)==0)
                 printf("%d",cp[h].num);
             }
         }

     }
 return 0;
}
