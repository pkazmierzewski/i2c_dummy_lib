/**
 * @file    example.c
 * @Author  Paweł Kaźmierzewski <p.kazmierzewski@inteliclinic.com>
 * @date    May, 2017
 * @brief   Brief description
 *
 * Description
 */

#include "drivers.h"
#include <stdio.h>

static void dummy(bool b){
  printf("[%s]: %s\n",__func__, b?"true":"false");
}

int main (void){
  printf("TEST!\n");
  char bufer[] = {0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0,
                  0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0,
                  0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0};

  /* I2C input definition */
  s_i2cInput input = {.addr = 10, .buf = bufer, .len=sizeof(bufer), .reg= 15};


  /* i2c_readData test */
  i2c_readData(&input, dummy);
  printf("\n");

  /* i2c_writeData test */
  i2c_writeData(&input, dummy);
  printf("\n");

  /* i2c_readData_blocking test */
  i2c_readData_blocking(&input);
  printf("\n");

  /* i2c_writeData_blocking test */
  i2c_writeData_blocking(&input);
  return 0;
}



