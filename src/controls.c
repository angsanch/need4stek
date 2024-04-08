/*
** EPITECH PROJECT, 2024
** controls.c
** File description:
** Easily control the car
*/

#include "../include/stek.h"

void set_direction(car *c)
{
    run_command(WHEELS_DIR, (-c->dir / 100));
}

void set_throttle(car *c)
{
    if (c->throttle > 0)
        run_command(CAR_FORWARD, (c->throttle / 100));
    else
        run_command(CAR_BACKWARDS, (-c->throttle / 100));
}
