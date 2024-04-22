/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** If i cant drive a real car...
*/

#include "../include/stek.h"

static void simulate_car(void)
{
    car_t c;

    memset(&c, 0, sizeof(car_t));
    while (true)
        drive(&c);
}

int main(void)
{
    run_command(START_SIMULATION);
    simulate_car();
    run_command(STOP_SIMULATION);
}
