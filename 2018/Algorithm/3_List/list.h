/* list.h */

typedef void* LIST;
typedef void* POSITION;

LIST list_construct();
void list_free(LIST lst);
void list_print(LIST lst);

void list_insert(LIST lst, POSITION pos, int value);
void list_delete(LIST lst, POSITION pos);
int list_retrieve(LIST lst, POSITION pos);
POSITION list_first(LIST lst);
POSITION list_last(LIST lst);
POSITION list_next(LIST lst, POSITION pos);
POSITION list_previous(LIST lst, POSITION pos);

POSITION list_get(LIST lst, long n);

//POSITION list_index(LIST lst, int value);