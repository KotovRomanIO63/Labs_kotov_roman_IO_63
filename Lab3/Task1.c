#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char command[100];
} Command;

Command Undo[MAX];
Command Redo[MAX];

int topUndo = -1;
int topRedo = -1;

void push(Command stack[], int* top, char command[])
{
    if (*top < MAX - 1)
    {
        (*top)++;
        strcpy(stack[*top].command, command);
    }
}

int pop(Command stack[], int* top, char command[])
{
    if (*top == -1)
    {
        return 0;
    }

    strcpy(command, stack[*top].command);
    (*top)--;

    return 1;
}

int peek(Command stack[], int top, char command[])
{
    if (top == -1)
    {
        return 0;
    }

    strcpy(command, stack[top].command);

    return 1;
}

int is_empty(int* top)
{
    return *top == -1;
}

int is_full(int* top)
{
    return *top == MAX - 1;
}

int main()
{
    char command[100];

    const char* kwords[3] = {"undo", "redo", "stop"};

    const char* description[3] = {"Undo the last action", "Redo the last undone action", "Exit the program"};

    while (1)
    {
        printf("\nEnter a drawing command or a keyword:\n");

        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "stop") == 0)
        {
            break;
        }

        printf("\nList of keywords:\n");

        for (int i = 0; i < 3; i++)
        {
            printf("%s - %s\n", kwords[i], description[i]);
        }

        if (strcmp(command, "undo") == 0)
        {
            if (!is_empty(&topUndo))
            {
                if (!is_full(&topRedo))
                {
                    peek(Undo, topUndo, command);
                    printf("Undo command: %s\n", command);

                    pop(Undo, &topUndo, command);
                    push(Redo, &topRedo, command);
                }
                else
                {
                    printf("Redo is full\n");
                }
            }
            else
            {
                printf("Undo is empty\n");
            }
        }
        else if (strcmp(command, "redo") == 0)
        {
            if (!is_empty(&topRedo))
            {
                if (!is_full(&topUndo))
                {
                    peek(Redo, topRedo, command);
                    printf("Redo command: %s\n", command);

                    pop(Redo, &topRedo, command);
                    push(Undo, &topUndo, command);
                }
                else
                {
                    printf("Undo is full\n");
                }
            }
            else
            {
                printf("Redo is empty\n");
            }
        }
        else if (command[0] != '\0')
        {
            if (!is_full(&topUndo))
            {
                push(Undo, &topUndo, command);

                topRedo = -1;
            }
            else
            {
                printf("Undo is full\n");
            }
        }
        else
        {
            printf("Empty command\n");
        }

        printf("\nActive drawing commands:\n");

        for (int i = 0; i <= topUndo; i++)
        {
            printf("%s\n", Undo[i].command);
        }
    }

    return 0;
}