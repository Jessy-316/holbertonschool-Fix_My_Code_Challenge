#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i = 0;

    if (head == NULL || *head == NULL)  /* Safeguard against double-null */
        return (-1);

    current = *head;

    /* Traverse to the node at the given index */
    while (i < index && current != NULL)
    {
        current = current->next;
        i++;
    }

    if (current == NULL)  /* Index out of range */
        return (-1);

    /* Case 1: Deleting the head node */
    if (current == *head)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else  /* Case 2: Deleting a middle or tail node */
    {
        current->prev->next = current->next;
        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    free(current);
    return (1);
}
