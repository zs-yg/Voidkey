#include "main_window.h"
#include "password_generator.h"
#include "file_reader.h"
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <stdlib.h>  // for realpath

static void on_generate_password(GtkWidget *widget, gpointer data) {
    show_password_generator(GTK_WINDOW(data));
}

GtkWidget *create_main_window(GtkApplication *app) {
    // 创建主窗口并禁用全屏
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Voidkey");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_window_set_deletable(GTK_WINDOW(window), FALSE);

    // 使用GTK4默认主题图标
    g_print("使用GTK4默认主题图标\n");

    // 创建主布局
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_top(box, 20);
    gtk_widget_set_margin_bottom(box, 20);
    gtk_widget_set_margin_start(box, 20);
    gtk_widget_set_margin_end(box, 20);

    // 添加宣传图片(使用相对路径)
    const char *image_path = "img/png/Voidkey.png";
    GtkWidget *image = NULL;
    if (g_file_test(image_path, G_FILE_TEST_EXISTS)) {
        GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(image_path, NULL);
        if (pixbuf) {
            // 设置图片宽度为窗口宽度-60px(考虑边距)
            int width = 200;
            int height = width * gdk_pixbuf_get_height(pixbuf) / gdk_pixbuf_get_width(pixbuf);
            GdkPixbuf *scaled = gdk_pixbuf_scale_simple(pixbuf, width, height, GDK_INTERP_BILINEAR);
            GdkPaintable *paintable = GDK_PAINTABLE(gdk_texture_new_for_pixbuf(scaled));
            image = gtk_image_new_from_paintable(paintable);
            gtk_widget_set_size_request(image, width, height);
            g_object_unref(pixbuf);
            g_object_unref(scaled);
            g_object_unref(paintable);
        }
    } else {
        g_warning("图片文件不存在: %s", image_path);
    }
    gtk_box_append(GTK_BOX(box), image);

    // 添加分隔空间
    GtkWidget *separator = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_box_append(GTK_BOX(box), separator);

    // 添加文本内容
    char *file_content = read_file_content("read.txt");
    GtkWidget *text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD);
    
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    gtk_text_buffer_set_text(buffer, file_content, -1);
    g_free(file_content);
    
    GtkWidget *scrolled_window = gtk_scrolled_window_new();
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window), text_view);
    gtk_box_append(GTK_BOX(box), scrolled_window);

    // 添加密码生成按钮
    GtkWidget *button = gtk_button_new_with_label("生成密码");
    g_signal_connect(button, "clicked", G_CALLBACK(on_generate_password), window);
    gtk_box_append(GTK_BOX(box), button);

    gtk_window_set_child(GTK_WINDOW(window), box);
    return window;
}
