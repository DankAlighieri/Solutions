#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  int val;
  struct ListNode *next;
} ListNode;

typedef ListNode *list;

void cria(list *l) {
  int v;
  list tail;

  *l = NULL;

  while (scanf("%d", &v), v) {
    list novo = (list)malloc(sizeof(ListNode));

    novo->val = v;
    novo->next = NULL;

    if (!(*l)) {
      *l = novo;
    } else {
      tail->next = novo;
    }
    tail = novo;
  }
}

int tam(list l) {
  int i = 0;
  while (l) {
    i++;
    l = l->next;
  }
  return i;
}
ListNode *ret(ListNode *prev) {
  list aux = prev->next;
  prev->next = aux->next;
  free(aux);
  aux = prev->next;
  return aux;
}

list deleteDuplicates(list head) {
  int t = tam(head);
  list curr = head, aux = NULL, prev = NULL;

  for (; curr; curr = curr->next) {
    prev = curr;
    aux = curr->next;
    printf("curr = %d\n", curr->val);
    while (aux) {
      printf("%d = %d?\n", curr->val, aux->val);
      if (curr->val == aux->val) {
        printf("Removendo %d\n", aux->val);
        aux = ret(prev);
      } else {
        prev = aux;
        aux = aux->next;
      }
    }
  }

  return head;
}

void mostra(list l) {
  while (l) {
    printf("%d\n", l->val);
    l = l->next;
  }
}

int main() {

  list l;
  cria(&l);

  // mostra(l);

  mostra(deleteDuplicates(l));
}