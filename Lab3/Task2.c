#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node
{
    char command[100];
    struct Node* next;
} Node;

Node* Undo = NULL;
Node* Redo = NULL;

int push(Node** top, const char command[])
{
    Node* newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation error\n");
        return 0;
    }

    strcpy(newNode->command, command);
    newNode->next = *top;
    *top = newNode;

    return 1;
}

int pop(Node** top, char command[])
{
    if (*top == NULL)
        return 0;

    Node* temp = *top;

    strcpy(command, temp->command);

    *top = temp->next;

    free(temp);

    return 1;
}

int peek(Node* top, char command[])
{
    if (top == NULL)
        return 0;

    strcpy(command, top->command);

    return 1;
}

int is_empty(Node* top)
{
    return top == NULL;
}

int is_full(void)
{
    Node* temp = malloc(sizeof(Node));

    if (temp == NULL)
        return 1;

    free(temp);

    return 0;
}

void clear_stack(Node** top)
{
    char command[100];

    while (pop(top, command))
    {
    }
}

void print_stack(Node* top)
{
    if (top == NULL)
        return;

    print_stack(top->next);

    printf("%s\n", top->command);
}

int main(void)
{
    char command[100];

    const char* keywords[3] = {"undo", "redo", "stop"};

    const char* descriptions[3] = {"Undo the last action", "Redo the last undone action", "Exit the program"};

    while (1)
    {
        printf("\nEnter a drawing command or a keyword:\n");

        if (fgets(command, sizeof(command), stdin) == NULL)
            break;

        command[strcspn(command, "\n")] = '\0';

        if (command[0] == '\0')
        {
            printf("Empty command\n");
            continue;
        }

        printf("\nThe list of key words:\n");

        for (int i = 0; i < 3; i++)
        {
            printf("%s - %s\n",
                keywords[i], descriptions[i]);
        }

        if (strcmp(command, "stop") == 0)
            break;

        if (strcmp(command, "undo") == 0)
        {
            if (!is_empty(Undo))
            {
                if (peek(Undo, command))
                {
                    printf("Undo command: %s\n", command);

                    if (pop(&Undo, command))
                    {
                        if (!push(&Redo, command))
                            push(&Undo, command);
                    }
                }
            }
            else
            {
                printf("Undo is empty\n");
            }
        }
        else if (strcmp(command, "redo") == 0)
        {
            if (!is_empty(Redo))
            {
                if (peek(Redo, command))
                {
                    printf("Redo command: %s\n", command);

                    if (pop(&Redo, command))
                    {
                        if (!push(&Undo, command))
                            push(&Redo, command);
                    }
                }
            }
            else
            {
                printf("Redo is empty\n");
            }
        }
        else
        {
            if (!is_full())
            {
                if (push(&Undo, command))
                    clear_stack(&Redo);
            }
            else
            {
                printf("Not enough memory\n");
            }
        }

        printf("\nActive commands:\n");
        print_stack(Undo);
    }

    clear_stack(&Undo);
    clear_stack(&Redo);

    return 0;
}