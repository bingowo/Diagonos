#include <stdio.h>
#include <string.h>

#define REGN 4
#define LEN 40

int main()
{ char instruction[4];int reg[REGN]={0};
   while(scanf("%s",instruction)!=EOF)
   { char reg1,reg2;
      scanf(" %cX",&reg1);
     if (!strcmp(instruction,"IN")) scanf(",%d",&reg[reg1-'A']);
     else if (!strcmp(instruction,"OUT")) printf("%d\n", reg[reg1-'A']);
     else
     {  scanf(",%cX",&reg2);
        if (!strcmp(instruction,"ADD"))        reg[reg1-'A'] += reg[reg2-'A'];
        else if (!strcmp(instruction,"SUB"))  reg[reg1-'A'] -= reg[reg2-'A'];
        else if (!strcmp(instruction,"MUL")) reg[reg1-'A'] *= reg[reg2-'A'];
        else if (!strcmp(instruction,"DIV"))  reg[reg1-'A'] /= reg[reg2-'A'];
        else                                                   reg[reg1-'A']  = reg[reg2-'A'];
     }
   }
  return 0;
}
