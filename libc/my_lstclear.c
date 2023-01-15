#include "libc.h"

void	my_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = *lst;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		my_lstdelone(*lst, (*del));
		*lst = temp;
	}
	*lst = NULL;
}
