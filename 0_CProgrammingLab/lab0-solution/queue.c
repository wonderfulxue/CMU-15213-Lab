/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
  queue_t *q = malloc(sizeof(queue_t));
  /* What if malloc returned NULL? */
  if (q)
  {
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
  }

  return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
  /* How about freeing the list elements and the strings? */
  /* Free queue structure */
  if (q)
  {
    list_ele_t *cur = q->head, *next = NULL;
    while (cur)
    {
      next = cur->next;
      free(cur->value); // free string
      free(cur);
      cur = next;
    }
    free(q); // free queue structure
  }
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
  if (!q)
    return false;

  list_ele_t *newh = malloc(sizeof(list_ele_t));

  if (!newh)
    return false;

  /* Don't forget to allocate space for the string and copy it */
  /* What if either call to malloc returns NULL? */
  char *copy_s_ptr = malloc(sizeof(char) * string_len(s));
  if (!copy_s_ptr)
  {
    free(newh); // IMPORTANT: Need to free the allocated newh space
    return false;
  }
  strcpy(copy_s_ptr, s);
  newh->value = copy_s_ptr;

  newh->next = q->head;
  q->head = newh;

  if (!q->tail)
    q->tail = q->head;

  ++q->size;

  return true;
}

/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
  /* You need to write the complete code for this function */
  /* Remember: It should operate in O(1) time */
  if (!q)
    return false;

  list_ele_t *newt = malloc(sizeof(list_ele_t));
  if (!newt)
    return false;

  char *copy_s_ptr = malloc(sizeof(char) * string_len(s));
  if (!copy_s_ptr)
  {
    free(newt); // IMPORTANT: Need to free allocated newt space
    return false;
  }
  strcpy(copy_s_ptr, s);
  newt->value = copy_s_ptr;
  newt->next = NULL;

  if (q->tail)
  {
    q->tail->next = newt;
    q->tail = newt;
  }
  else
  {
    q->head = newt;
    q->tail = newt;
  }

  ++q->size;

  return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
  if (!q || !q->head)
    return false;
  list_ele_t *oldh = q->head;

  q->head = q->head->next;

  if (sp)
  {
    size_t idx;
    for (idx = 0; *(oldh->value + idx) != '\0' && idx < bufsize - 1; ++idx)
    {
      *(sp + idx) = *(oldh->value + idx);
    }
    *(sp + idx) = '\0';
  }
  free(oldh->value);
  free(oldh);

  --q->size; // update queue size
  return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
  /* You need to write the code for this function */
  /* Remember: It should operate in O(1) time */
  if (!q || !q->head)
    return 0;

  return (int)q->size;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
  /* You need to write the code for this function */
  if (!q || !q->head)
    return;

  list_ele_t *cur = q->head, *prev = NULL;
  while (cur)
  {
    list_ele_t *next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }

  q->tail = q->head;
  q->head = prev;
}

/*
  Helper function
  Get the length of the char string
*/

size_t string_len(char *s)
{
  size_t len = 0;
  while (s[len] != '\0')
    ++len;

  return len + 1;
}
