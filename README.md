# Minishell 2

Un interpréteur de commandes Unix complet fait en C

Fonctionnalités :
- Exécution des commandes système avec gestion du PATH
- Gestion des builtins (`cd`, `env`, `setenv`, `unsetenv`, `exit`, `echo`)
- Pipes multiples (`|`) et redirections (`<`, `>`, `>>`, `<<`)
- Séparateurs et opérateurs logiques (`;`, `&&`, `||`)

## Build et lancement

```bash
make
./mysh
```
