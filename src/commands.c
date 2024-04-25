/*
** EPITECH PROJECT, 2024
** commands.c
** File description:
** Manage commands
*/

#include "../include/stek.h"

const char *commands[] = {
    "START_SIMULATION",
    "STOP_SIMULATION",
    "CAR_FORWARD",
    "CAR_BACKWARDS",
    "WHEELS_DIR",
    "GET_INFO_LIDAR",
    "GET_CURRENT_SPEED",
    "GET_CURRENT_WHEELS",
    "CYCLE_WAIT",
    "GET_CAR_SPEED_MAX",
    "GET_CAR_SPEED_MIN",
    "GET_INFO_SIMTIME",
};
const size_t command_type_minlen[] = {0, 4, 36, 5, 5};

static void send_command(int command, va_list *l)
{
    switch (command) {
        case CAR_FORWARD:
        case CAR_BACKWARDS:
        case WHEELS_DIR:
            dprintf(1, "%s:%f\n", commands[command], va_arg(*l, double));
            break;
        case CYCLE_WAIT:
            dprintf(1, "%s:%d\n", commands[command], va_arg(*l, int));
            break;
        default:
            dprintf(1, "%s\n", commands[command]);
    }
}

static int get_response_type(int command)
{
    switch (command) {
        case START_SIMULATION:
        case STOP_SIMULATION:
        case CAR_FORWARD:
        case CAR_BACKWARDS:
        case WHEELS_DIR:
            return (1);
        case GET_INFO_LIDAR:
            return (2);
        case GET_CURRENT_SPEED:
        case GET_CURRENT_WHEELS:
        case CYCLE_WAIT:
        case GET_CAR_SPEED_MAX:
        case GET_CAR_SPEED_MIN:
            return (3);
        case GET_INFO_SIMTIME:
            return (4);
        default:
            return (0);
    }
}

static void parse_data(int type, va_list *l, char **line)
{
    long *longs;
    lidr_t *lidar;

    switch (type) {
        case 2:
            lidar = va_arg(*l, lidr_t *);
            for (int i = 0; i < 32; i ++)
                lidar->indv[i] = atof(line[3 + i]);
            get_lidar(lidar);
            break;
        case 3:
            *va_arg(*l, float *) = atof(line[3]);
            break;
        case 4:
            longs = va_arg(*l, long *);
            sscanf(line[3], "[%lds,%ldns]", &longs[0], &longs[1]);
            break;
    }
}

static int parse_line(int command, va_list *l, char **line)
{
    int type = get_response_type(command);
    size_t len;
    size_t min_len = command_type_minlen[type];

    for (len = 0; line[len]; len ++);
    if (len < min_len || type == 0) {
        dprintf(2, "Response format is too short to match its command.\n");
        return (85);
    }
    if (line[2][0] == 'K') {
        dprintf(2, "Command could not be fulfiled. %s %s\n", line[0], line[2]);
        return (85);
    }
    if (strcmp(line[min_len - 1], "No further info\n") != 0)
        for (size_t i = min_len - 1; i < len; i ++)
            dprintf(2, "%s", line[i]);
    parse_data(type, l, line);
    return (strcmp(line[min_len - 1], "Track Cleared") == 0);
}

static int get_response(int command, va_list *l)
{
    char *line = NULL;
    char **parts = NULL;
    ssize_t readed = 0;
    int code = 0;

    readed = getline(&line, (size_t *)&readed, stdin);
    if (readed < 0 || line == NULL) {
        free(line);
        dprintf(2, "%s\n", "Problem reading command response");
        return (85);
    }
    parts = my_split(line, ':');
    free(line);
    if (parts == NULL) {
        dprintf(2, "%s\n", "Error while parsing response");
        return (85);
    }
    code = parse_line(command, l, parts);
    free_string_array(parts);
    return (code);
}

void run_command(int command, ...)
{
    va_list l;
    int status;

    va_start(l, command);
    send_command(command, &l);
    status = get_response(command, &l);
    va_end(l);
    if (status) {
        if (command != STOP_SIMULATION)
            run_command(STOP_SIMULATION);
        exit(status - 1);
    }
}