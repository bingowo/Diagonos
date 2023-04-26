#define N 100
int main()
{  char s1[N+1],s2[N+1];
   while(scanf("%s%s",s1,s2)==2)
   {  int co[N]={0},out[N],n=0,i;
      multiply(s1,s2,co);
      for (i=0;i<N;i++) if (co[i]) out[n++]=co[i];
      for (i=n-1;i>=0;i--) 
      { printf("%d",out[i]); 
        if (i>0) printf(" "); else printf("\n");
      }
   }
  return 0;
}
void multiply(char *s1,char *s2, int* co)
{  int co1[N]={0},co2[N]={0},i,j;
   readpoly(s1,co1);   readpoly(s2,co2);
   for (i=0;i<N/2;i++)
     for (j=0;j<N/2;j++)
        co[i+j]+=co1[i]*co2[j];
}
