#include <stdio.h>
#include <stdlib.h>

typedef struct integer {
  int num;
  struct integer *next;
} integer;

integer *head = NULL;
integer *current = NULL;

int isEmpty();
void printList();
int listLength();
void replace(int, int);
void delete(int);
void append(int);
void prepend(int);
integer* find();
void release();
void reverse();

int main() {
  for (int i = 1; i < 10; i++) {
    append(i);
  }

  prepend(10);
  printList();
  printf("\n");
  replace(0,1);
  printList();
  printf("\n");

  int d = 10;
  printf("Finding %d...", d);
  integer* number = find(d);
  if (number != NULL) {
    printf("found.\n\n");
  } else {
    printf("not found.\n\n");
  }

  reverse();
  printList();
  printf("\n");

  release();
}

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

  current = head;
  int i = 1;

  while(current != NULL) {
    if (i  == index) {
      current -> num = n;
      return;
    }
    current = current -> next;
    i++;
  }

  printf("Could not replace.\n");
}

void delete(int index) {
  if (listLength() < index) {
    printf("Index does not exist.\n");
    return;
  }

  current = head;
  int i = 1;
  while (current != NULL) {
    if (i + 1 == index) {
      free(current->next);
      current -> next = current -> next -> next;
    }
    current = current -> next;
    i++;
  }
}

void append(int n) {
  integer * new = malloc(sizeof(integer));
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
  integer * new = malloc(sizeof(integer));
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

void release() {
  current = head;
  while (current->next != NULL) {
    integer * temp = current -> next;
    free(current);
    current = temp;
  }
  free(current);
}

void reverse() {
  integer * prev = NULL;
  integer * next = NULL;
  current = head;
  while (current != NULL) {
    next = current -> next;
    current -> next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}