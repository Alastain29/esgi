#include <assert.h>
#include "db.h"

void test_insert() {
    TreeNode *root = NULL;

    Row row1 = { .data = (void *[]){"Alice"} };
    Row row2 = { .data = (void *[]){"Bob"} };

    root = insert(root, &row1);
    root = insert(root, &row2);

    assert(root != NULL);
    assert(strcmp((char *)root->row->data[0], "Alice") == 0);
    printf("Test insert passed.\n");
}

void run_tests() {
    test_insert();
}
