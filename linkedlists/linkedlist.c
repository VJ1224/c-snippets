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

int listLength() {
  current = head;
  int i = 0;
  while(current != NULL) {
    current = current->next;
    i++;
  }

  return i;
}

void replace(int n, int index) {
  if (listLength() < index) {
    printf("Index does not exist.\n");
    return;
  }

  integer *new = (integer *) malloc(sizeof(integer));
  new->num = n;
  current = head;
  int i = 1;

  while(current != NULL) {
    if(i + 1 == index) {
      integer *temp = (integer *) malloc(sizeof(integer));
      temp = current -> next -> next;
      current -> next = new;
      new -> next = temp;
      return;
    }
    current = current-> next;
    i++;
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

  append(20);
  printList();
  printf("\n");
  replace(10,10);
  printList();

  integer* number = find(10);
  printf("\nFinding %d....",number->num);
  if (number != NULL)
    printf("found.\n");
  else
    printf("not found.\n");
}
