#include "sqlite3.h"
#include <stdio.h>
#include <string.h>

int main()
{
    sqlite3 *db;
    sqlite3_stmt * stmt;
    int result;

    sqlite3_open("futbol.sqlite", &db);

    char sql1[] = "insert into cmponatos (id, nombre, campeon) values (NULL, ?, ?)";
    char nombre[] = "Copa 2020-21";
    int campeon = 3;

    sqlite3_prepare_v2(db, sql1,strlen(sql1) + 1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, campeon);

    result = sqlite3_step(stmt);
    if(result != SQLITE_DONE)
    {
        printf("Error insertando el camponato\n");
    } else{
        printf("Campeonato %s(%i) insertado\n", nombre, campeon);
    }

    sqlite3_finalize(stmt);
}


