/* set.h */

typedef void* SET;

SET set_construct();
void set_free(SET set);

int set_insert(SET set, char* str);
int set_delete(SET set, char* str);
int set_member(SET set, char* str);

