#include "clipboard.h"
#include <gtk/gtk.h>
#include <string.h>

void copy_to_clipboard(GtkEntry *entry) {
    if (!GTK_IS_ENTRY(entry)) return;
    
    GtkWidget *widget = GTK_WIDGET(entry);
    GtkWindow *window = GTK_WINDOW(gtk_widget_get_root(widget));
    GtkLabel *status_label = GTK_LABEL(g_object_get_data(G_OBJECT(window), "copy_status"));
    
    GtkEntryBuffer *buffer = gtk_entry_get_buffer(entry);
    const char *text = gtk_entry_buffer_get_text(buffer);
    int length = gtk_entry_buffer_get_length(buffer);
    
    if (length == 0) {
        gtk_label_set_text(status_label, "请先生成密码");
        return;
    }

    // 使用更基础的剪贴板API
    GdkDisplay *display = gtk_widget_get_display(widget);
    GdkClipboard *clipboard = gdk_display_get_clipboard(display);
    
    // 设置文本到剪贴板
    gdk_clipboard_set_text(clipboard, text);
    
    // 直接显示成功消息
    gtk_label_set_text(status_label, "密码已复制到剪贴板");
}
