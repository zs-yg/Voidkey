#include "file_reader.h"
#include <glib/gstdio.h>

char* read_file_content(const char* filename) {
    GError *error = NULL;
    gchar *content = NULL;
    
    if (!g_file_test(filename, G_FILE_TEST_EXISTS)) {
        return g_strdup("文件不存在");
    }

    g_file_get_contents(filename, &content, NULL, &error);
    
    if (error) {
        g_warning("无法读取文件: %s", error->message);
        g_error_free(error);
        return g_strdup("读取文件失败");
    }
    
    return content;
}
