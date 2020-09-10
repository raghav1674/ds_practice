void reverse(NODE **start)
{

    NODE *previous = *start;
    NODE *current = previous->next;
    NODE *next = previous->next;

   (*start)->next=NULL;

while(current!=NULL){
   
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
}

*start=previous;

}
