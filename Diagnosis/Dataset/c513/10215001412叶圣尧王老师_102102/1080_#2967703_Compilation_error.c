#include <stdio.h>
#include <stdlib.h>
#define END 10
void init(int *n)
{
    char c;int i=0;
     while((c=getchar())!='\n')
     {
         n[i]=c-'0';
         i++;
     }
     n[i]=END;
}
void multiout(int* out)
{
     int *p=out,carry,plus=0;
     while(1)
     {
         if(*p==-1)
         {
             if(p-out==0)
             {
                 *p=0;
                 return;
             }
             else if(plus==1)
                     *p=plus;
             return;
         }
         carry=*p*2+plus;  
         *p=carry%10;
         plus=carry/10;
         p++;
     }
 
 }
 void addout(int* out,int get)
 {
     int* p=out;
     if(get==0) return;
 
     else
     {
 
         *p=*p+1;
         while(*p==10)
         {
             *p=0;
             (*(++p))++;
         }
     }
 
 }
 
 int main()
 {
     int cas;scanf("%d\n",&cas);
     for(int m=0;m<cas;m++)
     {
         int BIGINT[101],bin[335],pos=0,binpos;
         init(BIGINT);
         for(binpos=0;BIGINT[pos]!=END;binpos++) 
         {    int rmd=0,divd;　　　　　　　　
             for(int i=pos;BIGINT[i]!=END;i++)
             {　　　　　　　　　　　　　　　　　　
                 divd=rmd*10+BIGINT[i];
                 rmd=divd%2;　　　　　　　　
                 BIGINT[i]=divd/2;　　　
             }　　　　　　　　　
             bin[binpos]=rmd;　　　　　　　　　　
             if(BIGINT[pos]==0)    pos++;　　　　　
         }　　　　　　　　　　　　　　　　　　　　　　　 
         bin[binpos]=END;　　　　　　　　　　　　　
         for(int i=1;i<110;i++) out[i]=-1;
         for(int i=1;bin[i]!=END;i++)　　　　　　
         {
             multiout(out);
             addout(out,bin[i]);
         }
         for(;out[ppos+1]!=-1;ppos++);
 
         printf("case #%d:\n",m);
         for(ppos;ppos>=0;ppos--)
             printf("%d",out[ppos]);
         printf("\n");
 
     }
     return 0;}
