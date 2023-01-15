#include "libc.h"

void	my_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
