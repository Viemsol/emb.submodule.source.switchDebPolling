//-----------------------------------------------------------------------------
// Copyright(c)2023 Saura as an unpublished work.
//
// The information contained herein is confidential property of Saura.
// All rights reserved.  Reproduction, adaptation, or translation without the
// express written consent of Saura is prohibited, except as allowed
// under the copyright laws.
//-----------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////////////
/// @file swDebPolMgr.c
/// @ingroup swDebPolMgr_int
/// @brief swDebPolMgr implementation.
///
///////////////////////////////////////////////////////////////////////////////

//-------------- HEADER INCLUDE FILES -----------------------------------------
#include "swDebPolMgr_api.h"
#include "swDebPolMgr_dependency_include.h"


//-------------- DEFINITIONS --------------------------------------------------
#ifdef UNIT_TEST
    #define STATIC
#else
    #define STATIC static
#endif

//-------------- TYPEDEFS -----------------------------------------------------

//-------------- FUNCTION PROTOTYPES ------------------------------------------

//-------------- VARIABLES ----------------------------------------------------
STATIC uint32_t swFinal, swDeb;
//-------------- STATIC FUNCTIONS ---------------------------------------------

//-------------- FUNCTIONS ----------------------------------------------------

//-----------------------------------------------------------------------------
// swDebPolMgr_init
//-----------------------------------------------------------------------------
void swDebPolMgr_init(void)
{
  uint32_t swCurr = swDebPolMgr_dependency_readAllSwitches();
  swFinal = swCurr;
  swDeb = swCurr;
}

// call this function every 10 ms
void swDebPolMgr_run(void)
{
   static bool debounceComplete;
   //read all  switches
   uint32_t swCurr = swDebPolMgr_dependency_readAllSwitches();
   //swFinal = 11111111
   //swCurr= 11110000 // first 4 bit pressed

   if(!debounceComplete)
   {
        //printf("It1 pre: swCurr =%d swDeb=%d swFinal=%d\n",swCurr, swDeb, swFinal);
        //if chang set debounce state
        if(swCurr != swFinal) // 111
        {
            swDeb = swCurr; // swDeb = 11110000
            debounceComplete = true;
        }
   }
   else
   {
        // in next read swCurr = 11111100  only 1st two input stable
        // bits which do not mach will have 1 and need to keep as it is
        uint32_t matchMask = (swCurr^swDeb); //  matchMask = 00001100
        //TODO generate events for switch which have updates
        swFinal = (swFinal & matchMask) | (swDeb & (~matchMask));
        //swFinal = 11111100
        debounceComplete = false;
        //printf("It2: swCurr =%d swDeb=%d swFinal=%d",swCurr, swDeb, swFinal);
   }
}

uint32_t swDebPolMgr_getStatus(void)
{
    return swFinal;
}
