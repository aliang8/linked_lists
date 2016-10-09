#include <stdio.h>
#include <stdlib.h>

//Node structures
struct node { 
  int data; 
  struct node *next;
};

//headers
struct node *insert_front(struct node *ptr, int data);
void print_list(struct node *ptr);
struct node *free_list(struct node *ptr);

struct node * insert_front(struct node *ptr, int data){
  //parent node
  struct node *parent = (struct node *)malloc(sizeof(struct node));
  parent->data = data;
  parent->next = ptr;
  return parent;
}

void print_list(struct node *ptr){
  while(ptr->next){
    printf("%i",ptr->data);
    printf(" >> ");
    ptr = ptr->next;
  }
  printf("%i",ptr->data);
  printf("\n");
}

struct node* free_list(struct node* ptr){
  struct node *tmp = ptr;
  struct node *tmp2;
  while(tmp){
    tmp2 = tmp->next;
    free(tmp);
    tmp = tmp2;
  }
  ptr = NULL;
  return ptr;
}

int main(){
  //new linked list
  printf("Creating initial node...\n");
  struct node * list = (struct node*)malloc(sizeof(struct node));
  list->data = 0;
  list->next = NULL;
  
  //Adding values
  printf("Adding values to linked list...\n");
  int i;
  for(int i = 1; i <= 20; i++){
    list = insert_front(list,i);
  }

  printf("Updated list: \n");
  print_list(list);

  //Freeing memory
  printf("Freeing the list...\n");
  list = free_list(list);
  printf("Pointer after freeing list: %p\n", list);
}
  
  
