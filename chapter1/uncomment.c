/*
 * =====================================================================================
 *
 *       Filename:  uncomment.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  08/16/2022 06:19:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 65536

#define NOT_IN_COMMENT 0
#define SINGLE_COMMENT 1
#define MULTI_COMMENT 2
int status = NOT_IN_COMMENT; // are we in a comment? what type?
int in_string = 0;           // are we inside a string const?

char *stripcomments(char *stripped, char *code) {
  int ndx;     // index for code
  int ondx;    // index for output
  char prevch; // value of prev char

  for (ndx = ondx = 0; ndx < strlen(code); ndx++) {
    char current = code[ndx];

    if (in_string) {
      if (current == '"')
        in_string = 0;
      stripped[ondx++] = current;
    } else {
      if (status == NOT_IN_COMMENT) {
        if (current == '"') {
          stripped[ondx++] = current;
          in_string = 1;
          continue;
        }

        if (current == '/' && prevch == '/')
          status = SINGLE_COMMENT;
        else if (current == '*' && prevch == '/')
          status = MULTI_COMMENT;
        else if (current != '/' ||
                 (current == '/' && ndx < strlen(code) - 1 &&
                  !(code[ndx + 1] == '/' || code[ndx + 1] == '*')))
          stripped[ondx++] = current;
      } else if (status == SINGLE_COMMENT) {
        if (current == '\n') {
          status = NOT_IN_COMMENT;
          stripped[ondx++] = '\n';
        }
      } else if (status == MULTI_COMMENT) {
        if (current == '/' && prevch == '*')
          status = NOT_IN_COMMENT;
      }
    }
    prevch = current;
  }
  stripped[ondx] = '\0';
  return stripped;
}

int main(void) { 
  char code[MAX_LENGTH];
  char stripped[MAX_LENGTH];

  while (fgets(code, sizeof(code), stdin)) {
    stripcomments(stripped, code);
    if (strlen(stripped) > 0) printf("%s", stripped);
  }
  return 0; 
}
