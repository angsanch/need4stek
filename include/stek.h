/*
** EPITECH PROJECT, 2024
** stek.h
** File description:
** Stek info
*/

#ifndef STEK_H_
    #define STEK_H_
    #include <stdbool.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <string.h>
    #include <math.h>

    #define ABS(n)  (((n) >= 0) ? (n) : -(n))

enum commands_enum {
    START_SIMULATION,
    STOP_SIMULATION,
    CAR_FORWARD,
    CAR_BACKWARDS,
    WHEELS_DIR,
    GET_INFO_LIDAR,
    GET_CURRENT_SPEED,
    GET_CURRENT_WHEELS,
    CYCLE_WAIT,
    GET_CAR_SPEED_MAX,
    GET_CAR_SPEED_MIN,
    GET_INFO_SIMTIME,
};

typedef struct lidar_information {
    float indv[32];
    float maxs[16];
    float right;
    float left;
    float bias;
    float front;
} lidr;

typedef struct control_information {
    float throttle;
    float dir;
} car_con;

typedef struct car_information {
    lidr lidar;
    car_con current;
    car_con intended;
} car;

char **free_string_array(char **result);
char **my_split(char const *s, char c);

void run_command(int command, ...);
void get_lidar(lidr *lidar);

void set_direction(car *c);
void set_throttle(car *c);

#endif
