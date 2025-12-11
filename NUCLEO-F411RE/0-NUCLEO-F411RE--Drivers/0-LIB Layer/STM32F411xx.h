/**
 ******************************************************************************
 * @file           : stm32f103xx.h
 * @author         : Diea Abdeltwab
 * @brief          : Version 1 For STM32F411RE Drivers
 * @date           : 25/3/2023
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
#ifndef STM32F446re_h
#define STM32F446re_h
/************************************************************************************************/
/******************************** RCC Registers *************************************************/
/************************************************************************************************/
#define RCC_BASE_ADDRESS                              0x40023800UL

typedef struct
{
	volatile uint32_t CR; 			 	 /*RCC clock control register*/
	volatile uint32_t PLLCFGR;           /*RCC PLL configuration register*/
	volatile uint32_t CFGR;              /*RCC clock configuration register*/
	volatile uint32_t CIR;               /*RCC clock interrupt register*/
	volatile uint32_t AHB1RSTR;          /*RCC AHB1 peripheral reset register*/
	volatile uint32_t AHB2RSTR;          /*RCC AHB2 peripheral reset register*/
	volatile uint32_t Reserved[2];          /*Reserved*/
	volatile uint32_t APB1RSTR;          /*RCC APB1 peripheral reset register*/
	volatile uint32_t APB2RSTR;          /*RCC APB2 peripheral reset register*/
	volatile uint32_t Reserved1[2];      /*Reserved*/
	volatile uint32_t AHB1ENR;           /*RCC AHB1 peripheral clock enable register*/
	volatile uint32_t AHB2ENR;           /*RCC AHB2 peripheral clock enable register*/
	volatile uint32_t Reserved2[2];         /*Reserved*/
	volatile uint32_t APB1ENR;           /*RCC APB1 peripheral clock enable register*/
	volatile uint32_t APB2ENR;           /*RCC APB2 peripheral clock enable register*/
	volatile uint32_t Reserved3[2];      /*Reserved*/
	volatile uint32_t AHB1LPENR;         /*RCC AHB1 peripheral clock enable in low power mode register*/
	volatile uint32_t AHB2LPENR;         /*RCC AHB2 peripheral clock enable in low power mode register*/
	volatile uint32_t Reserved4[2];         /*Reserved*/
	volatile uint32_t APB1LPENR;         /*RCC APB1 peripheral clock enable in low power mode register*/
	volatile uint32_t APB2LPENR;         /*RCC APB2 peripheral clock enable in low power mode register*/
	volatile uint32_t Reserved5[2];      /*Reserved*/
	volatile uint32_t BDCR;              /*RCC Backup domain control register*/
	volatile uint32_t CSR;               /*RCC clock control & status register*/
	volatile uint32_t Reserved6[2];      /*Reserved*/
	volatile uint32_t SSCGR;             /*RCC spread spectrum clock generation register*/
	volatile uint32_t PLLI2SCFGR;        /*RCC PLLI2S configuration register*/
	volatile uint32_t DCKCFGR;           /*RCC dedicated clock configuration register*/

}RCC_REG;

#define RCC                              ((RCC_REG*)RCC_BASE_ADDRESS)

/************************************************************************************************/
/************************************* GPIO Registers *******************************************/
/************************************************************************************************/
#define GPIOA_BASE_ADDRESS		0X40020000UL
#define GPIOB_BASE_ADDRESS		0X40020400UL
#define GPIOC_BASE_ADDRESS		0X40020800UL
#define GPIOD_BASE_ADDRESS		0X40020C00UL
#define GPIOE_BASE_ADDRESS		0X40021000UL
#define GPIOF_BASE_ADDRESS		0X40021400UL
#define GPIOG_BASE_ADDRESS		0X40021800UL
#define GPIOH_BASE_ADDRESS		0X40021C00UL

typedef struct
{
	volatile uint32_t MODER;     		/*GPIO port mode register*/
	volatile uint32_t OTYPER;    		/*GPIO port output type register*/
	volatile uint32_t OSPEEDER;  		/*GPIO port output speed register*/
	volatile uint32_t PUPDR;     		/*GPIO port pull-up/pull-down register*/
	volatile uint32_t IDR;       		/*GPIO port input data register*/
	volatile uint32_t ODR;       		/*GPIO port output data register*/
	volatile uint32_t BSRR;      		/*GPIO port bit set/reset register*/
	volatile uint32_t LCKR;      		/*GPIO port configuration lock register*/
	volatile uint32_t AFR[2];    		/*AFR[0] : GPIO alternate function low register
									     *AFR[1] : GPIO alternate function high register*/
}GPIO_REG;

#define GPIOA			                ((GPIO_REG*)GPIOA_BASE_ADDRESS)
#define GPIOB							((GPIO_REG*)GPIOB_BASE_ADDRESS)
#define GPIOC							((GPIO_REG*)GPIOC_BASE_ADDRESS)
#define GPIOD							((GPIO_REG*)GPIOD_BASE_ADDRESS)
#define GPIOE							((GPIO_REG*)GPIOE_BASE_ADDRESS)
#define GPIOF							((GPIO_REG*)GPIOF_BASE_ADDRESS)
#define GPIOG							((GPIO_REG*)GPIOG_BASE_ADDRESS)
#define GPIOH							((GPIO_REG*)GPIOH_BASE_ADDRESS)
/************************************************************************************************/
/********************************* SYSTICK Registers ********************************************/
/************************************************************************************************/
#define STK_BASE_ADDRESS                                  0xE000E010UL


typedef struct
{
	volatile uint32_t CTRL;
	volatile uint32_t LOAD;
	volatile uint32_t VAL;
	volatile uint32_t CALIB;
}STK_REG;

#define STK                                  ((STK_REG*)STK_BASE_ADDRESS)

/************************************************************************************************/
/******************************** NVIC Registers ************************************************/
/************************************************************************************************/
#define NVIC_u32_BASE_ADDRESS                               0xE000E100UL

typedef struct
{
	volatile uint32_t ISER[8];		/*Interrupt set-enable register*/
	uint32_t Reserved1[24];
	volatile uint32_t ICER[8];		/*Interrupt clear-enable register*/
	uint32_t Reserved[24];
	volatile uint32_t ISPR[8];		/*Interrupt set-pending register*/
	uint32_t Reserved2[24];
	volatile uint32_t ICPR[8];		/*Interrupt clear-pending register*/
	uint32_t Reserved4[24];
	volatile uint32_t IABR[8];		/*Interrupt active bit register*/
	uint32_t Reserved3[32];
	volatile uint8_t IPR[240];		/*Interrupt priority register*/
}NVIC_REG;

#define NVIC                                  ((NVIC_REG*)NVIC_u32_BASE_ADDRESS)
/************************************************************************************************/
/******************************** SCB Registers *************************************************/
/************************************************************************************************/
//#define SCB_u32_BASE_ADDRESS                               0xE000E008UL
#define SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address */

#define SCB_BASE            (SCS_BASE +  0x0D00UL)                    /*!< System Control Block Base Address */


typedef struct{
	  volatile  uint32_t CPUID;                   /*!< Offset: 0x000 (R/ )  CPUID Base Register                                   */
	  volatile uint32_t ICSR;                    /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register                  */
	  volatile uint32_t VTOR;                    /*!< Offset: 0x008 (R/W)  Vector Table Offset Register                          */
	  volatile uint32_t AIRCR;                   /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register      */
	  volatile uint32_t SCR;                     /*!< Offset: 0x010 (R/W)  System Control Register                               */
	  volatile uint32_t CCR;                     /*!< Offset: 0x014 (R/W)  Configuration Control Register                        */
	  volatile uint8_t  SHP[12];                 /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
	  volatile uint32_t SHCSR;                   /*!< Offset: 0x024 (R/W)  System Handler Control and State Register             */
	  volatile uint32_t CFSR;                    /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register                    */
	  volatile uint32_t HFSR;                    /*!< Offset: 0x02C (R/W)  HardFault Status Register                             */
	  volatile uint32_t DFSR;                    /*!< Offset: 0x030 (R/W)  Debug Fault Status Register                           */
	  volatile uint32_t MMFAR;                   /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register                      */
	  volatile uint32_t BFAR;                    /*!< Offset: 0x038 (R/W)  BusFault Address Register                             */
	  volatile uint32_t AFSR;                    /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register                       */
	  volatile  uint32_t PFR[2];                  /*!< Offset: 0x040 (R/ )  Processor Feature Register                            */
	  volatile  uint32_t DFR;                     /*!< Offset: 0x048 (R/ )  Debug Feature Register                                */
	  volatile  uint32_t ADR;                     /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register                            */
	  volatile  uint32_t MMFR[4];                 /*!< Offset: 0x050 (R/ )  Memory Model Feature Register                         */
	  volatile  uint32_t ISAR[5];                 /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register                   */
	       uint32_t RESERVED0[5];
	  volatile uint32_t CPACR;                   /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register                   */

}SCB_Type;

#define SCB                 ((SCB_Type       *)     SCB_BASE      )   /*!< SCB configuration struct */
/************************************************************************************************/
/********************************* SYSCFG Registers *********************************************/
/************************************************************************************************/
#define SYSCFG_BASE_ADDRESS		        0x40013800UL

typedef struct
{
	volatile uint32_t MEMRMP;			/*SYSCFG memory remap register*/
	volatile uint32_t PMC;				/*SYSCFG peripheral mode configuration register*/
	volatile uint32_t EXTICR[4];	    /*SYSCFG external interrupt configuration registers*/
	uint32_t Reserved[2];
	volatile uint32_t CMPCR;			/*Compensation cell control register*/
	uint32_t Reserved2[2];
	volatile uint32_t CFGR;				/*SYSCFG configuration register*/

}SYSCFG_RegDef_t;

#define SYSCFG					((SYSCFG_RegDef_t*)SYSCFG_BASE_ADDRESS)

/************************************************************************************************/
/********************************* EXTI Registers ***********************************************/
/************************************************************************************************/
#define EXTI_u32_BASE_ADDRESS                0x40013C00U

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_REG;

#define EXTI                                  ((EXTI_REG*)EXTI_u32_BASE_ADDRESS)

/************************************************************************************************/
/******************************** USART1 Registers **********************************************/
/************************************************************************************************/
#define USART1_u32_BASE_ADDRESS                                0x40011000U
#define USART2_u32_BASE_ADDRESS                                0x40004400U
#define USART3_u32_BASE_ADDRESS                                0x40004800U
#define  UART4_u32_BASE_ADDRESS                                0x40004C00U
#define  UART5_u32_BASE_ADDRESS                                0x40005000U
#define USART6_u32_BASE_ADDRESS                                0x40011400U
 typedef	struct
{
	volatile uint32_t SR    ;
	volatile uint32_t DR    ;
	volatile uint32_t BRR   ;
	volatile uint32_t CR1   ;
	volatile uint32_t CR2   ;
	volatile uint32_t CR3   ;
	volatile uint32_t GTPR  ;

} USART_REG ;

#define  USART1                     ( (  USART_REG *) USART1_u32_BASE_ADDRESS )
#define  USART2                     ( (  USART_REG *) USART2_u32_BASE_ADDRESS )
#define  USART3                     ( (  USART_REG *) USART3_u32_BASE_ADDRESS )
#define   UART4                     ( (  USART_REG *) UART4_u32_BASE_ADDRESS  )
#define   UART5                     ( (  USART_REG *) UART5_u32_BASE_ADDRESS  )
#define  USART6                     ( (  USART_REG *) USART6_u32_BASE_ADDRESS )

/************************************************************************************************/
/******************************** SPI Registers *************************************************/
/************************************************************************************************/
#define SPI1_u32_BASE_ADDRESS                                0x40013000U
#define SPI2_u32_BASE_ADDRESS                                0x40003800U
#define SPI3_u32_BASE_ADDRESS                                0x40003C00U
#define SPI4_u32_BASE_ADDRESS                                0x40013400U

 typedef	struct
{
	volatile uint32_t CR1     ;
	volatile uint32_t CR2     ;
	volatile uint32_t SR      ;
	volatile uint32_t DR      ;
	volatile uint32_t CRCPR   ;
	volatile uint32_t RXCRCR  ;
	volatile uint32_t TXCRCR  ;
	volatile uint32_t I2SCFGR ;
	volatile uint32_t I2SPR   ;

} SPI_REG ;

#define  SPI1                     ( ( SPI_REG *) SPI1_u32_BASE_ADDRESS )
#define  SPI2                     ( ( SPI_REG *) SPI2_u32_BASE_ADDRESS )
#define  SPI3                     ( ( SPI_REG *) SPI3_u32_BASE_ADDRESS )
#define  SPI4                     ( ( SPI_REG *) SPI4_u32_BASE_ADDRESS )

/************************************************************************************************/
/******************************** I2C Registers *************************************************/
/************************************************************************************************/
#define I2C1_u32_BASE_ADDRESS                                0x40005400U
#define I2C2_u32_BASE_ADDRESS                                0x40005800U
#define I2C3_u32_BASE_ADDRESS                                0x40005C00U
typedef struct{

	volatile uint32_t	CR1;
	volatile uint32_t   CR2;
	volatile uint32_t	OAR1;
	volatile uint32_t	OAR2;
	volatile uint32_t	DR;
	volatile uint32_t	SR1;
	volatile uint32_t	SR2;
	volatile uint32_t	CCR;
	volatile uint32_t	TRISE;
	volatile uint32_t   FLTR;

}I2C_REG;

#define I2C1		(( I2C_REG*)(I2C1_u32_BASE_ADDRESS))
#define I2C2		(( I2C_REG*)(I2C2_u32_BASE_ADDRESS))
#define I2C3		(( I2C_REG*)(I2C3_u32_BASE_ADDRESS))
/************************************************************************************************/
/******************************** GPTIMER Registers *********************************************/
/************************************************************************************************/
#define TMR2_u32_BASE_ADDRESS                                0x40000000U
#define TMR3_u32_BASE_ADDRESS                                0x40000400U
#define TMR4_u32_BASE_ADDRESS                                0x40000800U
#define TMR5_u32_BASE_ADDRESS                                0x40000C00U



typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR[2];
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t RESERVED_1;
	volatile uint32_t CCR[4];
	volatile uint32_t RESERVED_2;
	volatile uint32_t DCR;
	volatile uint32_t DMAR;
	volatile uint32_t OR;
}GPTIMER_REG;


#define TMR2		(( GPTIMER_REG *)(TMR2_u32_BASE_ADDRESS))
#define TMR3		(( GPTIMER_REG *)(TMR3_u32_BASE_ADDRESS))
#define TMR4		(( GPTIMER_REG *)(TMR4_u32_BASE_ADDRESS))
#define TMR5		(( GPTIMER_REG *)(TMR5_u32_BASE_ADDRESS))
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
#define DMA1_u32_BASE_ADDRESS                                0x40026000U
#define DMA2_u32_BASE_ADDRESS                                0x40026400U
typedef struct
{
	volatile uint32_t CR;     /*!< DMA stream x configuration register      */
	volatile uint32_t NDTR;   /*!< DMA stream x number of data register     */
	volatile uint32_t PAR;    /*!< DMA stream x peripheral address register */
	volatile uint32_t M0AR;   /*!< DMA stream x memory 0 address register   */
	volatile uint32_t M1AR;   /*!< DMA stream x memory 1 address register   */
	volatile uint32_t FCR;    /*!< DMA stream x FIFO control register       */
} DMA_STREAM;

typedef struct
{
	volatile uint32_t ISR[2];   /*!< DMA low interrupt status register,      Address offset: 0x00 */
	volatile uint32_t IFCR[2];  /*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
	DMA_STREAM        STREAM[8];
} DMA_REG;
#define DMA1 ( ( DMA_REG * ) DMA1_u32_BASE_ADDRESS )
#define DMA2 ( ( DMA_REG * ) DMA2_u32_BASE_ADDRESS )
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/

#endif
