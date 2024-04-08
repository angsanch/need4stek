/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** If i cant drive a real car...
*/

#include "../include/stek.h"

static void simulate_car(void)
{
    car c;

    memset(&c, 0, sizeof(car));
    while (true) {
        run_command(GET_INFO_LIDAR, &c.lidar);
        c.intended.throttle = c.lidar.front;
        c.intended.dir = c.lidar.bias * (22.5 / c.lidar.front);
        set_direction(&c);
        set_throttle(&c);
    }
}

int main(void)
{
    run_command(START_SIMULATION);
    simulate_car();
    run_command(STOP_SIMULATION);
}
