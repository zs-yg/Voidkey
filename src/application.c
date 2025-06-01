#include "application.h"
#include "main_window.h"

static void on_startup(G_GNUC_UNUSED GtkApplication *app, G_GNUC_UNUSED gpointer user_data) {
    // 初始化CSS样式
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_string(provider,
        "window.unanimated { animation: none; transition: none; }");
    
    GdkDisplay *display = gdk_display_get_default();
    if (display) {
        gtk_style_context_add_provider_for_display(display,
            GTK_STYLE_PROVIDER(provider), 
            GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    }
}

static void on_activate(GtkApplication *app, G_GNUC_UNUSED gpointer user_data) {
    GtkWidget *window = create_main_window(app);
    gtk_window_present(GTK_WINDOW(window));
}

GtkApplication *create_application(void) {
    GtkApplication *app = gtk_application_new(
        "com.example.passwordtool", 
        G_APPLICATION_DEFAULT_FLAGS
    );
    
    g_signal_connect(app, "startup", G_CALLBACK(on_startup), NULL);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    return app;
}
