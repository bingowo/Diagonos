#include <stdio.h>
#include <string.h>
#define MAXSTRING 160

unsigned all = 0; /* 组合个数 */

void get_strings(void);
void print_string(char *s, int count);
void swap(char *tp, int c);
void swap2(char *pt, int d);

int main(void)
{
   get_strings();
   return 0;
}

void get_strings(void)
{
   int i;
   char array[MAXSTRING];

   for(i = 0; i < MAXSTRING - 1; i++)
      if((array[i] = getchar()) == '\n' || array[i] == ' ')
         break;
   array[i] = '\0';
   i = strlen(array);
   print_string(array, i);
}

void print_string(char *s, int count)
{
   int i, j;
   char temp[count+1];

   for(i = 0; s[i] != '\0'; ){
      strcpy(temp, s);
      printf("\n%10s\n", temp);
      all++;
      for(j = 1; ; j++){
         if(temp[j+1] == '\0')
            j = 1;
         swap2(temp, j);
         if(strcmp(temp, s) == 0)
            break;
         else{
            printf("%10s\n", temp);
            all++;
         }
      }
      i++;
      swap(s, i);
   }
   printf("The number of combinations of character: %u\n", all-1);
}

void swap(char *tp, int c)
{
   char temp;

   temp = tp[c];
   tp[c] = tp[0];
   tp[0] = temp;
}

void swap2(char *pt, int b)
{
   char temp;

   if(pt[b+1] == '\0')
      return;
   temp = pt[b];
   pt[b] = pt[b+1];
   pt[b+1] = temp;
}