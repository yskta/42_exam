#include "microshell.h"

//エラーメッセージを出力する関数
int err(char *str) 
{
    while (*str)
        write(2, str++, 1);
    return 1;
}

//カレントディレクトリを変更する関数。簡単。
int cd(char **argv, int i) 
{
    if (i != 2)
        return err("error: cd: bad arguments\n");
    else if (chdir(argv[1]) == -1)
        return err("error: cd: cannot change directory to "), err(argv[1]), err("\n");
    return 0;
}

//コマンドを実行する関数
int exec(char **argv, char **envp, int i) 
{
    int fd[2];
    int status;
    int has_pipe = argv[i] && !strcmp(argv[i], "|");//argv[i]がNULLでなく、argv[i]が"|"なら1を返す

    if (has_pipe && pipe(fd) == -1)
        return err("error: fatal\n");

    int pid = fork();//fork() creates a new process by duplicating the calling process. The new process is referred to as the child process. The calling process is referred to as the parent process.
    if (!pid) //child process
    {
        argv[i] = 0;
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return err("error: fatal\n");
        execve(*argv, argv, envp);
        return err("error: cannot execute "), err(*argv), err("\n");
    }

    waitpid(pid, &status, 0);
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return err("error: fatal\n");
    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **envp) 
{
    int    i = 0;
    int    status = 0;

    if (argc > 1) 
    {
        while (argv[i] && argv[++i])
        {
            argv += i;//argvの先頭アドレスをi分ずらす
            i = 0;//iを初期化
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))//argv[i]がNULLでなく、argv[i]が"|"でも";"でもない間、iをインクリメント
                i++;
            if (!strcmp(*argv, "cd"))//argv[0]が"cd"なら
                status = cd(argv, i);
            else if (i)//iが0でなければ
                status = exec(argv, envp, i);
        }
    }
    return status;
}