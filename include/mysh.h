/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-dorian.senecot
** File description:
** mysh
*/

typedef struct alias_s {
    char **replace;
    char **cmd;
} alias_t;

typedef struct mysh {
    alias_t *alias;
    char ***parsing;
    char **envp;
    char *str;
    char **history;
    char **tab_line;
    char **cpy_tab;
    char *oldpwd;
    int status;
    int old;
    int oldplace;
    int tmp;
    int linevar;
    int count;
    int ireturn;
    int st;
    int lenenv;
    int cancel;
    int separator;
    int statu;
    int and_door;
    int or_door;
    int pipe;
    int is_separator;
    int result;
    int door;
    int start;
} mysh_t;

#ifndef MYSH_H_
    #define MYSH_H_
    #include "my.h"
    int launch_process(char **input, char *new_line);
    int add_bg_process(pid_t pid, char *new_line);
    int check_pid(char **input, char *new_line, int i);
    int set_jobs_controls(struct mysh *cmd, char **input, char *new_line);
    int tmp_envp(struct mysh *cmd, char **envp);
    int menu_manage(struct mysh *cmd, char **argv);
    int envp_recup(struct mysh *cmd, char *info);
    int cmd_envp(struct mysh *cmd);
    void alias_search(mysh_t *cmd, int i);
    char *add_character(char* string, char character);
    int repeat(mysh_t *cmd, char **input, char *new_line);
    int alias_replace(mysh_t *cmd, int i);
    int cmd_exit(struct mysh *cmd);
    int cmd_cd(struct mysh *cmd, char *input);
    void env_update(struct mysh *cmd, char *tmp);
    int my_echo(mysh_t *cmd, char **input);
    char **old_pwd(struct mysh *cmd, char *tmp);
    void backticks(struct mysh *cmd, char **input);
    char **new_env(struct mysh *cmd, char *var, char *value);
    int getlinevar(struct mysh *cmd, char *info);
    void testpath(struct mysh *cmd, char *input);
    void cp_str(struct mysh *cmd);
    char **cmd_unenv(struct mysh *cmd, char *var);
    void execute_manage(struct mysh *cmd, char **input);
    char **my_str_to_word_array_path(char *str);
    void set_history(mysh_t *cmd, char *tmp);
    void erno_error(char **input);
    char *parsing(char *input);
    void prompt(struct mysh *cmd);
    int history_print(mysh_t *cmd);
    int history_print_nbr(mysh_t *cmd, int nb);
    void get_pars(struct mysh *cmd);
    int red_out(struct mysh *cmd, char *file, char **input, char *new_line);
    int cmd_manage(struct mysh *cmd, char **input, char *new_line);
    int red_out_plus(struct mysh *cmd, char *file,
    char **input, char *new_line);
    int red_in(struct mysh *cmd, char *file, char **input, char *new_line);
    int pipe_manage(struct mysh *cmd, char **input, int i, char *new_line);
    char **remove_str_from_tab(char **tab, char *c);
    int red_in_plus(struct mysh *cmd, char *file,
    char **input, char *new_line);
    char **cp_tab(char **input);
    int lentabin(char **input);
    char *parsing(char *input);
    char **remove_str_from_tab_int(char **tab, int c);
    void free_tab(char **input);
    void my_setenv(struct mysh *cmd, char **new_env,
    char **input, char *new_line);
    char **my_unsetenv(struct mysh *cmd, char **env, char **input);
    int pass_space(char *str, int i);
    int my_term(struct mysh *cmd, char **input, char **new_env);
    int alias(mysh_t *cmd, char **input);
    char **my_unsetenv(struct mysh *cmd, char **env, char **input);
    char *inhibitors(char *input, int i);
    int browse_input(char *input, int *i);
    void separator_loop(struct mysh *cmd, int i);
    void separator(struct mysh *cmd, char **input);
    int clean_pipe(struct mysh *cmd, char **input, int i, char *new_line);
    char **change_pipe(struct mysh *cmd, char **input);
    char **start_change_tab(int *i, int j, char **tab, char **cpy_tab);
    int clean_pipe(struct mysh *cmd, char **input, int i, char *new_line);
    int cmd_which(struct mysh *cmd, char **input);
    int cmd_where(struct mysh *cmd, char **input);
    char *concat_path(char *dir_path, char *command);
    int cmd_manage_input(struct mysh *cmd, char **input, char *new_line);
    void check_redirection(struct mysh *cmd, char **input, int i);
    int manage_exec(char **input, char *tmp, struct mysh *cmd, char **path);
    void cmd_execute(struct mysh *cmd, char **input);
    int end_loop(pid_t pid, char *new_line);
    int add_bg_process(pid_t pid, char *new_line);
    int setenv_error_value(struct mysh *cmd, char **input);
#endif /* !MYSH_H_ */
