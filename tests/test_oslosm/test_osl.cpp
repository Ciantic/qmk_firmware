
#include "test_common.hpp"

using testing::_;
using testing::Return;

class OslTests : public TestFixture {};


TEST_F(OslTests, OslTesting) {
    TestDriver driver;
    // OSL(1) DOWN
    press_key(0, 0);
    run_one_scan_loop();

    // Layer 1, KC_A down
    press_key(2, 0);
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_A)));
    run_one_scan_loop();

    // Layer 1, KC_A up
    release_key(2, 0);
    run_one_scan_loop();

    // OSL(1) UP
    release_key(0, 0);
    // EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport()));
    run_one_scan_loop();
}