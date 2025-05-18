/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32g4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32g4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "trice.h"
#include "stm32g4xx_ll_usart.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_adc2;
extern UART_HandleTypeDef huart2;
extern TIM_HandleTypeDef htim6;

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
   while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* TODO: implement interrupt handler in Scilla domain. Also better to create a
   * wrappers of all registers for better view */

  /* Memory management faults */

  uint32_t CFSR_IACCVIOL = READ_BIT(SCB->CFSR, SCB_CFSR_IACCVIOL_Msk);
  (void)CFSR_IACCVIOL;

  uint32_t CFSR_DACCVIOL = READ_BIT(SCB->CFSR, SCB_CFSR_DACCVIOL_Msk);
  (void)CFSR_DACCVIOL;

  uint32_t CFSR_MUNSTKERR = READ_BIT(SCB->CFSR, SCB_CFSR_MUNSTKERR_Msk);
  (void)CFSR_MUNSTKERR;

  uint32_t CFSR_MSTKERR = READ_BIT(SCB->CFSR, SCB_CFSR_MSTKERR_Msk);
  (void)CFSR_MSTKERR;

  uint32_t CFSR_MLSPERR = READ_BIT(SCB->CFSR, SCB_CFSR_MLSPERR_Msk);
  (void)CFSR_MLSPERR;

  uint32_t CFSR_MMARVALID = READ_BIT(SCB->CFSR, SCB_CFSR_MMARVALID_Msk);
  (void)CFSR_MMARVALID;

  /* Bus faults */

  uint32_t CFSR_IBUSERR = READ_BIT(SCB->CFSR, SCB_CFSR_IBUSERR_Msk);
  (void)CFSR_IBUSERR;

  uint32_t CFSR_PRECISERR = READ_BIT(SCB->CFSR, SCB_CFSR_PRECISERR_Msk);
  (void)CFSR_PRECISERR;

  uint32_t CFSR_IMPRECISERR = READ_BIT(SCB->CFSR, SCB_CFSR_IMPRECISERR_Msk);
  (void) CFSR_IMPRECISERR;

  uint32_t CFSR_UNSTKERR = READ_BIT(SCB->CFSR, SCB_CFSR_UNSTKERR_Msk);
  (void)CFSR_UNSTKERR;

  uint32_t CFSR_STKERR = READ_BIT(SCB->CFSR, SCB_CFSR_STKERR_Msk);
  (void)CFSR_STKERR;

  uint32_t CFSR_LSPERR = READ_BIT(SCB->CFSR, SCB_CFSR_LSPERR_Msk);
  (void)CFSR_LSPERR;

  uint32_t CFSR_BFARVALID = READ_BIT(SCB->CFSR, SCB_CFSR_BFARVALID_Msk);
  (void)CFSR_BFARVALID;

  /* Usage faults */

  uint32_t CFSR_UNDEFINSTR = READ_BIT(SCB->CFSR, SCB_CFSR_UNDEFINSTR_Msk);
  (void)CFSR_UNDEFINSTR;

  uint32_t CFSR_INVSTATE = READ_BIT(SCB->CFSR, SCB_CFSR_INVSTATE_Msk);
  (void)CFSR_INVSTATE;

  uint32_t CFSR_INVPC = READ_BIT(SCB->CFSR, SCB_CFSR_INVPC_Msk);
  (void)CFSR_INVPC;

  uint32_t CFSR_NOCP = READ_BIT(SCB->CFSR, SCB_CFSR_NOCP_Msk);
  (void)CFSR_NOCP;

  uint32_t CFSR_UNALIGNED = READ_BIT(SCB->CFSR, SCB_CFSR_UNALIGNED_Msk);
  (void)CFSR_UNALIGNED;

  uint32_t CFSR_DIVBYZERO = READ_BIT(SCB->CFSR, SCB_CFSR_DIVBYZERO_Msk);
  (void)CFSR_DIVBYZERO;

  uint32_t BFAR = SCB->BFAR;
  (void)BFAR;

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/******************************************************************************/
/* STM32G4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32g4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles DMA1 channel1 global interrupt.
  */
void DMA1_Channel1_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel1_IRQn 0 */

  /* USER CODE END DMA1_Channel1_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_adc2);
  /* USER CODE BEGIN DMA1_Channel1_IRQn 1 */

  /* USER CODE END DMA1_Channel1_IRQn 1 */
}

/**
  * @brief This function handles USART2 global interrupt / USART2 wake-up interrupt through EXTI line 26.
  */
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */

  /* USER CODE END USART2_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART2_IRQn 1 */
  if (LL_USART_IsActiveFlag_TXE(TRICE_UARTA)) {
    LL_USART_ClearFlag_TXFE(TRICE_UARTA);
    triceServeTransmitUartA();
  }
  /* USER CODE END USART2_IRQn 1 */
}

/**
  * @brief This function handles TIM6 global interrupt, DAC1 and DAC3 channel underrun error interrupts.
  */
void TIM6_DAC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM6_DAC_IRQn 0 */

  /* USER CODE END TIM6_DAC_IRQn 0 */
  HAL_TIM_IRQHandler(&htim6);
  /* USER CODE BEGIN TIM6_DAC_IRQn 1 */

  /* USER CODE END TIM6_DAC_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
