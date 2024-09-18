/*
 * SPI.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Mohamed
 */

#ifndef SPI_H_
#define SPI_H_

#define MASTER 1
#define SLAVE  2

#define SPI_MODE MASTER

void SPI_VidInit(void);
void SPI_U8Transmmit(u8 Copy_Data);
u8 SPI_Receive(void);
u8 SPI_U8TransmmitReceive(u8 Copy_Data);

#endif /* SPI_H_ */
