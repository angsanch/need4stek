/*
** EPITECH PROJECT, 2024
** drive.c
** File description:
** %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
** %%#*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++%%%%
** %%#*+************************###########%%%##*************************++%%%%
** %%%*+*******+*****+**+**+****###########***##*********+*******+**+**+*++%%%%
** %%%#+********************##%##%##%##%##%##%##%#%%##*******************++%%%%
** %%#*+*****************#####%########################******************++%%%%
** %%#*+*****************##############################**##**************++%%%%
** %%##+***************#%##%##%##%##%##%##%##%##%#%%##%#%****************++%%%%
** %%#*+*******+*******#######################*******+***********+*****+*++%%%%
** %%#*+*************#########%##%#####%####********+++++****************++%%%%
** %%#*+*************#######################********+++++++**************++%%%%
** %%#*+*******+*****#######################*+******+++++++******+**+**+*++%%%%
** %%#*+***********##%#####%##%##%##%##%##%#********+++++++**************++%%%%
** %%#*+***********###########%#############********+++++++**************++%%%%
** %%#*+***********#########################********+++++++**************++%%%%
** %%##+***********##%##%##%##%##%##%##%##%##%##%#**+++++++**************++%%%%
** %%#*+*******+***########################**+**##***+*++++******+*****+*++%%%%
** %%#*+*************#########%##%#####%#**%##++####***##++**************++%%%%
** %%#*+*************####################**###**####**#**++**************++%%%%
** %%%*+*******+*****####################*+*****####**#**++******+**+**+*++%%%%
** %%%#+*************%#####%##%##%##%##%#*******%#%%**%******************++%%%%
** %%#*+*************#########%##########*****#######*+++****************++%%%%
** %%#*+***************##################*****#######*+++****************++%%%%
** %%##+***************#%##%##%##%##%##%#****%##%#%%##*++****************++%%%%
** %%#*+*******+*******##################*+**+#######************+*****+*++%%%%
** %%#*+***********###########%##%#####%#*******####+++******##+*********++%%%%
** %%#*+********#########################***########**+**###########**++*++%%%%
** %%#*+********#########################*+**#######**+**###########*****++%%%%
** %%#*+******##%#%##%#####%##%##%##%##%#****%##%#%%##+#%%#%##%##%##%###*++%%%%
** %%#*+******################%######################**#############%%###++%%%%
** %%#*+****######################################**++*#########**######%*+%%%%
** %%##+#%%#%###%#%##%##%##%##%##%##%##%##%##%##%#++++*#%%%%##%##%##%##%#++%%%%
** %%#*+##########################################***+*******##%########%++%%%%
** %%#*+######################**#%#####%##########*************#####%###%*+%%%%
** %%#*+######################****#########*******************##########%*+%%%%
** %%#*+#######**********#####****#%%####****+*******+***+******#######*%++%%%%
** %%#*+#%%#%###*********##%##%#*##%%##%#***********************#%##%##%%++%%%%
** %%#*+####**###******++*####%###*******++#************************%####++%%%%
** %%#*+**####**#*******++**#######**##**++###**##++*********************++%%%%
** %%##+#%%#*****#%******+****%##%*#%**%#**#**##%#%%##+******************++%%%%
** %%%#+##**##*+*##*****+**+****###*+##################**********+*****+*++%%%%
** %%#*+####**##******************#******#######**++++*####**************++%%%%
** %%#*+*****************+*************##**#######**+++######************++%%%%
** %%#*+*******+*****+**++*+**+**++*+*********####**+++**********+**+**+*++%%%%
** %%#*+*********************************#%***##%#%%**+******************++%%%%
** %%#*+***************************####**#####**#####**++****************++%%%%
** %%#*+*****************************##****############++++*************+++%%%%
** %%##+******##*****%#************#%##****##%##%#%%##%++++**************++%%%%
** %%#*+##****###**######**+****##*##**+*##############++++++****+*****+*++%%%%
** %%#*+%%##**###########*********###****##############**+++++*#*********++%%%%
** %%#*+########%########################################*****##********#++%%%%
** %%#*+#######**########################################*****##**%%****%++%%%%
** %%#*+#%%#%###%#%##%#####%##%##%##%##%##%##%##%#%%##%#%%#%##%##%%%%##%%++%%%%
** %%%#+#######**********###*********##****##***####***##*********##%###%*+%%%%
** %%#*+#######**####*****##****###**##****##***####***##****#####%%#####++%%%%
** %%##+#%%#%##**######***##*********##****###**####**###*********##%##%#++%%%%
** %%#*+#######**######*+*##*******####+**+###***##***###********+##%%##%++%%%%
** %%#*+#######**######***##****##*####****###********###****#######%###%*+%%%%
** %%#*+#######**#####***###****##***##****#####****#####*********##%%###++%%%%
** %%%*+#######******+***###**+*##+*+##+**+#####****#####+*******+##**##%++%%%%
** %%%#+#%%#%###*******#####****##***##****##%##****##%#%*********##%##%%++%%%%
** %%#*+##%%%%##%%%###########%#############%%#########%%%%%%#%%##%%%#%%%*+%%%%
** %%%#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++%%%%
** %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include "../include/stek.h"
#include <math.h>

static void throttle(car_t *c)
{
    c->intended.throttle = 10;
    if (c->lidar.front > 12.5)
        c->intended.throttle = 20;
    if (c->lidar.front > 20)
        c->intended.throttle = 40;
    if (c->lidar.front > 35)
        c->intended.throttle = 50;
    if (c->lidar.front > 50)
        c->intended.throttle = 80;
    if (c->lidar.front > 65)
        c->intended.throttle = 100;
}

static void direction(car_t *c)
{
    c->intended.dir = 50;
    if (c->lidar.front > 5)
        c->intended.dir = 30;
    if (c->lidar.front > 10)
        c->intended.dir = 20;
    if (c->lidar.front > 15)
        c->intended.dir = 10;
    if (c->lidar.front > 30)
        c->intended.dir = 5;
    if (c->lidar.front > 50)
        c->intended.dir = 0.5;
    if (c->lidar.bias < 0)
        c->intended.dir *= -1;
}

void drive(car_t *c)
{
    run_command(GET_INFO_LIDAR, &c->lidar);
    throttle(c);
    direction(c);
    set_direction(c);
    set_throttle(c);
}