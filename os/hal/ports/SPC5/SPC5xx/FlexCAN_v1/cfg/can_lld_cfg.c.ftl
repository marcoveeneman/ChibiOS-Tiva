[#ftl]
[@pp.dropOutputFile /]
[@pp.changeOutputFile name="can_lld_cfg.c" /]
/*
    SPC5 HAL - Copyright (C) 2013 STMicroelectronics

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    can_lld_cfg.c
 * @brief   CAN Driver configuration code.
 *
 * @addtogroup CAN
 * @{
 */

#include "hal.h"
#include "can_lld_cfg.h"

#if HAL_USE_CAN || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

[#list conf.instance.flexcan_settings.can_configurations.configs.can_configuration_settings as settings]
  [#assign name = settings.symbolic_name.value[0]?trim /]
  [#assign warnings = settings.flexcan_enable_warnings.value[0]?upper_case /]
  [#assign loopback = settings.flexcan_enable_loopback.value[0]?upper_case /]
  [#assign propseg = settings.timings.propseg.value[0]?string?trim /]
  [#assign pseg1 = settings.timings.pseg1.value[0]?string?trim /]
  [#assign pseg2 = settings.timings.pseg2.value[0]?string?trim /]
  [#assign presdiv = settings.timings.presdiv.value[0]?string?trim /]
  [#assign IDf0 = settings.filter_0_settings.id_mode.value[0]?string?trim /]
  [#assign maskf0 = settings.filter_0_settings.id_mask.value[0]?string?trim /]
  [#assign IDf1 = settings.filter_1_settings.id_mode.value[0]?string?trim /]
  [#assign maskf1 = settings.filter_1_settings.id_mask.value[0]?string?trim /]
  [#assign IDf2 = settings.filter_2_settings.id_mode.value[0]?string?trim /]
  [#assign maskf2 = settings.filter_2_settings.id_mask.value[0]?string?trim /]
  [#assign IDf3 = settings.filter_3_settings.id_mode.value[0]?string?trim /]
  [#assign maskf3 = settings.filter_3_settings.id_mask.value[0]?string?trim /]
  [#assign IDf4 = settings.filter_4_settings.id_mode.value[0]?string?trim /]
  [#assign maskf4 = settings.filter_4_settings.id_mask.value[0]?string?trim /]
  [#assign IDf5 = settings.filter_5_settings.id_mode.value[0]?string?trim /]
  [#assign maskf5 = settings.filter_5_settings.id_mask.value[0]?string?trim /]
  [#assign IDf6 = settings.filter_6_settings.id_mode.value[0]?string?trim /]
  [#assign maskf6 = settings.filter_6_settings.id_mask.value[0]?string?trim /]
  [#assign IDf7 = settings.filter_7_settings.id_mode.value[0]?string?trim /]
  [#assign maskf7 = settings.filter_7_settings.id_mask.value[0]?string?trim /]
  [#if warnings == "TRUE"]
    [#assign warnings = "CAN_MCR_WRN_EN" /]
  [/#if]
  [#if warnings == "FALSE"]
    [#assign warnings = "0" /]
  [/#if]
  [#if loopback == "TRUE"]
    [#assign loopback = "CAN_CTRL_LPB | " /]
  [/#if]
  [#if loopback == "FALSE"]
    [#assign loopback = "" /]
  [/#if]
  [#if IDf0 == "STANDARD"]
    [#assign IDf0 = "0" /]
  [/#if]
  [#if IDf0 == "EXTENDED"]
    [#assign IDf0 = "1" /]
  [/#if]
  [#if IDf1 == "STANDARD"]
    [#assign IDf1 = "0" /]
  [/#if]
  [#if IDf1 == "EXTENDED"]
    [#assign IDf1 = "1" /]
  [/#if]
  [#if IDf2 == "STANDARD"]
    [#assign IDf2 = "0" /]
  [/#if]
  [#if IDf2 == "EXTENDED"]
    [#assign IDf2 = "1" /]
  [/#if]
  [#if IDf3 == "STANDARD"]
    [#assign IDf3 = "0" /]
  [/#if]
  [#if IDf3 == "EXTENDED"]
    [#assign IDf3 = "1" /]
  [/#if]
  [#if IDf4 == "STANDARD"]
    [#assign IDf4 = "0" /]
  [/#if]
  [#if IDf4 == "EXTENDED"]
    [#assign IDf4 = "1" /]
  [/#if]
  [#if IDf5 == "STANDARD"]
    [#assign IDf5 = "0" /]
  [/#if]
  [#if IDf5 == "EXTENDED"]
    [#assign IDf5 = "1" /]
  [/#if]
  [#if IDf6 == "STANDARD"]
    [#assign IDf6 = "0" /]
  [/#if]
  [#if IDf6 == "EXTENDED"]
    [#assign IDf6 = "1" /]
  [/#if]
  [#if IDf7 == "STANDARD"]
    [#assign IDf7 = "0" /]
  [/#if]
  [#if IDf7 == "EXTENDED"]
    [#assign IDf7 = "1" /]
  [/#if]
  [#if maskf0 == ""]
    [#assign maskf0 = "0" /]
  [/#if]
  [#if maskf1 == ""]
    [#assign maskf1 = "0" /]
  [/#if]
  [#if maskf2 == ""]
    [#assign maskf2 = "0" /]
  [/#if]
  [#if maskf3 == ""]
    [#assign maskf3 = "0" /]
  [/#if]
  [#if maskf4 == ""]
    [#assign maskf4 = "0" /]
  [/#if]
  [#if maskf5 == ""]
    [#assign maskf5 = "0" /]
  [/#if]
  [#if maskf6 == ""]
    [#assign maskf6 = "0" /]
  [/#if]
  [#if maskf7 == ""]
    [#assign maskf7 = "0" /]
  [/#if]
/**
 * @brief   Structure defining the CAN configuration "${name}".
 */
const CANConfig can_config_${name} = {

  ${warnings},
  ${loopback}CAN_CTRL_PROPSEG(${propseg}) | CAN_CTRL_PSEG2(${pseg2}) |
  CAN_CTRL_PSEG1(${pseg1}) | CAN_CTRL_PRESDIV(${presdiv})
#if SPC5_CAN_USE_FILTERS
  ,
  {
   {${IDf0}, ${maskf0}},
   {${IDf1}, ${maskf1}},
   {${IDf2}, ${maskf2}},
   {${IDf3}, ${maskf3}},
   {${IDf4}, ${maskf4}},
   {${IDf5}, ${maskf5}},
   {${IDf6}, ${maskf6}},
   {${IDf7}, ${maskf7}}
  }
#endif
};

[/#list]
/*===========================================================================*/
/* Driver local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

#endif /* HAL_USE_ICU */

/** @} */
