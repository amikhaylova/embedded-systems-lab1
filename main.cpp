#include "hal.h"

int umain() {
    int k = 0;
    int j = 7;
    int delay = 500;
    int leds_num[] = {GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5,
                      GPIO_PIN_6, GPIO_PIN_8, GPIO_PIN_9,
                      GPIO_PIN_11, GPIO_PIN_12};
    unsigned int sw_num[] = {GPIO_PIN_4, GPIO_PIN_8, GPIO_PIN_10, GPIO_PIN_12};

    while(1) {
        if ((HAL_GPIO_ReadPin(GPIOE, sw_num[0]) == GPIO_PIN_RESET)
            &&(HAL_GPIO_ReadPin(GPIOE, sw_num[1]) == GPIO_PIN_SET)
            &&(HAL_GPIO_ReadPin(GPIOE, sw_num[2]) == GPIO_PIN_RESET)
            &&(HAL_GPIO_ReadPin(GPIOE, sw_num[3]) == GPIO_PIN_SET)
                ){

            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);

                if (k <= 7){
                    for (int z = 0; z <= k; z++){
                        HAL_GPIO_WritePin(GPIOD, leds_num[z], GPIO_PIN_SET);
                    }
                    for (int z = k+1; z <= 7; z++){
                        HAL_GPIO_WritePin(GPIOD, leds_num[z], GPIO_PIN_RESET);
                    }
                }
                if (k > 7){
                    for (int z = j; z <= 7; z++){
                        HAL_GPIO_WritePin(GPIOD, leds_num[z], GPIO_PIN_RESET);
                    }
                    for (int z = 0; z < j; z++){
                        HAL_GPIO_WritePin(GPIOD, leds_num[z], GPIO_PIN_SET);
                    }
                    j = j - 1;
                }
                HAL_Delay(delay);
                k = k + 1;
                if (j == 1){
                    j = 7;
                }
                if (k == 14){
                    k = 0;
                    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
                }

        }else{

            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);

            for(int i = 0; i < 4; i++) {
                GPIO_PinState state = HAL_GPIO_ReadPin(GPIOE, sw_num[i]);
                HAL_GPIO_WritePin(GPIOD, leds_num[i], state);
            }
            for (int i = 4; i < 8; i++){
                HAL_GPIO_WritePin(GPIOD, leds_num[i], GPIO_PIN_RESET);
            }
        }

    }

    return 0;
}