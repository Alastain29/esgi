#include <stdlib.h>
#include <string.h>
#include "db.h"

typedef struct TreeNode {
    Row *row;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
} TreeNode;

// Créer un nouveau nœud
TreeNode *create_node(Row *row) {
    TreeNode *node = malloc(sizeof(TreeNode));
    node->row = row;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Insérer dans l'arbre
TreeNode *insert(TreeNode *root, Row *row) {
    if (!root) return create_node(row);

    // Comparaison simplifiée pour l'exemple
    if (strcmp((char *)row->data[0], (char *)root->row->data[0]) < 0)
        root->left = insert(root->left, row);
    else
        root->right = insert(root->right, row);

    return root;
}

// Parcourir l'arbre
void inorder(TreeNode *root) {
    if (!root) return;
    inorder(root->left);
    // Affiche une ligne (exemple)
    printf("%s\n", (char *)root->row->data[0]);
    inorder(root->right);
}
