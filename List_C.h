struct list
{
  int data;
  struct list* ptr;
};

//List initialization
struct list* init(int a)
{
  struct list* lst;
  lst = (struct list*) malloc(sizeof(struct list));
  lst->data = a;
  lst->ptr = NULL;
  return(lst);
}

//Adding new element

struct list* add(list* lst, int a)
{
  struct list *temp, *p;
  temp = (struct list*) malloc(sizeof(list));
  p = lst->ptr;
  lst->ptr = temp;
  temp->data = a;
  temp->ptr = p;
  return(temp);
}

//Removing the element
struct list* deleteElem(list* lst, list* root)
{
  struct list *temp;
  temp = root;
  while(temp->ptr != lst)
  {
    temp = temp->ptr;
  }
  temp -> ptr = lst->ptr;
  free(lst);
  return(temp);
}
//Removing the root
struct list* deleteHead(list* root)
{
  struct list *temp;
  temp = root->ptr;
  free(root);
  return(temp);
}
//Printing the list
void listPrint(list *lst)
{
  struct list *p;
  p = lst;
  do
  {
    printf("%d", p->data);
    p = p->ptr;
  }
  while(p != NULL);
}
//Swap
struct list* swap(struct list *lst1, struct list *lst2, struct list *head)
{
  struct list *prev1, *prev2, *next1, *next2;
  prev1 = head;
  prev2 = head;
  if(prev1 == lst1)
    prev1 = NULL;
  else
  while(prev1->ptr != lst1)
    prev1 = prev1->ptr;
  if(prev2 == lst2)
  prev2 = NULL;
  else
  while(prev2->ptr != lst2)
    prev2 = prev2->ptr;
  next1 = lst1->ptr;
  next2 = lst2->ptr;

  if(lst2 == next1)
  {
    lst2->ptr = lst1;
    lst1->ptr = next2;
    if(lst1 != head)
      prev1->ptr = lst2;
  }
  else
  if(lst2 == next2)
  {
    lst1->ptr = lst2;
    lst2->ptr = next1;
    if(lst2 != head)
      prev2->ptr = lst2;
  }
  else
  {
    if(lst1 != head)
      prev1->ptr = lst2;
    lst2->ptr = next1;
    if(lst2 != head)
      prev1->ptr = lst1;
    lst1->ptr = next1;
  }
  if(lst1 == head)
    return(lst2);
  if(lst2 == head)
    return(lst1);
  return(head);
}
