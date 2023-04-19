#include <stdio.h>
#include <string.h>
#include "sqlite3.h"

#define MAX_CHAR 200

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char sql[MAX_CHAR];
    const char* data = "Callback function called";

    // Apertura de la BD
    rc = sqlite3_open("../agenda.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return (1);
    }

    // Creacion de consulta SQL
    strcpy(sql,"SELECT * FROM agenda");

    // Ejecucion de comando SQL: se invoca la funcion callback para cada
    // fila del resultado obtenido
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    // Clausura de conexion
    sqlite3_close(db);

    return 0;
}
