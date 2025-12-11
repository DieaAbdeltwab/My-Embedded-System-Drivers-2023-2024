/**
 ******************************************************************************
 * @file           : DMA_program.c
 * @author         : Diea Abdeltwab
 * @layer          : MCAL
 * @brief          : Version 2 For STM32F411RE Drivers
 * @date           : 25/7/2023
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
/******************************************************************************/
/************************ LIB Layer *******************************************/
/******************************************************************************/
#include <stdint.h>
#include "ERROR_STATE.h"
#include "BIT_MATH.h"
#include "STM32F411xx.h"
/******************************************************************************/
/************************ MCAL Layer ******************************************/
/******************************************************************************/
#include"DMA_INTERFACE.h"
#include"DMA_private.h"
#include"DMA_config.h"
/******************************************************************************/
/************************ Global **********************************************/
/******************************************************************************/
static void ( *DMA_ApfStramCallBack[DMA_NUMBERS][DMA_STREAM_7+1] )( void )= {{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}
		                                           	   	   	   	   	   	   	,{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}};
/*************************************************************************************************************************************/
/********************************************************* Functions implementations *************************************************/
/*************************************************************************************************************************************/
/**
 ******************************************************************************
 * @fn             : MDMA_u8SetConfiguration
 * @brief          : initialization Value of DMA Configuration
 * @param[in]      : DMAconfig  --> get option from @PinConfig_t  struct
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t MDMA_u8SetConfiguration ( const DMAconfig_t* DMAconfig )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if (  DMAconfig != NULL )
	{
		/********************************** Disable DMA ***********************************************************/
		CLR_BIT( DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR , DMA_SCR_DMA_ENABLE );
		while( 1 == GET_BIT(  DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR , DMA_SCR_DMA_ENABLE ) );
		MDMA_u8ClearAllFlags(DMAconfig->DMAindex,DMAconfig->StreamIndex);
		/********************************** CHANNEL PRIORITY *****************************************************/
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR &=~ (DMA_PRIORITY_MASK        << (DMA_SCR_PRIORITY));
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR |=  (DMAconfig->StramPriority << (DMA_SCR_PRIORITY));
		/********************************** MEMORY SIZE **********************************************************/
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR &=~ (DMA_SIZE_MASK      << (DMA_SCR_MEMORY_SIZE));
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR |=  (DMAconfig->PerSize << (DMA_SCR_MEMORY_SIZE));
		/********************************** PERIPHERAL SIZE ******************************************************/
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR &=~ (DMA_SIZE_MASK      << (DMA_SCR_PERIPHERAL_SIZE));
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR |=  (DMAconfig->MemSize << (DMA_SCR_PERIPHERAL_SIZE));
		/********************************** MEMORY Increment ******************************************************/
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR &=~ (DMA_INCREMENT_MASK << (DMA_SCR_MEMORY_INCREMENT));
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR |=  (DMAconfig->MemINC  << (DMA_SCR_MEMORY_INCREMENT));
		/********************************** PERIPHERAL Increment **************************************************/
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR &=~ (DMA_INCREMENT_MASK << (DMA_SCR_PERIPHERAL_INCREMENT));
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR |=  (DMAconfig->PerINC  << (DMA_SCR_PERIPHERAL_INCREMENT));
		/********************************** DMA MODE ***************************************************************/
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR &=~ (DMA_CIRC_MASK   << (DMA_SCR_CIRC));
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR |=  (DMAconfig->Mode << (DMA_SCR_CIRC));
		/********************************** Direction **************************************************************/
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR  &=~ (DMA_DIR_MASK         << ( ( DMA_SCR_DIR )) ) ;
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR  |=  (DMAconfig->Direction << ( ( DMA_SCR_DIR )) ) ;
		/********************************** Channel **************************************************************/
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR  &=~ (DMA_CHSEL_MASK          << ( ( DMA_SCR_CHSEL )) ) ;
		DMA_Index[DMAconfig->DMAindex]->STREAM[DMAconfig->StreamIndex].CR  |=  (DMAconfig->ChannelIndex << ( ( DMA_SCR_CHSEL )) ) ;
		/***********************************************************************************************************/
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK ;
	}
	return Local_u8ErrorState ;

}
/**
 ******************************************************************************
 * @fn             : MDMA_u8StramStatus
 * @brief          : Enable or Disable DMA
 * @param[in]      : Copy_DMAindex    --> get option from @DMAindex_t    enum
 * @param[in]      : Copy_StreamIndex --> get option from @StreamIndex_t enum
 * @param[in]      : Copy_FIFOstatus --> get option from @FIFOstatus_t enum
 * @param[in]      : Copy_FIFOthreshold --> get option from @FIFOthreshold_t enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t  MDMA_u8FIFOcontrol      ( DMAindex_t Copy_DMAindex , StreamIndex_t Copy_StreamIndex , FIFOstatus_t Copy_FIFOstatus , FIFOthreshold_t Copy_FIFOthreshold   )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_DMAindex<= DMA_2 && Copy_StreamIndex <= DMA_STREAM_7 && Copy_FIFOstatus <= FIFO_ENABLE && Copy_FIFOthreshold <= FALL_FIFO )
	{
		DMA_Index[Copy_DMAindex]->STREAM[Copy_StreamIndex].FCR  &=~ (DMA_FTH_MASK       << ( ( DMA_SFCR_FTH )) ) ;
		DMA_Index[Copy_DMAindex]->STREAM[Copy_StreamIndex].FCR  |=  (Copy_FIFOthreshold << ( ( DMA_SFCR_FTH )) ) ;

		DMA_Index[Copy_DMAindex]->STREAM[Copy_StreamIndex].FCR  &=~ (DMA_DMDIS_MASK  << ( ( DMA_SFCR_DMDIS )) ) ;
		DMA_Index[Copy_DMAindex]->STREAM[Copy_StreamIndex].FCR  |=  (Copy_FIFOstatus << ( ( DMA_SFCR_DMDIS )) ) ;
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK ;
	}
	return Local_u8ErrorState ;
}
/**
 ******************************************************************************
 * @fn             : MDMA_u8StramStatus
 * @brief          : Enable or Disable DMA
 * @param[in]      : Copy_DMAindex    --> get option from @DMAindex_t    enum
 * @param[in]      : Copy_StreamIndex --> get option from @StreamIndex_t enum
 * @param[in]      : Copy_StramStatus --> get option from @StramStatus_t enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t  MDMA_u8StramStatus ( DMAindex_t Copy_DMAindex , StreamIndex_t Copy_StreamIndex , StramStatus_t Copy_StramStatus )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_DMAindex<= DMA_2 && Copy_StreamIndex <= DMA_STREAM_7 && Copy_StramStatus<=STRAM_ENABLE)
	{
		MDMA_u8ClearAllFlags(Copy_DMAindex,Copy_StreamIndex);
		DMA_Index[Copy_DMAindex]->STREAM[Copy_StreamIndex].CR  &=~ (DMA_STATUS_MASK  << ( ( DMA_SCR_DMA_ENABLE )) ) ;
		DMA_Index[Copy_DMAindex]->STREAM[Copy_StreamIndex].CR  |=  (Copy_StramStatus << ( ( DMA_SCR_DMA_ENABLE )) ) ;
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK ;
	}
	return Local_u8ErrorState ;

}
/**
 ******************************************************************************
 * @fn             : MDMA_u8InterruptEnable
 * @brief          : Interrupt Enable
 * @param[in]      : Copy_DMAindex    --> get option from @DMAindex_t    enum
 * @param[in]      : Copy_StreamIndex --> get option from @StreamIndex_t enum
 * @param[in]      : Copy_INTSource  --> get option from @InterruptEnable_t  enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t  MDMA_u8InterruptEnable( DMAindex_t Copy_DMAindex , StreamIndex_t Copy_StreamIndex  , InterruptEnable_t Copy_INTSource )
{

	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_DMAindex<= DMA_2 && Copy_StreamIndex <= DMA_STREAM_7  &&  Copy_INTSource <= DMA_TCIE )
	{
	     SET_BIT( DMA_Index[Copy_DMAindex]->STREAM[ Copy_StreamIndex ].CR , Copy_INTSource );
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK ;
	}
	return Local_u8ErrorState ;

}
/**
 ******************************************************************************
 * @fn             : MDMA_u8ChannelStart
 * @brief          : Channel Start
 * @param[in]      : Copy_DMAindex    --> get option from @DMAindex_t    enum
 * @param[in]      : Copy_StreamIndex --> get option from @StreamIndex_t enum
 * @param[in]      : Copy_pu32PeripheralAddress --> Set Peripheral Address
 * @param[in]      : Copy_pu32PeripheralAddress --> Set Memory Address
 * @param[in]      : Copy_pu32PeripheralAddress --> Set Block Length
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t  MDMA_u8ChannelStart ( DMAindex_t Copy_DMAindex , StreamIndex_t Copy_StreamIndex , uint32_t * Copy_pu32PeripheralAddress , uint32_t * Copy_pu32MemoryAddress , uint16_t Copy_u16BlockLength )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_DMAindex<= DMA_2 && Copy_StreamIndex <= DMA_STREAM_7 &&  Copy_pu32PeripheralAddress != NULL &&  Copy_pu32MemoryAddress != NULL  )
	{
		CLR_BIT( DMA_Index[Copy_DMAindex]->STREAM[ Copy_StreamIndex ].CR , DMA_SCR_DMA_ENABLE );

		DMA_Index[Copy_DMAindex]->STREAM[ Copy_StreamIndex ].PAR   =  (uint32_t)Copy_pu32PeripheralAddress ;
		DMA_Index[Copy_DMAindex]->STREAM[ Copy_StreamIndex ].M0AR  =  (uint32_t)Copy_pu32MemoryAddress     ;
		DMA_Index[Copy_DMAindex]->STREAM[ Copy_StreamIndex ].NDTR  =            Copy_u16BlockLength        ;
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK ;
	}
	return Local_u8ErrorState ;
}
/**
 ******************************************************************************
 * @fn             : MDMA_u8SetCallBack
 * @brief          : Set Call Back
 * @param[in]      : Copy_DMAindex    --> get option from @DMAindex_t    enum
 * @param[in]      : Copy_StreamIndex --> get option from @StreamIndex_t enum
 * @param[in]      : Copy_pfun --> Set Call Back Function Address
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t  MDMA_u8SetCallBack      ( DMAindex_t Copy_DMAindex , StreamIndex_t Copy_StreamIndex , void (* Copy_pfun)(void) )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_DMAindex<= DMA_2 && Copy_StreamIndex <= DMA_STREAM_7 && Copy_pfun != NULL )
	{
		DMA_ApfStramCallBack[Copy_DMAindex][Copy_StreamIndex] = Copy_pfun;
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK ;
	}
	return Local_u8ErrorState ;
}
/*************************************************************************************************************************************/
/********************************************************* Static Functions implementations ******************************************/
/*************************************************************************************************************************************/
/**
 ******************************************************************************
 * @fn             : MDMA_u8ClearAllFlags
 * @brief          : Clear Flags
 * @param[in]      : Copy_DMAindex    --> get option from @DMAindex_t    enum
 * @param[in]      : Copy_StreamIndex --> get option from @StreamIndex_t enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
static uint8_t  MDMA_u8ClearAllFlags ( DMAindex_t Copy_DMAindex , StreamIndex_t Copy_StreamIndex  )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_StreamIndex <= DMA_STREAM_7  )
	{
		uint8_t Local_u8Reg =   Copy_StreamIndex / DMA_FLAG_BIT_ACCESS_4   ;
		uint8_t Local_u8Bit = ( Copy_StreamIndex % DMA_FLAG_BIT_ACCESS_4 ) * DMA_FLAG_BIT_ACCESS_6   ;
		if (Local_u8Bit >= DMA_FLAG_BIT_ACCESS_12 )
		{
			Local_u8Bit += DMA_FLAG_BIT_ACCESS_4 ;
		}
		DMA_Index[Copy_DMAindex]->IFCR[Local_u8Reg]  &=~ (DMA_FLAG_MASK << ( ( Local_u8Bit )) ) ;
		DMA_Index[Copy_DMAindex]->IFCR[Local_u8Reg]  |=  (DMA_FLAG_MASK << ( ( Local_u8Bit )) ) ;

	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK ;
	}
	return Local_u8ErrorState ;

}
/*************************************************************************************************************************************/
/********************************************************* Handlers implementations **************************************************/
/*************************************************************************************************************************************/
void DMA1_Stream0_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_1,DMA_STREAM_0);
	if ( DMA_ApfStramCallBack[DMA_1][DMA_STREAM_0] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_1][DMA_STREAM_0]();
	}
}
void DMA1_Stream1_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_1,DMA_STREAM_1);
	if ( DMA_ApfStramCallBack[DMA_1][DMA_STREAM_1] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_1][DMA_STREAM_1]();
	}
}
void DMA1_Stream2_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_1,DMA_STREAM_2);
	if ( DMA_ApfStramCallBack[DMA_1][DMA_STREAM_2] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_1][DMA_STREAM_2]();
	}
}
void DMA1_Stream3_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_1,DMA_STREAM_3);
	if ( DMA_ApfStramCallBack[DMA_1][DMA_STREAM_3] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_1][DMA_STREAM_3]();
	}
}
void DMA1_Stream4_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_1,DMA_STREAM_4);
	if ( DMA_ApfStramCallBack[DMA_1][DMA_STREAM_4] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_1][DMA_STREAM_4]();
	}
}
void DMA1_Stream5_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_1,DMA_STREAM_5);
	if ( DMA_ApfStramCallBack[DMA_1][DMA_STREAM_5] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_1][DMA_STREAM_5]();
	}
}
void DMA1_Stream6_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_1,DMA_STREAM_6);
	if ( DMA_ApfStramCallBack[DMA_1][DMA_STREAM_6] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_1][DMA_STREAM_6]();
	}
}
void DMA1_Stream7_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_1,DMA_STREAM_7);
	if ( DMA_ApfStramCallBack[DMA_1][DMA_STREAM_7] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_1][DMA_STREAM_7]();
	}
}

void DMA2_Stream0_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_2,DMA_STREAM_0);
	if ( DMA_ApfStramCallBack[DMA_2][DMA_STREAM_0] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_2][DMA_STREAM_0]();
	}
}
void DMA2_Stream1_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_2,DMA_STREAM_1);
	if ( DMA_ApfStramCallBack[DMA_2][DMA_STREAM_1] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_2][DMA_STREAM_1]();
	}
}
void DMA2_Stream2_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_2,DMA_STREAM_2);
	if ( DMA_ApfStramCallBack[DMA_2][DMA_STREAM_2] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_2][DMA_STREAM_2]();
	}
}
void DMA2_Stream3_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_2,DMA_STREAM_3);
	if ( DMA_ApfStramCallBack[DMA_2][DMA_STREAM_3] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_2][DMA_STREAM_3]();
	}
}
void DMA2_Stream4_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_2,DMA_STREAM_4);
	if ( DMA_ApfStramCallBack[DMA_2][DMA_STREAM_4] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_2][DMA_STREAM_4]();
	}
}
void DMA2_Stream5_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_2,DMA_STREAM_5);
	if ( DMA_ApfStramCallBack[DMA_2][DMA_STREAM_5] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_2][DMA_STREAM_5]();
	}
}
void DMA2_Stream6_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_2,DMA_STREAM_6);
	if ( DMA_ApfStramCallBack[DMA_2][DMA_STREAM_6] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_2][DMA_STREAM_6]();
	}
}
void DMA2_Stream7_IRQHandler(void)
{
	MDMA_u8ClearAllFlags(DMA_2,DMA_STREAM_7);
	if ( DMA_ApfStramCallBack[DMA_2][DMA_STREAM_7] != NULL )
	{
		 DMA_ApfStramCallBack[DMA_2][DMA_STREAM_7]();
	}
}

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
