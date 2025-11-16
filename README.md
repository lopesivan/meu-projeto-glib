Ótimas perguntas! Vou explicar cada parte:

## ❌ Não usa o GLib do sistema!

O Conan **não usa** o GLib instalado no seu sistema. Ele vai:
1. **Baixar** o código-fonte do GLib 2.78.1
2. **Compilar** especificamente para o seu projeto
3. **Isolar** em uma pasta própria do Conan

Isso garante que seu projeto tenha **exatamente a versão especificada**, independente do que está instalado no sistema.

## 📦 Explicação de cada seção:

### `[requires]`
```
glib/2.78.1
```
- Define qual pacote e versão você quer
- É como um `npm install` ou `pip install`
- O Conan vai buscar no [Conan Center](https://conan.io/center)

### `[generators]`
```
CMakeDeps
CMakeToolchain
```
**CMakeDeps**: Gera arquivos `.cmake` para o CMake encontrar as bibliotecas
- Cria arquivos como `glibConfig.cmake`, `glibTargets.cmake`
- Permite usar `find_package(glib)` no CMakeLists.txt

**CMakeToolchain**: Gera o `conan_toolchain.cmake`
- Configura compilador, flags, paths
- É o que você passa com `-DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake`

### `[options]`
```
glib/*:shared=False
```

## 🎯 **`glib/*:shared=False` - O que significa?**

Esta opção controla **como a biblioteca será linkada**:

| Opção | Significado | Resultado |
|-------|-------------|-----------|
| `shared=False` | **Biblioteca estática** (`.a` no Linux) | O código da GLib é **copiado para dentro** do seu executável |
| `shared=True` | **Biblioteca dinâmica** (`.so` no Linux) | Seu executável precisa do arquivo `.so` separado para rodar |

### 🔍 Diferenças Práticas:

**Com `shared=False` (estática)**:
```bash
# Seu executável fica maior, mas é standalone
./hello_glib  # Funciona sozinho! ✓

# Tamanho: ~5-10 MB (inclui todo o código da GLib)
```

**Com `shared=True` (dinâmica)**:
```bash
# Seu executável fica menor, mas precisa do .so
./hello_glib  # Pode dar erro se não achar libglib.so

# Tamanho: ~100 KB (só seu código)
# Mas precisa que libglib.so esteja disponível
```

### Sintaxe `glib/*:`
- `glib/` = nome do pacote
- `*` = todas as versões
- `:shared=False` = opção específica

Poderia ser mais específico:
```
glib/2.78.1:shared=False  # Só para versão 2.78.1
```

## 🔄 Onde os arquivos ficam?

```bash
~/.conan2/p/      # Pacotes baixados e compilados
  └── glib.../
      ├── include/  # Headers (.h)
      ├── lib/      # Bibliotecas (.a ou .so)
      └── bin/      # Executáveis auxiliares

build/            # Seu projeto
  └── conan_toolchain.cmake  # Aponta para ~/.conan2/p/
```

## 💡 Vantagens de **NÃO** usar a lib do sistema:

✅ Versão exata e reproduzível  
✅ Funciona igual em qualquer máquina  
✅ Não quebra se alguém atualizar o sistema  
✅ Múltiplos projetos com versões diferentes  

Ficou claro? Quer que eu mostre como ver onde os arquivos foram instalados? 🔍
