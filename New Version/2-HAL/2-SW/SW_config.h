/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  HAL                 ************************/
/************************        SWC:    SW                  ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#ifndef SW_CONFIG_H_
#define SW_CONFIG_H_

/* Write:
    - '0': To disable software debouncing
    - '1': To enable software debouncing
*/
#define SOFTWARE_DEBOUNCING 		1

/* Write:
    - '0': To choose wait & double check technique
*/
#define DEBOUNCING_TECHNIQUE 		0

/* Write:
    - '0': If you are using a temporary switch, but make sure to enable software debouncing
    - '1': If you are using a permanent switch or no need to software debouncing
*/
#define IS_PERMANENT_SWITCH_USED 	1


#endif /* SW_CONFIG_H_ End */
