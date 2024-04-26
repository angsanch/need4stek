/*
** EPITECH PROJECT, 2024
** controls.c
** File description:
** Easily control the car
*/

#include "../include/stek.h"

void set_direction(car_t *c)
{
    float real;

    if (ABS(c->current.dir - c->intended.dir) < 4)
        return;
    real = c->intended.dir * 0.75;
    run_command(WHEELS_DIR, (-real / 100));
    c->current.dir = real;
}

void set_throttle(car_t *c)
{
    float real;

    if (ABS(c->current.throttle - c->intended.throttle) < 5)
        return;
    if (c->intended.throttle > 100)
        real = 100;
    else if (c->intended.throttle < -100)
        real = -100;
    else
        real = c->intended.throttle;
    run_command((real >= 0) ? CAR_FORWARD : CAR_BACKWARDS, (real / 100));
    c->current.throttle = c->intended.throttle;
}
