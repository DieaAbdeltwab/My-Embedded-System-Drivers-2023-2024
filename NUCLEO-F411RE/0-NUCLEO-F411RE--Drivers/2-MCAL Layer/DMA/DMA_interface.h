
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H
/********************************************************/
/******* @Channel_t  ************************************/
/********************************************************/
typedef enum{
			DMA_1 =0 ,
			DMA_2
}DMAindex_t;
/********************************************************/
/******* @Channel_t  ************************************/
/********************************************************/
typedef enum{
			DMA_STREAM_0 =0 ,
			DMA_STREAM_1    ,
			DMA_STREAM_2    ,
			DMA_STREAM_3    ,
			DMA_STREAM_4    ,
			DMA_STREAM_5    ,
			DMA_STREAM_6    ,
			DMA_STREAM_7
}StreamIndex_t;
/********************************************************/
/******* @Channel_t  ************************************/
/********************************************************/
typedef enum{
			DMA_CHANNEL_0 =0 ,
			DMA_CHANNEL_1    ,
			DMA_CHANNEL_2    ,
			DMA_CHANNEL_3    ,
			DMA_CHANNEL_4    ,
			DMA_CHANNEL_5    ,
			DMA_CHANNEL_6    ,
			DMA_CHANNEL_7
}ChannelIndex_t;
/********************************************************/
/******* @Direction  ************************************/
/********************************************************/
typedef enum{
			DMA_PREI_TO_MEM  =0 ,
			DMA_MEM_TO_PERI     ,
			DMA_MEM_TO_MEM

}Direction_t;
/********************************************************/
/******* @Mode_t  ***************************************/
/********************************************************/
typedef enum{
			 DMA_DISABLE_CIRCULAR =0 ,
			 DMA_ENABLE_CIRCULAR
}DMAMode_t;
/********************************************************/
/******* @Increment_t  **********************************/
/********************************************************/
typedef enum{
			 DMA_INCREMENT_DISABLE =0 ,
			 DMA_INCREMENT_ENABLE
}Increment_t;

/********************************************************/
/******* @DataSize_t  ***********************************/
/********************************************************/
typedef enum{
			DMA_SIZE_BYTE      =0 ,               
			DMA_SIZE_HALF_WORD    , 
			DMA_SIZE_WORD
}DataSize_t;      
/********************************************************/
/******* @Priority_t  ***********************************/
/********************************************************/
typedef enum{
			DMA_LOW        =0 ,               
			DMA_MEDIUM        , 
			DMA_HIGH          ,    
			DMA_VERY_HIGH  
}Priority_t;
/********************************************************/
/******* @InterruptEnable_t  ****************************/
/********************************************************/
typedef enum{
			DMA_DMEIE  =1,
			DMA_TEIE     ,
			DMA_HTIE     ,
			DMA_TCIE
}InterruptEnable_t;
/********************************************************/
/******* @DMAstate_t  ***********************************/
/********************************************************/
typedef enum{
			DMA_DISABLE  =0 ,
			DMA_ENABLE
}DMAstate_t;
/********************************************************/
/******* @Flags_t  **************************************/
/********************************************************/
typedef enum{
			DMA_FEIF  =0 ,
			DMA_DMEIF =2 ,
			DMA_TEIF     ,
			DMA_CHTIF    ,
			DMA_TCIF
}Flags_t;
/********************************************************/
/******* @StramStatus_t  ********************************/
/********************************************************/
typedef enum{
			STRAM_DISABLE =0 ,
			STRAM_ENABLE
}StramStatus_t;

/********************************************************/
/******* @FIFOstatus_t  *********************************/
/********************************************************/
typedef enum{
			FIFO_DISABLE =0 ,
			FIFO_ENABLE
}FIFOstatus_t;
/********************************************************/
/******* @FIFOthreshold_t  ******************************/
/********************************************************/
typedef enum{
			QUARTER_FALL_FIFO    =0 ,
			HALF_FALL_FIFO          ,
			THREE_QUARTER_FALL_FIFO ,
			FALL_FIFO
}FIFOthreshold_t;
/********************************************************/
/******* @DMAconfig_t ***********************************/
/********************************************************/

typedef struct{
			DMAindex_t          DMAindex           ;
			StreamIndex_t       StreamIndex        ;
			ChannelIndex_t      ChannelIndex       ;
			Direction_t         Direction          ;
			DMAMode_t           Mode               ;
			Increment_t         PerINC             ;
			Increment_t         MemINC             ;
			DataSize_t			MemSize            ;
			DataSize_t			PerSize            ;
			Priority_t			StramPriority      ;
}DMAconfig_t;
/*************************************************************************************************************************************/
/********************************************************* Functions Prototype *******************************************************/
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
uint8_t MDMA_u8SetConfiguration ( const DMAconfig_t* DMAconfig );
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
uint8_t  MDMA_u8FIFOcontrol      ( DMAindex_t Copy_DMAindex , StreamIndex_t Copy_StreamIndex , FIFOstatus_t Copy_FIFOstatus , FIFOthreshold_t Copy_FIFOthreshold   );
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
uint8_t  MDMA_u8StramStatus ( DMAindex_t Copy_DMAindex , StreamIndex_t Copy_StreamIndex , StramStatus_t Copy_StramStatus );
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
uint8_t  MDMA_u8InterruptEnable( DMAindex_t Copy_DMAindex , StreamIndex_t Copy_StreamIndex  , InterruptEnable_t Copy_INTSource );
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
uint8_t  MDMA_u8ChannelStart ( DMAindex_t Copy_DMAindex , StreamIndex_t Copy_StreamIndex , uint32_t * Copy_pu32PeripheralAddress , uint32_t * Copy_pu32MemoryAddress , uint16_t Copy_u16BlockLength );
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
uint8_t  MDMA_u8SetCallBack      ( DMAindex_t Copy_DMAindex , StreamIndex_t Copy_StreamIndex , void (* Copy_pfun)(void) );
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/


















#endif
