typedef struct hashset_node
{
    struct hashset_node *next;
    char *value;
} hashset_node;

typedef struct hashset
{
    hashset_node *table[10];
} hashset;

int set_member(hashset *set, char *str)
{
    int h = hash(str);
    hashset_node *node = set;
    while (node != NULL)
    {
        if (strcmp(node->value, str) == 0)
        {
            return 1;
        }
        node->value = h;
        node = node->next;
    }
    return 0;
}