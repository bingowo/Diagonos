#include <stdio.h>
int main(int argc, char* argv[]) {
  enum {
    literal,
    single,
    multiple,
    string
  } mode = literal;
  char last = 0, current;

  while ((current = getchar()) != EOF) {
    switch (mode) {
    case single: {
      if (last != '\\' && (current == '\n' || current == '\r')) {
        putchar(current);
        current = 0;
        mode = literal;
      }
    } break;
    case multiple: {
      if (last == '*' && current == '/') {
        current = 0;
        mode = literal;
      }
    } break;
    case string: {
      if (last == '\\') {
        putchar(last);
        putchar(current);
      } else if (current != '\\') {
        putchar(current);
        if (current == '"') {
          mode = literal;
        }
      }
    } break;
    default: {
      if (last == '/') {
        if (current == '/') {
          mode = single;
        } else if (current == '*') {
          mode = multiple;
        } else {
          putchar(last);
          putchar(current);
        }
      } else if (current != '/') {
        putchar(current);
        if (current == '"') {
          mode = string;
        }
      }
    } break;
    }
    last = current;
  }

  return 0;
}