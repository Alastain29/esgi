#include <stdio.h>
#include <stdlib.h>
#include "db.h"

void save_table(TreeNode *root, FILE *file) {
    if (!root) return;

    fwrite(root->row->data, sizeof(void *), 1, file);
    save_table(root->left, file);
    save_table(root->right, file);
}

TreeNode *load_table(FILE *file) {
    TreeNode *root = NULL;
    Row row;

    while (fread(&row, sizeof(Row), 1, file)) {
        root = insert(root, &row);
    }
    return root;
}
