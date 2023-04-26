#include <stdio.h>
#include <string.h>


void insert(char *s, char c, int index)
{
 int lens = strlen(s);
 memmove(s + index + 1, s + index, lens - index + 1);
 *(s + index) = c;
}

int del(char *s)
{
 int ret = 0;
 int isSame = 0, isComplete = 1, lens;
 char *pa = s;
 char *pb = pa + 1;
 char *pend = NULL, *pstart = NULL;
 while(1){
  lens = strlen(s);
  pend = s + lens;
  pstart = s;
  if(*pb == *pa ){
   isSame = 1;
  }else{
   isSame = 0;
  }
  if(isSame){
   pb ++;
  }else{
   if(pb - pa > 1){
    ret += (pb - pa);
    memmove(pa, pb, pend - pb + 1);
    isComplete = 0;
    if(*pstart == '\0'){
     break;
    }else if(*pa == '\0'){
     pa -= 1;
     pb = pa + 1;
     continue;
    }else{
     pb = pa + 1;
     continue;
    }
   }
   if(*pb == '\0'){
    if(! isComplete){
     pa = s;
     pb = pa + 1;
     isComplete = 1;
    }else{
     break;
    }
   }else{
    pb += 1;
    pa += 1;
   }
  }
 }
 return ret;
}