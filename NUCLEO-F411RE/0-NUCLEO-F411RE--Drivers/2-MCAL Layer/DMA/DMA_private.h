

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H
/*************************************************************************************************************************************/
/********************************************************* Static Functions Prototype ************************************************/
/*************************************************************************************************************************************/

static uint8_t  MDMA_u8ClearAllFlags ( DMAindex_t Copy_DMAindex , StreamIndex_t Copy_StreamIndex  );

/******************************************************************************/
/************************ CR BITS *********************************************/
/******************************************************************************/

#define  DMA_SCR_CHSEL                   25
#define  DMA_SCR_PRIORITY                16
#define  DMA_SCR_MEMORY_SIZE             13
#define  DMA_SCR_PERIPHERAL_SIZE         11
#define  DMA_SCR_MEMORY_INCREMENT        10
#define  DMA_SCR_PERIPHERAL_INCREMENT    9
#define  DMA_SCR_CIRC                    8
#define  DMA_SCR_DIR                     6
#define  DMA_SCR_DMA_ENABLE              0
/******************************************************************************/
/************************ FCR BITS ********************************************/
/******************************************************************************/
#define  DMA_SFCR_FTH                    0
#define  DMA_SFCR_DMDIS                  2
/******************************************************************************/
/************************ MASKS ***********************************************/
/******************************************************************************/
#define  DMA_FLAG_MASK        			 0b111111
#define  DMA_CHSEL_MASK                  0b111
#define  DMA_DIR_MASK                    0b11
#define  DMA_PRIORITY_MASK   			 0b11
#define  DMA_SIZE_MASK        			 0b11
#define  DMA_FTH_MASK                    0b11
#define  DMA_DMDIS_MASK                  0b1
#define  DMA_INCREMENT_MASK  			 0b1
#define  DMA_CIRC_MASK       			 0b1
#define  DMA_STATUS_MASK                 0b1
#define  DMA_FLAG_BIT_ACCESS_4   		 4
#define  DMA_FLAG_BIT_ACCESS_6   		 6
#define  DMA_FLAG_BIT_ACCESS_12   		 12

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/




#endif
