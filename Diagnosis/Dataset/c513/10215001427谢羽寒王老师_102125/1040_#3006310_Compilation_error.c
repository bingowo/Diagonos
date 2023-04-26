#include <stdio.h>
#include <string.h>

int main()
{
    const int ABO[4][4][4]=
{1,0,0,1,  1,1,1,0,  1,1,1,1,  1,0,0,1,
1,1,1,0,   1,1,1,0,   1,1,1,0,  1,0,1,0,       //4x4种父母搭配可能生下的孩子血型类型
 1,1,1,1,  1,1,1,0,    0,0,1,1,  0,0,1,1, 
1,0,0,1,   1,0,1,0,    0,0,1,1,  0,0,0,1};

  int father,mother,child;     
  father=read();mother=read();child=read();  
  int ansABO[4]; 
                    //ansABO[i] 表示血型i是否为可能的血型
                    //接下来，确定好要求的所有血型是哪些
  if(father==0){
      int m1,c1;
      m1=mother-1;
      c1=child-1;
      for(int i=0;i<4;i++)
          ansABO[i]=ABO[i][m1][c1];
  }
  if(mother==0){
      int f1,c2;
      f1=father-1;
      c2=child-1;
      for(i=0;i<4;i++)
      ansABO[i]=ABO[f1][i][c2];
  }
  if(child==0){
      int f2,m2;
      f2=father-1;
      m2=mother-1;
       for(i=0;i<4;i++)
      ansABO[i]=ABO[f2][m2][i];
  }
      
  if(father!=0) print(father,0);    else write();   
  printf(" ");  
   if(mother!=0) print(mother,0);     else write();
   printf(" ");  
   if(child!=0) print(child,0);     else write();    
   printf("\n");

}
int read()    //输入
{
    char s[10];
    scanf("%s",s);
    int flag =0;
    if(!strcmp(s,"B")) flag=3;
    else if(!strcmp(s,"A")) flag =1;
    else if(!strcmp(s,"AB")) flag=2;
    else if(!strcmp(s,"?")) flag =4;
    return flag;
    
}
void print (int x, int type)
{
    if(type == 1) printf("{");
    else if (type >1) printf(",");
    if(x=1) printf("A");
    if(x=2) printf("B");
    if(x=3) printf("AB");
    if(x=4) printf("O");
}
void write()
{
    int ABO=0;
    for(int i=0;i<4;i++) ABO+=ansABO[i];
    if(ABO==0) printf("impossible");
    else{
        int cnt = 0;
        for(int i=0;i<4;i++)
        if(ansABO[i]){
            cnt++;
            printf(i+1,cnt);
        }
        printf("}");
        }
}  