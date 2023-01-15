#include "libc.h"

t_list	*my_lstlast(t_list *lst)
{
	t_list	*new;

	new = lst;
	while (new)
	{
		if (new->next == NULL)
			return (new);
		new = new->next;
	}
	return (NULL);
}
