#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"

void execute_insert(TreeNode **root, Row *row) {
    *root = insert(*root, row);
    printf("Row inserted successfully.\n");
}

void execute_select(TreeNode *root) {
    printf("Displaying all rows:\n");
    inorder(root);
}
