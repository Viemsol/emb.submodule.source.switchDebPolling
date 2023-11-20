

#include "swDebPolMgr_api.h"
#include "swDebPolMgr_dependency_include.h"
#include "unity.h"

/* sometimes you may want to get at local data in a module.
 * for example: If you plan to pass by reference, this could be useful
 * however, it should often be avoided */
extern uint32_t swFinal, swDeb;
uint32_t curSw;
void setUp(void)
{
  /* This is run before EACH TEST */
   curSw = 0x01;
}

void tearDown(void)
{
}

void test_swDebPolMgr_init_ShouldReturnZeroIfInitSuccess(void)
{
  /* All of these should pass */
  swDebPolMgr_init();
  TEST_ASSERT_EQUAL(swDebPolMgr_getStatus(), curSw);
}

void test_swDebPolMgr_run_DebFail(void)
{
    swDebPolMgr_init();
    TEST_ASSERT_EQUAL(swDebPolMgr_getStatus(), curSw);
    curSw = 0xFF;
    swDebPolMgr_run(); //first debounce
    swDebPolMgr_run(); //2nd debounce
    TEST_ASSERT_EQUAL(swDebPolMgr_getStatus(), curSw);
}

void test_swDebPolMgr_run_DebPass(void)
{
    swDebPolMgr_init();
    TEST_ASSERT_EQUAL(curSw,swDebPolMgr_getStatus());
    curSw = 0x81;
    swDebPolMgr_run(); //first debounce
    swDebPolMgr_run(); //2nd debounce
    TEST_ASSERT_EQUAL(0x81, swDebPolMgr_getStatus());

    curSw = 0x00;
    swDebPolMgr_run(); //first debounce
    curSw = 0x81;
    swDebPolMgr_run(); //2nd debounce
    TEST_ASSERT_EQUAL(0x81, swDebPolMgr_getStatus());


}

//----------------------Mock Functions
uint32_t swDebPolMgr_dependency_readAllSwitches(void)
{
    return curSw;
}
