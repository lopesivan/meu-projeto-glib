Ah, você precisa criar o profile padrão do Conan primeiro! Execute este comando:

```bash
conan profile detect
```

Este comando vai detectar automaticamente as configurações do seu sistema (compilador, arquitetura, etc.) e criar o profile padrão.

Depois disso, você pode executar novamente:

```bash
conan install . --output-folder=build --build=missing
```

---

**O que é um profile do Conan?**

O profile contém informações sobre o ambiente de compilação, como:
- Compilador (gcc, clang, etc.)
- Versão do compilador
- Arquitetura (x86_64, ARM, etc.)
- Sistema operacional
- Configurações de build (Release, Debug)

Se você quiser ver o conteúdo do profile criado, pode usar:

```bash
conan profile show default
```

Isso deve resolver o problema! Me avise se aparecer algum outro erro. 🚀
