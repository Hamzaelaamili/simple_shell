/**
 * _Just Print_environment_variables - prints  variables
 * Return = void.
 */
void _print_environment_variables(void)
{
    extern char **Environ;
    int k = 0;

    char **env = environ;
    if (env == NULL)
        return;

    while (env[k] != NULL)
    {
        size_t len = _strlen(env[k]);

        write(STDOUT_FILENO, env[k], len);
        write(STDOUT_FILENO, "\n", 1);
        k++;
    }
}

/**
 * _handle the exit - exit built-in
 * @args: pointers to user command plus arguments.
 * @input: user inputs
 * Return = void.
 */
void _handle_exit(char **args, char *input)
{
    if (args[1] != NULL) /* handle exit arguments */
    {
        int status = _atoi(args[1]);
        _free_args(args);
        free(input);
        exit(status);
    }
    _free_args(args);
    free(input);
    exit(EXIT_SUCCESS);
}

/**
 * _setenv command it handles setenv built-in command
 * @args: pointers to user command plus arguments
 * Return =void.
 */
void _setenv_command(char **args)
{
    if (args[1] == NULL || args[2] == NULL)
    {
        perror("Usage: setenv VARIABLE VALUE");
        return;
    }
    if (setenv(args[1], args[2], 1) != 0)
    {
        perror("Failed to set environment variable");
        return;
    }
}

/**
 * _unsetenv command it handles usetenv built-in command
 * @args: pointer to user command plus arguments.
 * Return: void.
 */
void _unsetenv_command(char **args)
{
    if (args[1] == NULL)
    {
        perror("Usage: unsetenv VARIABLE");
        return;
    }
    if (unsetenv(args[1]) != 0)
    {
        perror("unsetenv failed");
        return;
    }
}

/**
 * cd command it handles cd built-in command
 * @args: pointer to user command + arguments.
 * Return: void.
 */
void _cd_command(char **args)
{
    char *path = args[1];
    char cwd[1024];

    if (path == NULL) /* Cd without arguments it can change to $HOME */
    {
        path = getenv("HOME");
        if (path == NULL)
        {
            perror("HOME environment variable not set");
            return;
        }
    }
    else if (_strcmp(path, "-") == 0) /* cd -, it changes to previous directory */
    {
        path = getenv("OLDPWD");
        if (path == NULL)
        {
            perror("OLDPWD environment variable not set");
            return;
        }
    }

    if (getcwd(cwd, sizeof(cwd)) == NULL) /* store the full-path of cwd in cwd */
    {
        perror("getcwd");
        return;
    }

    if (chdir(path) != 0) /* change to directory specified in the path */
    {
        perror("chdir");
        return;
    }

    /* update the PWD environment variables */
    if (setenv("PWD", getcwd(cwd, sizeof(cwd)), 1) != 0)
    {
        perror("setenv");
        return;
    }
}
