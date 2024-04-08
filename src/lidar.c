/*
** EPITECH PROJECT, 2024
** lidar.c
** File description:
** Control the lidar
*/

#include "../include/stek.h"
#include <math.h>

static float average(int n, float *nums)
{
    float sum = 0;

    for (int i = 0; i < n; i ++)
        sum += nums[i];
    return (sum / n);
}

float map(float n, float ranges[2][2])
{
    float in_min = ranges[0][0];
    float in_max = ranges[0][1];
    float out_min = ranges[1][0];
    float out_max = ranges[1][1];

    return (n - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void get_lidar(lidr *l)
{
    float max = 0;
    int index = 0;

    l->front = average(32, l->indv);
    for (int i = 0; i < 32; i ++)
        if (max < l->indv[i]) {
            max = l->indv[i];
            index = i;
        }
    l->sides = map(index, (float[2][2]){{0, 31}, {-100, 100}});
    dprintf(2, "%f %f\n", l->front, l->sides);
}
