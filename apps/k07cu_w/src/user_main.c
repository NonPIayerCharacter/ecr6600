/**
* @file user_main.c
* @author 小王同学
* @brief user_main module is used to 
* @version 0.1
* @date 2023-05-10
*
*/
#include "led_driver.h"
#include "led.h"
#include "andlink_wifi_softap.h"
#include "user_wifi_status.h"
#include "system_event.h"
#include "ipotek_prov.h"
#include "andlink_wifi_connect.h"
#include "sntp_tr.h"
/***********************************************************
*************************micro define***********************
***********************************************************/
 
 
/***********************************************************
***********************typedef define***********************
***********************************************************/
 
 
/***********************************************************
***********************variable define**********************
***********************************************************/
 
 
/***********************************************************
***********************function define**********************
***********************************************************/
void user_main(void)
{
    set_timezone(8);

    ipotek_prov_data_init();

    sys_event_loop_init(wifi_status_event, NULL);
    // user_led_test();

    andlink_softap_start();
}
