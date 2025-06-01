#include "password_generator.h"
#include <gtk/gtk.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    MODE_NUMERIC,
    MODE_ALPHABETIC,
    MODE_ALPHANUMERIC
} PasswordMode;

static void generate_password(GtkEntry *entry, int length, PasswordMode mode) {
    const char *numeric = "0123456789";
    const char *alphabetic = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *alphanumeric = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    const char *charset;
    int charset_len;
    
    switch (mode) {
        case MODE_NUMERIC:
            charset = numeric;
            charset_len = 10;
            break;
        case MODE_ALPHABETIC:
            charset = alphabetic;
            charset_len = 52;
            break;
        case MODE_ALPHANUMERIC:
            charset = alphanumeric;
            charset_len = 62;
            break;
        default:
            charset = numeric;
            charset_len = 10;
    }
    
    char password[length + 1];
    srand(time(NULL));
    
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_len];
    }
    password[length] = '\0';
    
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(entry), password, -1);
}

static void on_generate_clicked(GtkWidget *widget, gpointer data) {
    GtkEntry *length_entry = GTK_ENTRY(g_object_get_data(G_OBJECT(data), "length_entry"));
    GtkEntry *password_entry = GTK_ENTRY(g_object_get_data(G_OBJECT(data), "password_entry"));
    GtkDropDown *mode_dropdown = GTK_DROP_DOWN(g_object_get_data(G_OBJECT(data), "mode_dropdown"));
    
    const char *length_text = gtk_entry_buffer_get_text(gtk_entry_get_buffer(length_entry));
    int length = atoi(length_text);
    
    if (length > 0 && length <= 100) {
        PasswordMode mode = gtk_drop_down_get_selected(mode_dropdown);
        generate_password(password_entry, length, mode);
    }
}

void show_password_generator(GtkWindow *parent) {
    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "密码生成器");
    gtk_window_set_transient_for(GTK_WINDOW(window), parent);
    gtk_window_set_modal(GTK_WINDOW(window), TRUE);
    
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_widget_set_margin_top(grid, 10);
    gtk_widget_set_margin_bottom(grid, 10);
    gtk_widget_set_margin_start(grid, 10);
    gtk_widget_set_margin_end(grid, 10);
    
    GtkWidget *length_label = gtk_label_new("密码长度:");
    GtkWidget *length_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(length_entry), "输入1-100之间的数字");
    
    GtkWidget *mode_label = gtk_label_new("密码模式:");
    GtkStringList *string_list = gtk_string_list_new(NULL);
    gtk_string_list_append(string_list, "纯数字");
    gtk_string_list_append(string_list, "纯英文");
    gtk_string_list_append(string_list, "数字+英文");
    
    GtkWidget *mode_dropdown = gtk_drop_down_new(G_LIST_MODEL(string_list), NULL);
    gtk_drop_down_set_selected(GTK_DROP_DOWN(mode_dropdown), 0);
    
    GtkWidget *generate_button = gtk_button_new_with_label("生成密码");
    GtkWidget *password_entry = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(password_entry), FALSE);
    
    gtk_grid_attach(GTK_GRID(grid), length_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), length_entry, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), mode_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), mode_dropdown, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), generate_button, 0, 2, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), password_entry, 0, 3, 2, 1);
    
    g_object_set_data(G_OBJECT(window), "length_entry", length_entry);
    g_object_set_data(G_OBJECT(window), "password_entry", password_entry);
    g_object_set_data(G_OBJECT(window), "mode_dropdown", mode_dropdown);
    g_signal_connect(generate_button, "clicked", G_CALLBACK(on_generate_clicked), window);
    
    gtk_window_set_child(GTK_WINDOW(window), grid);
    gtk_window_present(GTK_WINDOW(window));
}
