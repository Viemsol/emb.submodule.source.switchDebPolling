//-----------------------------------------------------------------------------
// Copyright(c)2021 Saura as an unpublished work.
//
// The information contained herein is confidential property of Saura.
// All rights reserved.  Reproduction, adaptation, or translation without the
// express written consent of Saura is prohibited, except as allowed
// under the copyright laws.
//-----------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////////////
/// @file swDebPolMgr_dependency_include.h
/// @ingroup swDebPolMgr_ext
/// @brief swDebPolMgr dependency includes declarations.
///
///////////////////////////////////////////////////////////////////////////////

#ifndef SWDEBPOLMGR_DEPENDENCY_INCLUDE_H
#define SWDEBPOLMGR_DEPENDENCY_INCLUDE_H

//-------------- HEADER INCLUDE FILES -----------------------------------------
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#ifdef UNIT_TEST
    // all dependency includes will be mocked
#else
   // all sub module dependency includes add here needed by this submodule
   //os.h
   //
#endif

//-------------- DEFINITIONS --------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

//-------------- TYPEDEFS -----------------------------------------------------

//-------------- FUNCTION PROTOTYPES ------------------------------------------
//read current status of switches
uint32_t swDebPolMgr_dependency_readAllSwitches(void);
//-------------- FUNCTION PROTOTYPES ------------------------------------------

#ifdef __cplusplus
}
#endif

#endif  // SWDEBPOLMGR_DEPENDENCY_INCLUDE_H
