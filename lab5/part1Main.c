#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
extern char *pop();
extern void push(char *);
extern int isEmpty();

int main(int argc, char *argv[])
{
    int ch;
    char tag_buffer[101];
    // Read characters from the input
    while ((ch = getchar()) != EOF)
    {
        // If an opening angle bracket is found
        if (ch == '<')
        {
            int is_end_tag = 0;
            int index = 0;
            // Read the characters inside the angle brackets
            while ((ch = getchar()) != '>' && ch != EOF)
            {
                if (ch == '/')
                {
                    // If a forward slash is encountered, it's an end tag
                    is_end_tag = 1;
                }
                else if (isalpha(ch))
                {
                    // Store the tag name in tag_buffer
                    tag_buffer[index++] = ch;
                }
            }
            tag_buffer[index] = '\0';

            // If it's an end tag
            if (is_end_tag)
            {
                char *popped_tag = pop();
                // Check if the popped tag matches the current end tag
                if (popped_tag == NULL || strcmp(tag_buffer, popped_tag) != 0)
                {
                    printf("No\n");
                    exit(1);
                }
            }
            else
            {
                // If it's an opening tag, push it onto the stack
                push(tag_buffer);
            }
        }
    }

    // If the stack is empty, all tags are properly nested
    if (isEmpty())
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    exit(0);
}