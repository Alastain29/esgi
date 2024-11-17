#include <stdio.h>
#include <string.h>
#include "db.h"
#include "commands.h"
#include "storage.h"

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "--test") == 0) {
        run_tests();
        return 0;
    }

    printf("Welcome to SimpleDB!\n");

    // Exemple de table et commandes
    Column columns[] = {
        {"Name", "STRING"}
    };
    Table *table = create_table("Users", 1, columns);

    TreeNode *root = NULL;

    Row row1 = { .data = (void *[]){"Alice"} };
    Row row2 = { .data = (void *[]){"Bob"} };

    execute_insert(&root, &row1);
    execute_insert(&root, &row2);

    execute_select(root);

    return 0;
}
