# Minishell 2

Interpréteur de commandes Unix développé en C.

## Présentation

Minishell 2 (B-PSU-200) est une reproduction d'un shell POSIX capable d'exécuter des commandes système et d'enchaîner des opérations complexes.

Fonctionnalités gérées :
- Exécution des commandes via `fork`, `execve` et `waitpid`.
- Résolution du `PATH` et gestion dynamique de l'environnement (`env`, `setenv`, `unsetenv`).
- Pipes multiples (`cmd1 | cmd2 | cmd3`).
- Redirections d'entrées et sorties (`<`, `>`, `>>`, `<<`).
- Opérateurs logiques et séparateurs (`;`, `&&`, `||`).
- Commandes internes intégrées (`cd`, `exit`, `echo`, `env`).

## Prérequis

- GCC
- Make

## Compilation et Lancement

```bash
# Compiler le projet
make

# Lancer le shell interactif
./mysh

# Exemple d'utilisation dans le shell
mysh> ls -la | grep src > output.txt && cat output.txt
```
