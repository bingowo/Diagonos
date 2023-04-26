#include<stdio.h>
#include<string.h>
int main()
{int i=0,T;
 char s[105]={0},l=0;
 scanf("%d",&T);
 for(i=0;i<T;i++)
    {int j=0,k=0,c=0,d=0,d1=0,d2=0,d3=0,d4=0,e1=0,e2=0,e3=0,e4=0;
     scanf("%s",s);
     c=strlen(s);
     if(c%4==0)
     {d=c/4;
     for(j=0;j<c;j++)
        {if(s[j]=='R') d1++;
         else if(s[j]=='B') d2++;
         else if(s[j]=='Y') d3++;
         else if(s[j]=='G') d4++;
         else d=c/4;
         }
     e1=d-d1;
     e2=d-d2;
     e3=d-d3;
     e4=d-d4;
     printf("case #%d:\n",i);
     printf("%d",e1);
     printf("% d",e2);
     printf("% d",e3);
     printf("% d",e4);
     printf("\n");
     }
     else if(c%4==1)
     {d=c/4;
     for(j=0;j<c-1;j++)
        {if(s[j]=='R') d1++;
         else if(s[j]=='B') d2++;
         else if(s[j]=='Y') d3++;
         else if(s[j]=='G') d4++;
         else d=c/4;
         }
     e1=d-d1;
     e2=d-d2;
     e3=d-d3;
     e4=d-d4;
     while(s[k]=='!')
     {k=k+4;}
     if(s[k]=='R')
     {l='R';
      if(s[c-1]=='!')  e1++;
      else d=c/4;
     }
     else if(s[k]=='B')
     {l='B';
      if(s[c-1]=='!') e2++;
      else d=c/4;
     }
     else if(s[k]=='Y')
     {l='Y';
      if(s[c-1]=='!')  e3++;
      else d=c/4;
     }
     else
     {l='G';
      if(s[c-1]=='!')  e4++;
      else d=c/4;
     }


     printf("case #%d:\n",i);
     printf("%d",e1);
     printf("% d",e2);
     printf("% d",e3);
     printf("% d",e4);
     printf("\n");
     }
     else if(c%4==2)
     {d=c/4-1;
     for(j=0;j<c-2;j++)
        {if(s[j]=='R') d1++;
         else if(s[j]=='B') d2++;
         else if(s[j]=='Y') d3++;
         else if(s[j]=='G') d4++;
         else d=c/4;
         }
     e1=d-d1;
     e2=d-d2;
     e3=d-d3;
     e4=d-d4;
      while(s[k]=='!')
     {k=k+4;}
     if(s[k]=='R')
     {l='R';
      if(s[c-2]=='!')  e1++;
      else d=c/4;
     }
     else if(s[k]=='B')
     {l='B';
      if(s[c-2]=='!') e2++;
      else d=c/4;
     }
     else if(s[k]=='Y')
     {l='Y';
      if(s[c-2]=='!')  e3++;
      else d=c/4;
     }
     else
     {l='G';
      if(s[c-2]=='!')  e4++;
      else d=c/4;
     }
     k=0;
     while(s[k+1]=='!')
     {k=k+4;}
     if(s[k+1]=='R')
     {l='R';
      if(s[c-1]=='!')  e1++;
      else d=c/4-1;
     }
     else if(s[k+1]=='B')
     {l='B';
      if(s[c-1]=='!') e2++;
      else d=c/4-1;
     }
     else if(s[k+1]=='Y')
     {l='Y';
      if(s[c-1]=='!')  e3++;
      else d=c/4-1;
     }
     else
     {l='G';
      if(s[c-1]=='!')  e4++;
      else d=c/4-1;
     }
     printf("case #%d:\n",i);
     printf("%d",e1);
     printf("% d",e2);
     printf("% d",e3);
     printf("% d",e4);
     printf("\n");
     }
     else
     {d=c/4;
     for(j=0;j<c-3;j++)
        {if(s[j]=='R') d1++;
         else if(s[j]=='B') d2++;
         else if(s[j]=='Y') d3++;
         else if(s[j]=='G') d4++;
         else d=c/4;
         }
     e1=d-d1;
     e2=d-d2;
     e3=d-d3;
     e4=d-d4;
     while(s[k]=='!')
     {k=k+4;}
     if(s[k]=='R')
     {l='R';
      if(s[c-3]=='!')  e1++;
      else d=c/4;
     }
     else if(s[k]=='B')
     {l='B';
      if(s[c-3]=='!') e2++;
      else d=c/4;
     }
     else if(s[k]=='Y')
     {l='Y';
      if(s[c-3]=='!')  e3++;
      else d=c/4;
     }
     else
     {l='G';
      if(s[c-3]=='!')  e4++;
      else d=c/4;
     }
     k=0;
     while(s[k+1]=='!')
     {k=k+4;}
     if(s[k+1]=='R')
     {l='R';
      if(s[c-2]=='!')  e1++;
      else d=c/4-1;
     }
     else if(s[k+1]=='B')
     {l='B';
      if(s[c-2]=='!') e2++;
      else d=c/4-1;
     }
     else if(s[k+1]=='Y')
     {l='Y';
      if(s[c-2]=='!')  e3++;
      else d=c/4-1;
     }
     else
     {l='G';
      if(s[c-2]=='!')  e4++;
      else d=c/4-1;
     }
      while(s[k+2]=='!')
     {k=k+4;}
     if(s[k+2]=='R')
     {l='R';
      if(s[c-1]=='!')  e1++;
      else d=c/4-1;
     }
     else if(s[k+2]=='B')
     {l='B';
      if(s[c-1]=='!') e2++;
      else d=c/4-1;
     }
     else if(s[k+2]=='Y')
     {l='Y';
      if(s[c-1]=='!')  e3++;
      else d=c/4-1;
     }
     else
     {l='G';
      if(s[c-1]=='!')  e4++;
      else d=c/4-1;
     }
     printf("case #%d:\n",i);
     printf("%d",e1);
     printf("% d",e2);
     printf("% d",e3);
     printf("% d",e4);
     printf("\n");
     }
    s[0]='0\n';
    }
return 0;
}
