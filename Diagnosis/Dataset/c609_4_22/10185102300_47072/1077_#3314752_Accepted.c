#include <stdio.h>
#include <string.h>

int main()
{ char inst[4],r1,r2; int r['A'+4]={0};
  while(scanf("%s",inst)!=EOF)
    if (scanf(" %cX",&r1),!strcmp(inst,"IN")) scanf(",%d",&r[r1]);
    else if (!strcmp(inst,"OUT")) printf("%d\n",r[r1]);
    
    else if (scanf(",%cX",&r2),!strcmp(inst,"ADD")) r[r1] += r[r2];
    else if (!strcmp(inst,"SUB")) r[r1] -= r[r2];
    else if (!strcmp(inst,"MUL")) r[r1] *= r[r2];
    else if (!strcmp(inst,"DIV")) r[r1] /= r[r2];
    else                          r[r1]  = r[r2];
  return 0;
}
