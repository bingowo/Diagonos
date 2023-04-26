#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int main()
{
   char ans[1001],anscpy[1001],c;
   memset(ans,0,1001);
   memset(anscpy,0,1001);
   while((c=getchar())!=EOF&&c!='\n')
   {
       if(c>='a'&&c<='z')c=c-'a'+'A';
       if(c>=ans[0]){strcpy(anscpy,ans);ans[0]=c;ans[1]=0;strcat(ans,anscpy);}
       else ans[strlen(ans)]=c;
   }
   printf("%s",ans);
   return(0);
}
