#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void multiply(char*a)
{
    int i,len=strlen(a);
    char b[1001]={0};
    int temp;
    for(i=0;i<len;i++)
    {
        temp=(a[i]-'0')*4+b[i];
        b[i]=temp%10+'0';
        b[i+1]+=temp/10;
    }
    if(b[i]){b[i]+='0';}
    strcpy(a,b);
}
void plus(char*a,int b)
{
    int i;
    a[0]+=b;
    if(a[0]<='9'){return;}
    a[0]=(a[0]-'0')%10+'0';
    for(i=1;a[i]=='9';i++){a[i]='0';}
    if(a[i]==0) a[i]+='0';
    a[i]++;
}
void minus(char*a,int b)
{
    int i;
    if(a[0]-b>='0'){a[0]-=b;return;}
    a[0]=a[0]+10-b;
    for(i=1;a[i]=='0';i++){a[i]='9';}
    a[i]--;
    if(a[i]=='0') a[i]=0;
}
int main()
{
   char a[100];
   scanf("%s",a);
   int b[16][4]={{0,1,0,1},{1,1,0,1},{1,-1,1,1},{0,1,1,1},{0,1,2,-1},{1,1,2,-1},{1,-1,1,-1},{0,1,1,-1},{2,1,2,1},{3,1,2,1},{1,1,3,1},{2,1,3,1},{2,1,0,1},{3,1,0,1},{1,1,1,1},{2,1,1,1}};
   char c0[1001]={0},c1[1001]={0};
   int flag1,flag2,i,p;
   if(a[2]>='0'&&a[2]<='9')
    {
        p=a[2]-'0';
       c0[0]=b[p][0]+'0';
       flag1=b[p][1];
       c1[0]=b[p][2]+'0';
       flag2=b[p][3];
   }
   if(a[2]>='A')
    {
        p=a[2]-'A'+10;
       c0[0]=b[p][0]+'0';
       flag1=b[p][1];
       c1[0]=b[p][2]+'0';
       flag2=b[p][3];
   }
   int len=strlen(a);
   for(i=3;i<len;i++)
   {
       flag1=-flag1;
       flag2=-flag2;
       multiply(c0);
       multiply(c1);
       if(a[i]>='0'&&a[i]<='9')
    {
        p=a[i]-'0';
   }
   if(a[i]>='A')
    {
        p=a[i]-'A'+10;
   }
       if((flag1*b[p][1])>0){plus(c0,b[p][0]);}
       if((flag2*b[p][3])>0){plus(c1,b[p][2]);}
       if((flag1*b[p][1])<0)
       {
            if(strlen(c0)==1&&c0[0]-'0'<b[p][0])
            {flag1=-flag1;
            c0[0]=b[p][0]-c0[0]+2*'0';}
            else{minus(c0[0],b[p][0]);}
       }
       if((flag2*b[p][3])<0)
       {
            if(strlen(c1)==1&&c1[0]-'0'<b[p][2])
            {flag2=-flag2;
            c1[0]=b[p][2]-c1[0]+2*'0';}
            else{minus(c1[0],b[p][2]);}
       }
   }
   if(!strcmp(c0,"0")&&!strcmp(c1,"0")) {printf("0");return 0;}
   if(strcmp(c0,"0"))
   {
       if(flag1<0) printf("-");
       for(i=0;i<strlen(c0);i++){printf("%c"),c0[i];}
       if(flag2>0&&strcmp(c1,"0")) printf("+");

   }
   if(strcmp(c1,"0"))
   {
       if(flag2<0) printf("-");
       if(!strcmp(c1,"1")){printf("i");return 0;}
       for(i=0;i<strlen(c1);i++){printf("%c"),c1[i];}
       printf("i");
   }

}