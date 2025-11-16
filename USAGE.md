# 1. Instala as dependências com Conan
conan install . --output-folder=build --build=missing

# 2. Configura o CMake usando as toolchains do Conan
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release

# 3. Compila o projeto
cmake --build build

# 4. Executa o programa
./build/hello_glib
```

## Saída Esperada

Você deverá ver algo como:
```
=== Hello World com GLib ===
Versão do GLib: 2.78.1

Mensagem da lista: Hello from GLib! 

GString: GLib está funcionando perfeitamente!

✓ Programa finalizado com sucesso!
