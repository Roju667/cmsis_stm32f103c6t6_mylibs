/*
 * stm32f103xx_usart.h
 *
 *  Created on: Mar 20, 2022
 *      Author: pawel
 */

#ifndef MYDRIVERS_INC_STM32F103XX_USART_H_
#define MYDRIVERS_INC_STM32F103XX_USART_H_

#include "stm32f1xx.h"

// defining those macros will allocate static data
// for purpose of using DMA/IRQ
#define MD_USING_USART1	1U
#define MD_USING_USART2	0U

#if(MD_USING_USART1 || MD_USING_USART2)
#define MD_ENABLE_USART
#endif // (MD_USING_USART1 || MD_USING_USART2)


#ifdef MD_ENABLE_USART

// @usart_word_lenght
typedef enum
{
	USART_WORD_LENGHT_8BIT,
	USART_WORD_LENGHT_9BIT
}usart_word_lenght_t;

// @usart_stop_bits
typedef enum
{
	USART_STOP_BITS_1,
	USART_STOP_BITS_05,
	USART_STOP_BITS_2,
	USART_STOP_BITS_15
}usart_stop_bits_t;

// @usart_status
typedef enum
{
	USART_ERR_NOERR,
	USART_ERR_TIMEOUT_TXE,
	USART_ERR_TIMEOUT_TC
}usart_error_t;

// @usart_handle
typedef struct
{
	USART_TypeDef *p_USARTx;
	uint16_t tx_buffer_len;
	uint16_t tx_buffer_count;

}usart_handle_t;

#if MD_USING_USART1
extern usart_handle_t husart1;
#endif // MD_USING_USART1

#if MD_USING_USART2
extern usart_handle_t husart2;
#endif // MD_USING_USART2

void md_usart_init_handlers(void);
void md_usart_init_clock(usart_handle_t *p_hUSARTx);
void md_usart_init_gpio(usart_handle_t *p_hUSARTx);
void md_usart_set_baud_rate(usart_handle_t *p_hUSARTx,uint32_t baud_rate);
void md_usart_init_basic(usart_handle_t *p_hUSARTx,usart_word_lenght_t word_lenght,usart_stop_bits_t stop_bits, uint32_t baud_rate);


#endif // MD_ENABLE_USART

#endif /* MYDRIVERS_INC_STM32F103XX_USART_H_ */
