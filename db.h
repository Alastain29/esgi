#ifndef DB_H
#define DB_H

typedef struct {
    char name[50];
    char type[10]; // Exemple : "INT", "STRING"
} Column;

typedef struct {
    char name[50];
    int column_count;
    Column *columns; // Tableau dynamique des colonnes
} Table;

typedef struct {
    void **data; // Pointeurs vers les valeurs des colonnes
} Row;

// Fonction pour initialiser une table
Table *create_table(const char *name, int column_count, Column *columns);

// Fonction pour libérer une table
void free_table(Table *table);

#endif
           