/**
 * Takes C source code as input and removes comments.
 *
 * gcc -std=c99 -Wall -Wextra -Wall -pedantic stripcomments.c -o sc
 */

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { Character, String } literal_t;


static int next(const char *);
static int peek(void);
static void consume_literal(literal_t);
static void skip_multiline(void);
static void skip_singleline(void);

static unsigned int line = 0;
// comment here

int main(void)
{
    int character;

    while ((character = next(NULL)) != EOF)
    {
        switch (character)
        {
            case '\'': // another comment there
                switch (peek())
                {
                    case '\n':
                        next(NULL);
                        break;

                    default: 
                        putchar('\'');
                        consume_literal(Character);
                        break;
                }
                break;

            case '"':
                putchar('"');
                consume_literal(String);
                break;

            case '/':
                switch (peek())
                {
                    case '*':
                        skip_multiline();
                        break;

                    case '/':
                        skip_singleline();
                        break;

                    default:
                        putchar(character);
                }
                break;

            default:
                putchar(character);
                break;
        }
    }
}

int next(const char *error)
{
    errno = 0;

    int character = getchar();

    if (errno)
    {
        perror(error ? error : "\n\tRead error");
        exit(EXIT_FAILURE);
    }

    line += (character == '\n') ? 1 : 0;
    return character;
}


int peek(void)
{
    int nxt = next(NULL);

    if (ungetc(nxt, stdin) == EOF)
    {
        fprintf(stderr, "\n\tError trying to push back %c (line %u).\n\n", 
                nxt, line);

        exit(EXIT_FAILURE);
    }

    return nxt;
}


void skip_multiline(void)
{
    next(NULL);

    bool done = false;

    while (!done)
    {
        switch (next(NULL))
        {
            case EOF:
                fprintf(stderr, "\n\tError (line %u): unterminated multiline comment.\n\n", 
                        line);

                done = true;
                break;
                
            case '*':
                if (peek() == '/')
                {
                    next(NULL);
                    done = true;
                }

            default: break;
        }
    }
}


void skip_singleline(void)
{
    next(NULL);

    int character;

    while ((character = next(NULL)) != '\n')
    {
        if (character == EOF)
        {
            fprintf(stderr, "\n\tError (line %u): unterminated single-line comment.\n\n", 
                    line);
        }
    }

    putchar('\n');
}


void consume_literal(literal_t type)
{
    int character,
        target = (type == Character) ? '\'' : '"';

    while ((character = next(NULL)) != target)
    {
        putchar(character);
    }

    putchar(target);
}
