#include <stdio.h>
#include <string.h>

int main()
{
    char temp[4], fam[4];
    for(int i=0; i<3; i++)
    {
    scanf("%s", temp);
    if(strlen(temp) == 2) fam[i] = 'C';//代表AB
    else if(temp[0] == 'O') fam[i] = 'F';//代表O
    else fam[i] = temp[0];
    }
    if(fam[2] == '?' && fam[0] != fam[1])
    {
        int and = fam[0] + fam[1] -'A'-'A';
        switch (and)
        {
            case 1: printf("%c %c {A,B,AB,O}\n",fam[0], fam[1]); break;
            case 2: printf("%c %c {A,B,AB}\n",fam[0],fam[1]);break;
            case 5: printf("%c %c {A,O}\n",fam[0],fam[1]);break;
            case 3: printf("%c %c {A,B,AB}\n",fam[0],fam[1]);break;
            case 6: printf("%c %c {B,O}\n",fam[0],fam[1]);break;
            case 7: printf("%c %c {A,B}\n",fam[0],fam[1]);break;
        }
    }
      if(fam[2] == '?' && fam[0] == fam[1])
    {
        int and = fam[0] + fam[1] -'A'-'A';
        switch (and)
        {
            case 0: printf("%c %c {A,O}\n",fam[0], fam[1]); break;
            case 2: printf("%c %c {B,O}\n",fam[0],fam[1]);break;
            case 4: printf("%c %c {A,B,AB}\n",fam[0],fam[1]);break;
            case 10: printf("%c %c {O}\n",fam[0],fam[1]);break;
        }
    }
    if(fam[1] == '?')
    {
        if(fam[2] == 'A')
        {
            switch( fam[0])
            {
                case 'A':printf("A {A,B,AB,O} A");break;
                case 'B':printf("B {A,AB} A");break;
                case 'C':printf("AB {A,B,AB,O} A");break;
                case 'F':printf("O {A,AB} A");break;
            }
        }
        if(fam[2] == 'B')
        {
            switch( fam[0])
            {
                case 'A':printf("A {B,AB} B");break;
                case 'B':printf("B {A,B,AB,O} B");break;
                case 'C':printf("AB {A,B,AB,O} B");break;
                case 'F':printf("O {B,AB} B");break;
            }
        }
         if(fam[2] == 'C')
        {
            switch( fam[0])
            {
                case 'A':printf("A {B,AB} AB");break;
                case 'B':printf("B {A,AB} AB");break;
                case 'C':printf("AB {A,B,AB} AB");break;
                case 'F':printf("O impossible AB");break;
            }
        }
        
         if(fam[2] == 'F')
        {
            switch( fam[0])
            {
                case 'A':printf("A {A,B,O} O");break;
                case 'B':printf("B {A,B,O} O");break;
                case 'C':printf("AB impossible O");break;
                case 'F':printf("O {O} O");break;
            }
        }
    }


    if(fam[0] == '?')
    {
        if(fam[2] == 'A')
        {
            switch( fam[1])
            {
                case 'A':printf("{A,B,AB,O} A A");break;
                case 'B':printf("{A,AB} B A");break;
                case 'C':printf("{A,B,AB,O} AB A");break;
                case 'F':printf("{A,AB} O A");break;
            }
        }
        if(fam[2] == 'B')
        {
            switch( fam[1])
            {
                case 'A':printf("{B,AB} A B");break;
                case 'B':printf("{A,B,AB,O} B B");break;
                case 'C':printf("{A,B,AB,O} AB B");break;
                case 'F':printf("{B,AB} O B");break;
            }
        }
         if(fam[2] == 'C')
        {
            switch( fam[1])
            {
                case 'A':printf("{B,AB} A AB");break;
                case 'B':printf("{A,AB} B AB");break;
                case 'C':printf("{A,B,AB} AB AB");break;
                case 'F':printf("impossible O AB");break;
            }
        }
        
         if(fam[2] == 'F')
        {
            switch( fam[1])
            {
                case 'A':printf("{A,B,O} A O");break;
                case 'B':printf("{A,B,O} B O");break;
                case 'C':printf("impossible AB O");break;
                case 'F':printf("{O} O O");break;
            }
        }
    }
    return 0;
}