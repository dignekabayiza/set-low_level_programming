#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - adds or updates an element in a hash table
 * @ht: the hash table
 * @key: the key (cannot be an empty string)
 * @value: the value associated with the key (duplicated)
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node;
	char *new_value;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	new_value = strdup(value);
	if (new_value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	for (node = ht->array[index]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);
			node->value = new_value;
			return (1);
		}
	}

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
	{
		free(new_value);
		return (0);
	}

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(new_value);
		free(node);
		return (0);
	}

	node->value = new_value;
	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
