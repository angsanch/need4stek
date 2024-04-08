/*
** EPITECH PROJECT, 2024
** controls.c
** File description:
** Easily control the car
*/

#include "../include/stek.h"

void set_direction(car *c)
{
    run_command(WHEELS_DIR, (-c->intended.dir / 100));
    c->current.dir = c->intended.dir;
}

void set_throttle(car *c)
{
    float real;

    if (c->intended.throttle > 100)
        real = 100;
    else if (c->intended.throttle < -100)
        real = -100;
    else
        real = c->intended.throttle;
    run_command((real >= 0) ? CAR_FORWARD : CAR_BACKWARDS, (real / 100));
    c->current.throttle = c->intended.throttle;
}
