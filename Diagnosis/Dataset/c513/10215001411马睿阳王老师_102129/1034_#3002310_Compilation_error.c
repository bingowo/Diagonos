#include<stdio.h>
#include<string.h>
typedef struct{
char al;
int fr;
}pl;

void sort(pl b[105],int c)
{
  int compare(const void*a1,const void*a2)
  {
      int w=*(int*)a1;
      int q=*(int*)a2;
      if(w>=q) return -1;
      else return 1;
  }
  qsort(b.fr,c,sizeof(int),compare);
}
int main()
{int i=1,j=1,k=0,t=0,h=0;
 char s;
 int a[26]={0};//各个字母的频率
 pl b[105]={0};
 int T;
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {for(i=1;i<=26;i++)
  a[i]=0;
  for(i=1;i<=26;i++)
  scanf("%d",a[i]);
  int c=0;
  b[0].al="\0";
  for(i=1;i<=105;i++)
  b[i].fr=0;
  j=1;
  while(scanf("%pl",&b[j].al)!=0)
  {j++;}
  c=j-1;//c为b的长度
  for(j=1;j<=c;j++)
  {
      if(b[j].al=='A'||b[j].al=='a')  b[j].fr=a[1];
      if(b[j].al=='B'||b[j].al=='b')  b[j].fr=a[2];
      if(b[j].al=='C'||b[j].al=='c')  b[j].fr=a[3];
      if(b[j].al=='D'||b[j].al=='d')  b[j].fr=a[4];
      if(b[j].al=='E'||b[j].al=='e')  b[j].fr=a[5];
      if(b[j].al=='F'||b[j].al=='f')  b[j].fr=a[6];
      if(b[j].al=='G'||b[j].al=='g')  b[j].fr=a[7];
      if(b[j].al=='H'||b[j].al=='h')  b[j].fr=a[8];
      if(b[j].al=='I'||b[j].al=='i')  b[j].fr=a[9];
      if(b[j].al=='J'||b[j].al=='j')  b[j].fr=a[10];
      if(b[j].al=='K'||b[j].al=='k')  b[j].fr=a[11];
      if(b[j].al=='L'||b[j].al=='l')  b[j].fr=a[12];
      if(b[j].al=='M'||b[j].al=='m')  b[j].fr=a[13];
      if(b[j].al=='N'||b[j].al=='n')  b[j].fr=a[14];
      if(b[j].al=='O'||b[j].al=='o')  b[j].fr=a[15];
      if(b[j].al=='P'||b[j].al=='p')  b[j].fr=a[16];
      if(b[j].al=='Q'||b[j].al=='q')  b[j].fr=a[17];
      if(b[j].al=='R'||b[j].al=='r')  b[j].fr=a[18];
      if(b[j].al=='S'||b[j].al=='s')  b[j].fr=a[19];
      if(b[j].al=='T'||b[j].al=='t')  b[j].fr=a[20];
      if(b[j].al=='U'||b[j].al=='u')  b[j].fr=a[21];
      if(b[j].al=='V'||b[j].al=='v')  b[j].fr=a[22];
      if(b[j].al=='W'||b[j].al=='w')  b[j].fr=a[23];
      if(b[j].al=='X'||b[j].al=='x')  b[j].fr=a[24];
      if(b[j].al=='Y'||b[j].al=='y')  b[j].fr=a[25];
      if(b[j].al=='Z'||b[j].al=='z')  b[j].fr=a[26];

   }
   sort(pl b[105],int c);
   for(j=1;j<=c;j++)
   {
      if(b[j].fr==b[i+1].fr)
      {
          if(b[j].al-'0'==b[j+1]+32-'0')//j是小写
          h=0;
          else if(b[j+1].al=b[j].al+32-'0')//j+1是小写
          {s=b[j+1].al;
           b[j+1].al=b[j].al;
           b[j].al=s;
          }
          else
          {
              if(b[j].al-'0'>b[j+1].al-'0')
              {s=b[j+1].al;
               b[j+1].al=b[j].al;
               b[j].al=s;
              }
              else h=0;
          }
      }

   }
  printf("case #%d\n",k);
  for(j=1;j<=c;j++)
  printf("%pl",b[j].al);
  printf("\n");
 }
 return 0;
}
