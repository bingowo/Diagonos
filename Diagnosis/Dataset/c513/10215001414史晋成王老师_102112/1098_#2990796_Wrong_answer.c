#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ int T,i,j,n,m,l,a[1000]={0},k,c1,c2,c3,c4;
  char s[1000];
  scanf("%d",&T);
  for(i=0;i<T;i++)
  {  c1=0;c2=0;c3=0;c4=0;
      scanf("%s",s);
    printf("case #%d:\n",i);
    l=strlen(s);
  
    for(j=0;j<l;j++)
    { if(s[j]=='R') {a['R']=j; break;}
    }
    while(a['R']>3) a['R']-=4;
    for(j=0;j<l;j++)
    { if(s[j]=='Y') {a['Y']=j; break;}
    }
    while(a['Y']>3) a['Y']-=4;
    for(j=0;j<l;j++)
    { if(s[j]=='G') {a['G']=j; break;}
    }
    while(a['G']>3) a['G']-=4;
    for(j=0;j<l;j++)
    { if(s[j]=='B') {a['B']=j; break;}
    }
    while(a['B']>3) a['B']-=4;
    
    for(k=a['R'];k<l;k+=4)
    if(s[k]=='!') c1++;
    for(k=a['B'];k<l;k+=4)
    if(s[k]=='!') c2++;
    for(k=a['Y'];k<l;k+=4)
    if(s[k]=='!') c3++;
    for(k=a['G'];k<l;k+=4)
    if(s[k]=='!') c4++;
           if(l==4)
    {  c1=1;c2=1;c3=1;c4=1;
      for(i=0;i<l;i++)
      {     if(s[i]=='R') c1--;
            if(s[i]=='Y') c3--;
      if(s[i]=='B') c2--;
       if(s[i]=='G') c4--;
      }
        
    }
    printf("%d %d %d %d",c1,c2,c3,c4);
  }
    
}