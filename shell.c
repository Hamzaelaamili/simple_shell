/**
 * the shell functions
 * Return to 0
 */
int shell(void)
{
    char *input = NULL;
    size_t input_len = 0;
    pid_t child_pid;
    int status;
    char **args;
    char *env[] = {NULL}; /* the empty environmental variable is array */

    while (
        write(STDOUT_FILENO, "$ ", 2) != -1 && 
        getline(&input, &input_len, stdin) != EOF
        )
    {
        fflush(stdout);
        /* Remove the newline character at the end of the input */
        _remove_newline_char(input);

        /* Handle the command line for arguments */
        args = _handle_Command_line_arguments(input);

        if (access(args[0], X_OK) == 0) /* the current directory is  for executables */
        {
            child_pid = _execute_command(args, env);
            wait(&status);
        }
        else if (_strcmp(args[0], "/bin/ls") == 0)
        {
            child_pid = _execute_command(args, env);
            wait(&status);
        }
        else if (_strcmp(input, "exit") == 0) //handle the exit built-in cmmand
        {
            _handle_exit(args, input);
        }
        else if (_strcmp(input, "env") == 0) //handle the env built-in command
        {
            _print_environment_variables();
        }
        else if (_strcmp(args[0], "setenv") == 0) //handle the setenv built-in command
        {
            _setenv_command(args);
        }
        else if (_strcmp(args[0], "unsetenv") == 0) //handle the unsetenv built-in command
        {
            _unsetenv_command(args);
        }
        else if (_strcmp(args[0], "cd") == 0) //handle the cd built-in command
        {
            _cd_command(args);
        }
        else // check in the PATH for the  executables command
        {
           _execute_PATH(args, env);
        }

        _free_args(args);
        free(input);
        input = NULL;
        input_len = 0;
    }

    if (getline(&input, &input_len, stdin) == EOF) //handle the EOF (ctrl + D) command
    {
        // Handle the termination of the shell due to the end of the  file (Ctrl+D) command
        // For the example, print a message and perform the necessary cleanup command
        write(STDOUT_FILENO, "\nShell terminated due to end of file.\n", 40);
    }
    
    free(input);
    return (0);
}

/**
 * _free_args - frees the user command plus arguments
 * @args: pointer to the user command plus the arguments.
 * Return to the void.
 */
void _free_args(char **args)
{
    if (args == NULL)
        return;

    for (int k = 0; k < MAX_ARGUMENTS && args[k] != NULL; k++)
    {
        free(args[k]);
        args[k] = NULL;
    }
    free(args);
    args = NULL;
}
