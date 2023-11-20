//-----------------------------------------------------------------------------
// Copyright(c)2021 Saura as an unpublished work.
//
// The information contained herein is confidential property of Saura.
// All rights reserved.  Reproduction, adaptation, or translation without the
// express written consent of Saura is prohibited, except as allowed
// under the copyright laws.
//-----------------------------------------------------------------------------

/// @defgroup swDebPolMgr_ext Module Name External API
/// @defgroup swDebPolMgr_int Module Name Internal

///////////////////////////////////////////////////////////////////////////////
/// @file swDebPolMgr_api.h
/// @ingroup swDebPolMgr_ext
/// @brief swDebPolMgr API.
///
///////////////////////////////////////////////////////////////////////////////

#ifndef SWDEBPOLMGR_API_H
#define SWDEBPOLMGR_API_H

//-------------- HEADER INCLUDE FILES -----------------------------------------
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

//-------------- DEFINITIONS --------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

//-------------- TYPEDEFS -----------------------------------------------------

//-------------- FUNCTION PROTOTYPES ------------------------------------------

///////////////////////////////////////////////////////////////////////////////
/// @brief This function initializes swich debaunce manager.
/// @note This function must be called once during device initialization ,
//        after all input switch pins are initialized.
///////////////////////////////////////////////////////////////////////////////
void swDebPolMgr_init(void); // TODO - Delete after setup.

///////////////////////////////////////////////////////////////////////////////
/// @brief This function handles switch debounce logic.
/// @note this function must be called periodically, i.e. every 10ms.
///////////////////////////////////////////////////////////////////////////////
void swDebPolMgr_run(void);

///////////////////////////////////////////////////////////////////////////////
/// @brief This function reads debounce switch status.
/// @return debounced switch status bits.
///////////////////////////////////////////////////////////////////////////////
uint32_t swDebPolMgr_getStatus(void);

#ifdef __cplusplus
}
#endif

#endif  // SWDEBPOLMGR_API_H
