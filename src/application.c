#include "application.h"
#include "main_window.h"

static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = create_main_window(app);
    gtk_window_present(GTK_WINDOW(window));
}

GtkApplication *create_application(void) {
    GtkApplication *app = gtk_application_new(
        "com.example.passwordtool", 
        G_APPLICATION_DEFAULT_FLAGS
    );
    
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    return app;
}
