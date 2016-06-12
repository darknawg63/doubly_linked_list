#include "node.h"
#include "output.h"

Node*
node_new(int x)
{
  Node* node = malloc(sizeof(*node));
  node->data = x;
  node->next = NULL;
  node->prev = NULL;

  return node;
}

Node*
node_insert(Node* head, int x, int n)
{
  Node* new = node_new(x);
  Node* curr = head;
  int i;

  if (curr == NULL)
    {
      curr = new;

      return curr;
    }

  // We are prepending to a list.
  if (n == 1)
    {
      new->next = curr;
      curr->prev = new;
      curr = new;

      return curr;
    }

  // We are appending to a list which consists of one node.
  while (curr->prev == NULL &&
         curr->next == NULL &&
         curr != NULL)
    {
      curr->next = new;
      new->prev = curr;

      return curr;
    }

  // Inserting into a list.
  for (i = 0; i < n-2; i++)
    {
      curr = curr->next;
    }

  // Inserting at the tail (prepends last node).
  if (curr->next == NULL)
    {
      new->prev = curr;
      curr->next = new;

      return head;
    }

  // All other cases
  new->next = curr->next;
  new->prev = curr;
  curr->next->prev = new;
  curr->next = new;

  return head;
}

Node*
node_push(Node* curr, int x)
{
  Node* new = node_new(x);

  if (curr == NULL)
    {
      curr = new;
      return curr;
    }
  new->next = curr;
  new->prev = NULL;
  curr->prev = new;
  curr = new;

  return curr;
}

Node*
node_delete(Node* head, int x)
{
  Node* curr = head;
  Node* orphan;
  int i;

  for (i = 0; i < x-1; i++)
    {
      curr = curr->next;
    }
  orphan = curr;
  curr->prev->next = curr->next;
  curr->next->prev = curr->prev;
  free(orphan);

  return head;
}

void node_free(Node* head)
{
    Node *next,*curr;
    curr = head;
    while (curr != NULL)
    {
       next = curr -> next;
       free(curr);
       curr = next;
    }
}
