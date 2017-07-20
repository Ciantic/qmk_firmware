
#include "test_common.hpp"

using testing::_;
using testing::Return;

class OslTests : public TestFixture {};


TEST_F(OslTests, OslTesting) {
    TestDriver driver;
    press_key(2, 0);
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_C)));
    // run_one_scan_loop();
    // release_key(2, 0);
    // run_one_scan_loop();

    // press_key(0, 0);
    // run_one_scan_loop();
    // // EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_A)));

    // release_key(0, 0);
    // run_one_scan_loop();
}