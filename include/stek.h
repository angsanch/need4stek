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
    #include <fcntl.h>
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
    float right;
    float left;
    float bias;
    float front;
} lidr_t;

typedef struct control_information {
    float throttle;
    float dir;
} car_con_t;

typedef struct car_information {
    lidr_t lidar;
    car_con_t current;
    car_con_t intended;
} car_t;

char **free_string_array(char **result);
char **my_split(char const *s, char c);

void run_command(int command, ...);
void get_lidar(lidr_t *lidar);

void set_direction(car_t *c);
void set_throttle(car_t *c);

void drive(car_t *c);

#endif
