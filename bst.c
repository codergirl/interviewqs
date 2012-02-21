#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 100

int max(int a, int b)
{
    return a > b ? a : b;
}

typedef struct nodeT {
  struct nodeT* left;
  struct nodeT* right;
  char data;
} node;

typedef node* stack_elem;

// -----------------------------------------------------------------
// stack definition                                                -
// -----------------------------------------------------------------
typedef struct stackT {
  stack_elem data[STACK_MAX];
  int size;
} stack;

void stack_init(stack *s)
{
   s->size = 0;
}

stack_elem stack_pop(stack *s)
{
  if (s->size < 1)
  {
    printf("can't pop empty stack\n");
    exit(1);
  }
  s->size = s->size - 1;
  return s->data[s->size];
}

void stack_push(stack *s, stack_elem e)
{
   if (s->size+1 == STACK_MAX)
   {
       printf("Too many elements, max stack size is %d.\n", STACK_MAX);
       exit(-1);
   }
   (s->data)[s->size] = e;
   s->size = s->size + 1;
}

int stack_is_empty(stack *s)
{
   if (s->size == 0) return 1; else return 0;
}

// ------------------------------------------------------
// dfs                                                  -
// ------------------------------------------------------

int dfs(node* root, char value)
{
   stack s;
   stack_init(&s);

   stack_push(&s, root);

   while (!stack_is_empty(&s))
   {
     stack_elem curr = stack_pop(&s);
     printf("%c == %c ?\n", curr->data, value);
     if (curr->data == value)
     {
        printf("elem found\n");
        return 1;
     }
     if (curr->right)
        stack_push(&s, curr->right);
     if (curr->left)
        stack_push(&s, curr->left);
   }
   printf("not found\n");
   return 0;
}


// -----------------------------------------------------------
// binary search tree (i.e. ordered) search                  -
//------------------------------------------------------------
int bst_search(node* root, char value)
{
  node* curr = root;

  while (curr)
  {
    if (value == curr->data) 
    {
      printf("found\n");
      return 1;
    }
    else if (value < curr->data) 
    {
       printf("%c < %c, search left\n", value, curr->data);
       curr = curr->left;
    }
    else 
    {
      printf("%c > %c, search right\n", value, curr->data);
      curr = curr->right;
   }
  }
  printf("not found\n");
  return 0;
}

void inorder(node* root)
{
   stack s;
   stack_init(&s);

   node* curr = root;

   while(curr || !stack_is_empty(&s)) 
   {
      if (curr)
      {
        stack_push(&s, curr);
        curr = curr->left; 
      }
      else
      {
         curr = stack_pop(&s);
         printf("%c\n", curr->data);
         curr = curr->right;
      }
   }
}

int longest_path_length(node* n)
{
    if (!n)
        return 0;

    return max(longest_path_length(n->left)+1,
               longest_path_length(n->right)+1);
    
}

void test_bst_search(int argc, char* argv[])
{
  node n9 = {NULL,NULL,'8'};
  node n6 = {NULL,NULL,'5'};
  node n7 = {&n6, &n9, '7'};
  node n2 = {NULL,NULL,'3'};
  node n5 = {&n2,&n7,'4'};
  node n13 = {NULL,NULL,'9'};
  node n10 = {&n5,&n13,'9'};

  bst_search(&n10,*argv[1]);
}

int main(int argc, char* argv[])
{
  //test_bst_search(argc, argv);
  node n9 = {NULL,NULL,'8'};
  node n6 = {NULL,NULL,'5'};
  node n7 = {&n6, &n9, '7'};
  node n2 = {NULL,NULL,'3'};
  node n5 = {&n2,&n7,'4'};
  node n13 = {NULL,NULL,'9'};
  node n10 = {&n5,&n13,'9'};
  node n11 = {NULL, &n10, '1'};
  
  node c3_1 = {NULL, NULL, 'z'};
  node c2_2 = {NULL, &c3_1, 'y'};
  node c2_1 = {NULL, &c2_2, 'x'};
  node c1_1 = {NULL, &c2_1, 'a'};
  node c1_2 = {NULL, NULL, 'b'};
  node c0 = {&c1_1, &c1_2, '0'};

  inorder(&c0);
  int len = longest_path_length(&c0);
  printf("longest path: %d\n", len);
}


