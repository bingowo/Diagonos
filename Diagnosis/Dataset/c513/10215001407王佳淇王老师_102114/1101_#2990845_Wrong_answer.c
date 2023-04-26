#include<stdio.h>
#include<string.h>
const int Rh[2][2][2]=
{ 1,1,  1,1,
  1,1,  0,1};
int ans_Rh[2];
const int ABO[4][4][4]=
{1,0,0,1,  1,1,1,0,  1,1,1,1,  1,0,0,1,
1,1,1,0,   1,1,1,0,   1,1,1,0,  1,0,1,0,
 1,1,1,1,  1,1,1,0,    0,0,1,1,  0,0,1,1, 
1,0,0,1,   1,0,1,0,    0,0,1,1,  0,0,0,1};
int ans_ABO[4];
int read()
{
  char s[10];
  scanf("%s",s);
  int flag=0;
  if(!strcmp(s,"A+")) flag=1;
  if(!strcmp(s,"A-")) flag=-1;
  else if(!strcmp(s,"B+")) flag=3;
  else if(!strcmp(s,"B-")) flag=-3;
  else if(!strcmp(s,"AB+")) flag=2;
  else if(!strcmp(s,"AB-")) flag=-2;
  else if(!strcmp(s,"O+")) flag=4;
  else if(!strcmp(s,"O-")) flag=4;
  else if(!strcmp(s,"?")) flag=0;
  return flag;
}
void print(int x, int type)
{
   if(type==1) printf("{");
   else if(type>1) printf(",");
   if(x==1||x==-1) printf("A");
   if(x==2||x==-2) printf("AB");
   if(x==3||x==-3) printf("B");
   if(x==4||x==-4) printf("O");
   if(x>0) printf("+");
   else printf("-");
}


void write()
{
    int ABO=0,Rh=0;
    for(int i=0;i<4;i++)        //统计可能的ABO血型数
        ABO+=ans_ABO[i];   
    for(int i=0;i<2;i++)        //统计可能的Rh因子数，可能的血型数为ABO*Rh
        Rh+=ans_Rh[i];
    if(ABO*Rh==0) printf("impossible");     //没有一个可能的血型
    if(ABO*Rh==1)      //只有一种可能的血型
    {
        for(int i=0;i<4;i++)
            if(ans_ABO[i])
               for(int j=0;j<2;j++)
                  if(ans_Rh[j])
                   {
                    if(j==0) print(i+1,0);
                    else print(-i-1,0);
                   }
    }
if(ABO*Rh>1)     //有多种可能的血型
    {
        int cnt=0;
        for(int i=0; i<4; i++)
            if(ans_ABO[i])
                for(int j=0; j<2; j++)
                    if(ans_Rh[j])
                    {
                        cnt++;
                        if(j==0) print(i+1,cnt);
                        else print(-i-1,cnt);
                   }
        printf("}");
    }
}
int main(){
	int T;
	scanf("%d",&T);
	for(int z=0;z<T;z++){
		//printf("case #\n");
int father,mother,child;     
  father=read();
  mother=read();
  child=read(); 
  //      
  if(father==0)
     {
         int m1,c1,m2,c2;
         if(mother>0) {m1=mother-1;m2=0;}
         else {m1=-1-mother;m2=1;}
         if(child>0) {c1=child-1;c2=0;}
         else {c1=-1-child;c2=1;}
         for(int i=0;i<4;i++)
            ans_ABO[i]=ABO[i][m1][c1];
          for(int i=0;i<2;i++)
             ans_Rh[i]=Rh[i][m2][c2];
      }
  //
  if(mother==0)
{
  int f11,c11,f22,c22;
  if(father>0) {f11=father-1;f22=0;}
  else {f11=-1-father;f22=1;}
  if(child>0) {c11=child-1;c22=0;}
  else {c11=-1-child;c22=1;}
  for(int j=0;j<4;j++)
  ans_ABO[j]=ABO[f11][j][c11];
  for(int i=0;i<2;i++)
             ans_Rh[i]=Rh[f22][i][c22];
  
  }
  if(child==0)
{
  int f3,m3,f4,m4;
  if(father>0) {f3=father-1;f4=0;}
  else {f3=-1-father;f4=1;}
  if(mother>0) {m3=mother-1;m4=0;}
  else {m3=-1-mother;m4=1;}
  for(int j=0;j<4;j++)
  ans_ABO[j]=ABO[f3][m3][j];
  for(int i=0;i<2;i++)
             ans_Rh[i]=Rh[f4][m4][i];
  }
  //
  if(father!=0) print(father,0);    
  else write();   
  printf(" ");  
   if(mother!=0) print(mother,0); 
   else write();
   printf(" ");  
   if(child!=0) print(child,0);   
   else write();    
   printf("\n");
}
return 0;
}