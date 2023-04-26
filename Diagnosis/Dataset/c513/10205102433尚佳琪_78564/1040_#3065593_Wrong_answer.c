#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int stoi(char s[])
{
    if(strcmp(s,"A")==0)
        return 0;
    else if(strcmp(s,"AB")==0)
        return 1;
    else if(strcmp(s,"B")==0)
        return 2;
    else //if(strcmp(s,"O"))
        return 3;
}
void itos(char s[],int i)
{
    if(i==0)
        strcpy(s,"A");
    else if(i==1)
        strcpy(s,"AB");
    else if(i==2)
        strcpy(s,"B");
    else if(i==3)
        strcpy(s,"O");
    //printf("%d",i);
}
int main()
{
char p[17][5]={"1001","1111","1110","1001",
    "1111","0011","1110","0011",
    "1110","1110","1110","1010",
    "1001","0011","1010","0001"};
   char f[5],m[5],c[5];
  // int father=0,mother=0,child=0;
   scanf("%s %s %s",f,m,c);

   if(strcmp(c,"?")==0)
   {
       printf("%s %s {",f,m);
       int fa=stoi(f);
       int mo=stoi(m);
       char ans[5];
       strcpy(ans,p[fa*4+mo]);
       char ans2[5][5];
       int k=0;
       for(int i=0;i<4;i++)
       {
           if(ans[i]=='1') itos(ans2[k++],i);
       }
       for(int i=0;i<k-1;i++)
            printf("%s,",ans2[i]);
       printf("%s}",ans2[k-1]);
   }
   else if(strcmp(m,"?")==0)
   {
       int fa=stoi(f);//2
       int ch=stoi(c);//3
       char ans2[5][5];
       int k=0;
       for(int i=fa*4;i<fa*4+4;i++)
       {
           if(p[i][ch]=='1')
           {
               itos(ans2[k++],i-fa*4);
           }
       }
       printf("%s ",f);
       if(k==0)printf("impossible");
       else{
            printf("{");
            for(int i=0;i<k-1;i++)
                printf("%s,",ans2[i]);
            printf("%s}",ans2[k-1]);
       }
       printf(" %s",c);
   }
    else if(strcmp(f,"?")==0)
   {
       int ma=stoi(m);//2
       int ch=stoi(c);//3
       char ans2[5][5];
       int k=0;
       for(int i=ma*4;i<ma*4+4;i++)
       {
           if(p[i][ch]=='1')
           {
               itos(ans2[k++],i-ma*4);
           }
       }
       if(k==0)printf("impossible");
       else{
            printf("{");
            for(int i=0;i<k-1;i++)
                printf("%s,",ans2[i]);
            printf("%s}",ans2[k-1]);
       }
        printf(" %s",m);
       printf(" %s",c);
   }
//father=1;
  /* else if(f=='?')mother=1;
   else if(c=='?')
   {
      child=1;

   }*/

}
