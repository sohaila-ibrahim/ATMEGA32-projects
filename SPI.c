/*
 * SPI.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Mohamed
 */

#include<avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI.h"

void SPI_VidInit(void)
{
#if SPI_MODE==MASTER
	/*Select Master*/
	SET_BIT(SPCR,MSTR);

	/*Select ORDER*/
	CLEAR_BIT(SPCR,DORD);

	/*CLK PHASE*/
	SET_BIT(SPCR,CPOL);
	SET_BIT(SPCR,CPHA);

	/*CLK Select*/
	CLEAR_BIT(SPCR,SPR1);
	SET_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPI2X);


#elif SPI_MODE==SLAVE
	/*Select Slave*/
	CLEAR_BIT(SPCR,MSTR);

	/*Select ORDER*/
	CLEAR_BIT(SPCR,DORD);

	/*CLK PHASE*/
	SET_BIT(SPCR,CPOL);
	SET_BIT(SPCR,CPHA);

#endif

	/*Enable*/

	SET_BIT(SPCR,SPE);
}


u8 SPI_U8TransmmitReceive(u8 Copy_Data)
{

	SPDR=Copy_Data;
	while(GET_BIT(SPSR,SPIF)==0);
	return SPDR;
}


void SPI_U8Transmmit(u8 Copy_Data)
{
	SPDR=Copy_Data;
}

u8 SPI_Receive(void)
{
	while(GET_BIT(SPSR,SPIF)==0);
	return SPDR;
}








