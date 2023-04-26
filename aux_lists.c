#include "main.h"

/**
 * add_sep_node_end - adds a separator found at the end
 * of a sep_list.
 * @headOfList: headOfList of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the headOfList.
 */
sep_list *add_sep_node_end(sep_list **headOfList, char sep)
{
	sep_list *new, *temp;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	temp = *headOfList;

	if (temp == NULL)
	{
		*headOfList = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*headOfList);
}

/**
 * free_sep_list - frees a sep_list
 * @headOfList: headOfList of the linked list.
 * Return: no return.
 */
void free_sep_list(sep_list **headOfList)
{
	sep_list *temp;
	sep_list *curr;

	if (headOfList != NULL)
	{
		curr = *headOfList;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*headOfList = NULL;
	}
}

/**
 * add_line_node_end - adds a command line at the end
 * of a line_list.
 * @headOfList: headOfList of the linked list.
 * @line: command line.
 * Return: address of the headOfList.
 */
line_list *add_line_node_end(line_list **headOfList, char *line)
{
	line_list *new, *temp;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *headOfList;

	if (temp == NULL)
	{
		*headOfList = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*headOfList);
}

/**
 * free_line_list - frees a line_list
 * @headOfList: headOfList of the linked list.
 * Return: no return.
 */
void free_line_list(line_list **headOfList)
{
	line_list *temp;
	line_list *curr;

	if (headOfList != NULL)
	{
		curr = *headOfList;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*headOfList = NULL;
	}
}
