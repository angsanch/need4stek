/*
** EPITECH PROJECT, 2024
** lidar.c
** File description:
** Control the lidar
*/

#include "../include/stek.h"
#include <math.h>
#include <time.h>

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

void get_lidar(lidr_t *l)
{
    for (int n = 0; n < 32; n ++)
        l->indv[n] = map(l->indv[n], (float[2][2]){{0, 3010}, {0, 100}});
    l->right = l->indv[31];
    l->left = l->indv[0];
    if (l->right > l->left)
        l->bias = l->right / l->left;
    else
        l->bias = - l->left / l->right;
    l->front = average(8, &l->indv[12]);
}
