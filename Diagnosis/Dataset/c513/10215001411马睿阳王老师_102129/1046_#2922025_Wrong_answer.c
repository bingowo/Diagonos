#include<stdio.h>
#include<string.h>

int cmp(char*a)
{if(!strcmp(a,"the")) return 0;
 else if(!strcmp(a,"The")) return 0;
 else if(!strcmp(a,"tHe")) return 0;
 else if(!strcmp(a,"thE")) return 0;
 else if(!strcmp(a,"THe")) return 0;
 else if(!strcmp(a,"ThE")) return 0;
 else if(!strcmp(a,"tHE")) return 0;
 else if(!strcmp(a,"THE")) return 0;
 else if(!strcmp(a,"A")) return 0;
 else if(!strcmp(a,"a")) return 0;
 else if(!strcmp(a,"an")) return 0;
 else if(!strcmp(a,"An")) return 0;
 else if(!strcmp(a,"aN")) return 0;
 else if(!strcmp(a,"AN")) return 0;
 else if(!strcmp(a,"of")) return 0;
 else if(!strcmp(a,"Of")) return 0;
 else if(!strcmp(a,"oF")) return 0;
 else if(!strcmp(a,"OF")) return 0;
 else if(!strcmp(a,"for")) return 0;
 else if(!strcmp(a,"For")) return 0;
 else if(!strcmp(a,"fOr")) return 0;
 else if(!strcmp(a,"foR")) return 0;
 else if(!strcmp(a,"FOr")) return 0;
 else if(!strcmp(a,"FoR")) return 0;
 else if(!strcmp(a,"fOR")) return 0;
 else if(!strcmp(a,"FOR")) return 0;
 else if(!strcmp(a,"and")) return 0;
 else if(!strcmp(a,"And")) return 0;
 else if(!strcmp(a,"aNd")) return 0;
 else if(!strcmp(a,"anD")) return 0;
 else if(!strcmp(a,"ANd")) return 0;
 else if(!strcmp(a,"AnD")) return 0;
 else if(!strcmp(a,"aND")) return 0;
 else if(!strcmp(a,"AND")) return 0;
 else return 1;
}

int main()
{int i,n;
 char a[101];
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {printf("%d",n);
  int sum=0;
  do
  {scanf("%s",a);
   sum+=cmp(a);
  }
  while(getchar()!='\n');
  printf("%d",sum);
 }
 return 0;
}




