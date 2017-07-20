
#include "test_common.hpp"

using testing::_;
using testing::Return;

class OslTests : public TestFixture {};

// OSL Delay bug
TEST_F(OslTests, OslTesting) {
    TestDriver driver;
    EXPECT_EQ(0, layer_state);

    // OSL(1) DOWN
    press_key(0, 0);
    run_one_scan_loop();
    EXPECT_EQ((1 <<0) | (1 << 1), layer_state);

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
    EXPECT_EQ(1 << 0, layer_state);
}


// OSL Delay bug (up)
TEST_F(OslTests, OslTestingUp) {
    TestDriver driver;

    // OSL(1) DOWN
    press_key(0, 0);
    run_one_scan_loop();

    // OSL(1) UP
    release_key(0, 0);
    run_one_scan_loop();

    EXPECT_EQ((1 << 1), layer_state);

    // Layer 1, KC_A down
    press_key(2, 0);
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_A)));
    run_one_scan_loop();
}