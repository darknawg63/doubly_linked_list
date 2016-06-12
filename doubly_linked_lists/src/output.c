#include "node.h"

int 
node_length(Node* head)
{
  int len = 0;

  while (head != NULL)
    {
      head = head->next;
      len++;
    }
  return len;
}

Node* 
node_top(Node* head)
{
  Node* curr = head;

  while (curr != NULL)
    {
      if (curr->next == NULL)
        return curr;

      curr = curr->next;
    }
  return curr;
}

void 
node_print(Node* head, int j, int k)
{
  Node* curr = head;

  if (curr == NULL)
    {
      printf("empty list...\n");
      return;
    }

  if (k > node_length(curr))
    {
      printf("length is %d but second argument is %d\n", 
             node_length(curr), k);
      return;
    }

  int i = 0;

  for (i = 0; i < k; i++)
    {
      if (i >= j-1)
        {
          printf("%d ", curr->data);
        }

      curr = curr->next;
    }
  printf("\n");
}

void 
node_print_reverse(Node* curr)
{
  Node* temp = node_top(curr);
  printf("The reversed list contains: ");

  while (temp != NULL)
    {
      printf("%d ", temp->data);
      temp = temp->prev;
    }
  printf("\n");
}

void 
node_print_wide(Node* curr)
{
  while (curr != NULL)
    {
      printf("address [%p] | prev [%p] | data [%d] | next [%p]\n", 
             curr, curr->prev, curr->data, curr->next);
      curr = curr->next;
    }
  printf("\n");
}
