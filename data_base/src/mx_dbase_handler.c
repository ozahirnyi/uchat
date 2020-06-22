#include "dbase.h"

json_object *mx_dbase_handler(json_object *jobj, sqlite3 *db) {
    t_datab *datab = mx_create_datab_node();
    json_object *j_result = json_object_new_object();

    if (!mx_strcmp("Logging", mx_json_to_str(jobj, "Type")))
        j_result = mx_if_logging(jobj, db, datab);
    else if (!mx_strcmp("Registr", mx_json_to_str(jobj, "Type")))
        j_result = mx_if_registr(jobj, db, datab);
    return j_result;
}