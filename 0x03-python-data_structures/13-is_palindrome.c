#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/* Define the structure for a singly linked list node */
typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

/* Function to check if a linked list is a palindrome */
int is_palindrome(listint_t **head);

int main(void)
{
    /* Example usage */
    listint_t *head = NULL;

    /* TODO: Create your linked list here */

    if (is_palindrome(&head))
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is not a palindrome.\n");

    return 0;
}

/* Helper function to reverse a linked list */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL;
    listint_t *current = head;
    listint_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

/* Function to check if a linked list is a palindrome */
int is_palindrome(listint_t **head)
{
    if (*head == NULL || (*head)->next == NULL) {
        return 1;  // An empty list or a single element list is a palindrome
    }

    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *prev_slow = *head;
    listint_t *second_half = NULL;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    if (fast != NULL) {  // Odd number of elements, skip the middle one
        slow = slow->next;
    }

    second_half = reverse_list(slow);
    slow = *head;

    while (second_half != NULL) {
        if (slow->n != second_half->n) {
            return 0;  // Not a palindrome
        }
        slow = slow->next;
        second_half = second_half->next;
    }

    return 1;  // Palindrome
}

