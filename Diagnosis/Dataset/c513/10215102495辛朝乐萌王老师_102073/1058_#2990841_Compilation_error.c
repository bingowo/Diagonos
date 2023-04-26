#include <stdio.h>
#define N 100000

int main(void)
{
 char c, s[N];
 int isLineComment = 0, isParaComment = 0, isQuote = 0;
 int ps = 0;
 //对于非注释的字符，把它们放到字符串中，因此是一个一个读取的 
 while((c = getchar()) != EOF){
  /*当我们读到“/”时，就需要分不同的情况:
   1.如果这个时候不是在引用（也就是不在字符串中）->不启动判断 
   2.这个是第一次读到“/”->isLineComment = 1，isParaComment = 1
   3.这个是第二次读到“/”->isLineComment = 2， isParaComment = 0
   4.这个是作为段注释的结尾 ->isParaComment = 0 
   5.这就是个符号->放入字符串s 
  */ 
  if(c == '/' && !isQuote && isParaComment != 2){
   if(isLineComment != 2 && isParaComment != 3){
    isLineComment ++;
    isParaComment ++;
    //说明已经读到过一个反斜杠，这是另一个
    if(isLineComment == 2){   
     isParaComment = 0;
     //请往后看，再回来就可以明白为什么要-- 
     ps --;
    }else{
    //第一次读到“/”时，先放入字符串中，请往后看，就明白为何 
     s[ps ++] = '/'; 
    }
   //这里结束段落引用，后面的语句保证这个情况是唯一的 
   }else if(isParaComment == 3){
    isParaComment = 0;
   }
  /*当我们读到“*” 时，就需要分以下情况：
   1.如果这个时候不是在引用（也就是不在字符串中）->不启动判断 
   2.这个是在“/”后读到的“*”->isLineComment = 0，isParaComment = 2
   3.这个是在结束的时候读到的“*”->对不起，这个没办法提前知道，但是我们让它保持在 
   isParaComment = 3的状态，这样子当读到“/”时，上面的那个if就可以完成这个夙愿。
   4.这个是段注释中读到的->依旧保持 isParaComment = 3。再读到“\n”时会把这个重置为2，
   以免出现：
     /* *****************
     / 
   的情况错误地删除了注释。
   5.这就是个符号->放入字符串s 
  */ 
  }else if(c == '*' && !isQuote){
   if(isParaComment == 1){
    isParaComment ++;
    isLineComment = 0;
    ps --;
   }else if(isParaComment == 2){
    isParaComment ++;
   }else if(isParaComment == 3){
    isParaComment = 3;
   }else if(isLineComment != 2){
    s[ps ++] = c;
   }
  }else if(c == '\n'){
   //让行注释结束 
   if(isLineComment == 2){
    isLineComment = 0;
    s[ps ++] = '\n';
   //不误删段注释 
   }else if(isParaComment >= 2){
    if(isParaComment == 3){
     isParaComment = 2;
    }
   }else{
    s[ps ++] = '\n';
   }
  //这里的引用有单引号和双引号，都需要判断，我让双引号引起的引用值为1，单引号为2 
  }else if(c == '"' && !isLineComment && !isParaComment){
   if(isQuote == 0){
    isQuote = 1;
   /*这里要考虑字符或字符串中的转义字符，有两种情况：
    1."\\"
    2."\"" 
    第一种情况转义得到了\，因此读入的这个引号应该被视为结束
    第二种情况转义得到了"，因此读入的引号不是结束标志
    下面的单引号也是同样的道理 
   */
   }else if(isQuote == 1 && (s[ps - 1] != '\\' || s[ps - 2] == '\\') ){
    isQuote = 0;
   }
   s[ps ++] = '"';
  }else if(c == '\'' && !isLineComment && !isParaComment){
   if(isQuote == 0){
    isQuote = 2;
   }else if(isQuote == 2 && (s[ps - 1] != '\\' || s[ps - 2] == '\\') ){
    isQuote = 0;
   }
   s[ps ++] = '\'';
  }
  //正常地把字符放到字符串中 
  else if(isLineComment != 2 && isParaComment < 2){
   s[ps ++] = c;
   //因为如果读入的是除号的“/”而不
   这也是为什么读到“/”后就先把它放入字符串中。 
   if(isLineComment == 1){
    isLineComment = 0, isParaComment = 0;
   }
  }
 }
 s[ps] = '\0';
 printf("%s", s);
 
 return 0;
}
   
  