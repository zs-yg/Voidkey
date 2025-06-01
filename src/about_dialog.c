#include "about_dialog.h"
#include <gtk/gtk.h>
#include <glib/gstdio.h>

static void on_link_clicked(GtkLabel *label, const char *uri, gpointer data) {
    GtkUriLauncher *launcher = gtk_uri_launcher_new(uri);
    gtk_uri_launcher_launch(launcher, GTK_WINDOW(data), NULL, NULL, NULL);
    g_object_unref(launcher);
}

void show_about_dialog(GtkWindow *parent) {
    GtkWidget *dialog = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(dialog), "关于 VoidKey");
    gtk_window_set_transient_for(GTK_WINDOW(dialog), parent);
    gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
    gtk_window_set_default_size(GTK_WINDOW(dialog), 400, 300);

    GtkWidget *content = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_top(content, 10);
    gtk_widget_set_margin_bottom(content, 10);
    gtk_widget_set_margin_start(content, 10);
    gtk_widget_set_margin_end(content, 10);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    // 添加关于图片
    GtkWidget *about_image = NULL;
    const char *image_path = "img/png/about.png";
    if (g_file_test(image_path, G_FILE_TEST_EXISTS)) {
        GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(image_path, NULL);
        if (pixbuf) {
            int width = 150;
            int height = width * gdk_pixbuf_get_height(pixbuf) / gdk_pixbuf_get_width(pixbuf);
            GdkPixbuf *scaled = gdk_pixbuf_scale_simple(pixbuf, width, height, GDK_INTERP_BILINEAR);
            GdkPaintable *paintable = GDK_PAINTABLE(gdk_texture_new_for_pixbuf(scaled));
            about_image = gtk_image_new_from_paintable(paintable);
            gtk_widget_set_size_request(about_image, width, height);
            g_object_unref(pixbuf);
            g_object_unref(scaled);
            g_object_unref(paintable);
        }
    }
    if (about_image) {
        gtk_box_append(GTK_BOX(box), about_image);
    }
    
    GtkWidget *title = gtk_label_new("VoidKey 密码工具");
    gtk_widget_set_halign(title, GTK_ALIGN_CENTER);
    PangoAttrList *attrs = pango_attr_list_new();
    pango_attr_list_insert(attrs, pango_attr_weight_new(PANGO_WEIGHT_BOLD));
    pango_attr_list_insert(attrs, pango_attr_scale_new(1.5));
    gtk_label_set_attributes(GTK_LABEL(title), attrs);
    pango_attr_list_unref(attrs);
    
    GtkWidget *version = gtk_label_new("版本: v4.0");
    gtk_widget_set_halign(version, GTK_ALIGN_CENTER);
    
    GtkWidget *author = gtk_label_new("作者: zs-yg");
    gtk_widget_set_halign(author, GTK_ALIGN_CENTER);
    
    GtkWidget *email = gtk_label_new("邮箱: chr_super@outlook.com");
    gtk_widget_set_halign(email, GTK_ALIGN_CENTER);
    
    GtkWidget *qq = gtk_label_new("QQ: 3872006562");
    gtk_widget_set_halign(qq, GTK_ALIGN_CENTER);
    
    GtkWidget *github = gtk_label_new("GitHub: <a href=\"https://github.com/zs-yg/Voidkey\">项目地址</a>");
    gtk_label_set_use_markup(GTK_LABEL(github), TRUE);
    gtk_widget_set_halign(github, GTK_ALIGN_CENTER);
    g_signal_connect(github, "activate-link", G_CALLBACK(on_link_clicked), NULL);
    
    gtk_box_append(GTK_BOX(box), title);
    gtk_box_append(GTK_BOX(box), version);
    gtk_box_append(GTK_BOX(box), author);
    gtk_box_append(GTK_BOX(box), email);
    gtk_box_append(GTK_BOX(box), qq);
    gtk_box_append(GTK_BOX(box), github);
    
    gtk_box_append(GTK_BOX(content), box);
    
    GtkWidget *close = gtk_button_new_with_label("关闭");
    gtk_box_append(GTK_BOX(content), close);
    g_signal_connect_swapped(close, "clicked", G_CALLBACK(gtk_window_close), dialog);
    gtk_window_set_child(GTK_WINDOW(dialog), content);
    
    gtk_window_present(GTK_WINDOW(dialog));
}
