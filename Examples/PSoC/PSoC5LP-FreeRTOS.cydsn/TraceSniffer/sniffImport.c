/** \file sniffImport.c
 * \brief sniffImport source file.
 * \details Implements the functions used for initialising the Tracer.
 * \author Jonas Mair
 * \date 2018
 */

#include <string.h>
#include <sniffImport.h>

//! @cond Doxygen_Suppress
typedef void* TaskHandle_t;
extern long xTaskGenericCreate();
extern void vTaskSuspend(TaskHandle_t xTaskToSuspend);
//! @endcond
static TaskHandle_t sniffTaskHandle = NULL;/**<The sniffTaskHandle*/
/**
 * \brief Initialise the TraceSniffer, has to be called before any RTOS object is created
 * \return 0 if OK
 * \sa initialiseFIFO() and initialiseObjectList() and enableReceiveInterrupt()
 */
uint8_t initialiseTraceSniffer() {
	initialiseFIFO();
	initialiseObjectList();
	enableReceiveInterrupt();
	memset(sniffIDFilter, 0xff, sizeof(uint8_t) * SIZE_OF_FILTER);


#if WAIT_FOR_SNIFFER_START
	uint8_t* data;
	payloadType* type;
	while(readReceiveFIFO(data,type)!=0);
#endif
#if !SEND_WITHOUT_SNIFF_TASK
	//Create Task
	xTaskGenericCreate(sniffTask, "sniffTask", STACK_SIZE_OF_SNIFF_TASK, NULL,PRIORITY_OF_SNIFF_TASK, &sniffTaskHandle,NULL,NULL);
#endif
	
	return 0;
}

/**
 * \brief Stops the TraceSniffer, either if the ErrorFIFO overruns or the user calls the function
 */
void stopTraceSniffer() {
	vTaskSuspend(sniffTaskHandle);
}

