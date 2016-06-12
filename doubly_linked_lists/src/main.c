#include "output.h"
#include "mutator.h"

int 
main(void)
{
  Node* head = NULL;
  head = node_push(head, 7);
  head = node_push(head, 1);
  head = node_push(head, 3);
  head = node_push(head, 5);
//  head = node_insert(head, 6, 5);
//  head = node_insert(head, 2, 2);
  head = node_delete(head, 2);
  node_print(head, 1, 3);
  node_free(head);

  return 0;
}
