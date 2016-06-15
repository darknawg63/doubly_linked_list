#ifndef MUTATOR_H_
#define MUTATOR_H_

#include "node.h"
#include "output.h"

Node* node_new(int x);
Node* node_insert(Node* head, int x, int n);
Node* node_push(Node* head, int x);
Node* node_delete(Node* head, int x);
Node* node_set(Node* head, int, int n);
void node_free(Node* head);

#endif
