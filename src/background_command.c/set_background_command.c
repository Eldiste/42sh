/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-dorian.senecot
** File description:
** set_background_command
*/

#include "../../include/mysh.h"
#include "../../include/my.h"

typedef struct bg_process_s {
    pid_t pid1;
    char *cmd;
} bg_process_t;

bg_process_t bg_processes[10];
int num_bg_processes = 0;

int set_fg(struct mysh *cmd, char **input, char *new_line)
{
    if (my_strcmp(input[0], "fg") == 0) {
        if (num_bg_processes == 0) {
            printf("fg: No current job.\n");
            return 0;
        }
        pid_t pid = bg_processes[num_bg_processes - 1].pid1;
        char *cmd_str = bg_processes[num_bg_processes - 1].cmd;
        if (my_strlen(cmd_str) > 1 && cmd_str[my_strlen(cmd_str)-2] == ' ' &&
        cmd_str[my_strlen(cmd_str)-1] == '&')
            cmd_str[my_strlen(cmd_str)-2] = '\0';
        printf("%s\n", cmd_str);
        kill(pid, SIGCONT);
        waitpid(pid, NULL, 0);
        num_bg_processes--;
        return 0;
    }
    return -1;
}

void print_command(pid_t pid, int num_bg_processes)
{
    my_putchar('[');
    my_put_nbr(num_bg_processes + 1);
    my_putstr("] ");
    my_put_nbr(pid);
    my_putchar('\n');
}

int launch_process(char **input, char *new_line)
{
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execvp(input[0], input);
        perror(input[0]);
        exit(1);
    } else {
        return pid;
    }
}

int add_bg_process(pid_t pid, char *new_line)
{
    print_command(pid, num_bg_processes);
    bg_processes[num_bg_processes].pid1 = pid;
    bg_processes[num_bg_processes].cmd = my_strdup(new_line);
    num_bg_processes++;
    return 0;
}

int set_jobs_controls(struct mysh *cmd, char **input, char *new_line)
{
    int i = 0;
    while (input[i] != NULL) {
        if (my_strcmp(input[i], "&") == 0) {
            int re = check_pid(input, new_line, i);
            return re;
        }
        i++;
    }
    if (set_fg(cmd, input, new_line) == 0)
        return 0;
    else
        return -1;
}
