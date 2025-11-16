#include <glib.h>
#include <iostream>

int main() {
    // Inicializa GLib
    std::cout << "=== Hello World com GLib ===" << std::endl;
    
    // Verifica a versão do GLib
    std::cout << "Versão do GLib: " 
              << glib_major_version << "."
              << glib_minor_version << "."
              << glib_micro_version << std::endl;
    
    // Cria uma GList (lista encadeada do GLib)
    GList *lista = NULL;
    lista = g_list_append(lista, (gpointer)"Hello");
    lista = g_list_append(lista, (gpointer)"from");
    lista = g_list_append(lista, (gpointer)"GLib!");
    
    std::cout << "\nMensagem da lista: ";
    for (GList *l = lista; l != NULL; l = l->next) {
        std::cout << (char*)l->data << " ";
    }
    std::cout << std::endl;
    
    // Usa GString (string dinâmica do GLib)
    GString *gstr = g_string_new("GLib está funcionando");
    g_string_append(gstr, " perfeitamente!");
    std::cout << "\nGString: " << gstr->str << std::endl;
    
    // Limpeza
    g_list_free(lista);
    g_string_free(gstr, TRUE);
    
    std::cout << "\n✓ Programa finalizado com sucesso!" << std::endl;
    
    return 0;
}
