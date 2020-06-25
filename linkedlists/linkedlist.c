#include <stdio.h>
#include <stdlib.h>

typedef struct integer {
  int num;
  struct integer *next;
} integer;

integer *head = NULL;
integer *current = NULL;

int isEmpty() {
  return head == NULL;
}

void printList() {
   current = head;

   while(current != NULL) {
      printf("%d\n",current->num);
      current = current->next;
   }
}

void append(int n) {
  integer *new = (integer *) malloc(sizeof(integer));
  new->num = n;

  if (isEmpty()) {
    head = new;
    return;
  }

  current = head;
  while (current != NULL) {
    if (current->next == NULL) {
      current->next = new;
      return;
    }
    current = current->next;
  }
}

void prepend(int n) {
  integer *new = (integer *) malloc(sizeof(integer));
  new->num = n;
  new->next = head;
  head = new;
}

integer* find(int n) {
   if(isEmpty()) {
      return NULL;
   }

   current = head;
   while(current->num != n) {
      if(current->next == NULL) {
         return NULL;
      } else {
         current = current->next;
      }
   }

   return current;
}

int main() {
  for (int i = 1; i < 10; i++) {
    append(i);
  }

  prepend(0);
  printList();

  integer* number = find(1);
  if (number != NULL)
    printf("Found.\n");
  else
    printf("Not found.\n");
}
