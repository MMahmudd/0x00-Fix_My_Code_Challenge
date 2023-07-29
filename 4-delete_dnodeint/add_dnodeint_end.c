#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * struct dlistint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous node
 * @next: Pointer to the next node
 */
struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
};

typedef struct dlistint_s dlistint_t;

/**
 * add_dnodeint_end - Add a node at the end of a list
 *
 * @head: The address of the pointer to the first element of the list
 * @n: The number to store in the new element
 *
 * Return: A pointer to the new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    // Allocate memory for the new node
    dlistint_t *new;
    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
    {
        return (NULL);
    }

    // Fill in the new node's data
    new->n = n;
    new->next = NULL;

    // If the list is empty, make the new node the first node (head)
    if (*head == NULL)
    {
        *head = new;
        new->prev = NULL;
        return (new);
    }

    // Traverse the list to find the last node
    dlistint_t *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    // Attach the new node to the last node's next and set prev pointers
    last->next = new;
    new->prev = last;

    return (new);
}

int main()
{
    // Test the add_dnodeint_end function

    dlistint_t *head = NULL; // Initialize an empty list

    // Add nodes with values 10, 20, 30, and 40 to the end of the list
    add_dnodeint_end(&head, 10);
    add_dnodeint_end(&head, 20);
    add_dnodeint_end(&head, 30);
    add_dnodeint_end(&head, 40);

    // Print the linked list to verify the elements
    dlistint_t *current = head;
    while (current != NULL)
    {
        printf("%d ", current->n);
        current = current->next;
    }
    printf("\n");

    return 0;
}
