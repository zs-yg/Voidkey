#include "application.h"

int main(int argc, char *argv[]) {
    GtkApplication *app = create_application();
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
