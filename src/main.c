/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** If i cant drive a real car...
*/

#include <stdio.h>
#include <unistd.h>

void run_command(char const *str)
{
    char buff[1024];

    dprintf(1, "%s\n", str);
    read(0, buff, 1024);
}

int main(void)
{
    run_command("start_simulation");
    run_command("car_forward:0.5");
    sleep(10);
    run_command("stop_simulation");
}
