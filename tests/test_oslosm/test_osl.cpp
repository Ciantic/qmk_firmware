
#include "test_common.hpp"

using testing::_;
using testing::Return;

class OslTests : public TestFixture {};

// // OSL should switch layer immediately
TEST_F(OslTests, OslShouldSwitchLayerImmediately) {
    TestDriver driver;
    EXPECT_EQ(0, layer_state);

    // OSL(1) DOWN
    press_key(0, 0);
    run_one_scan_loop();
    EXPECT_EQ(2, layer_state);

    // idle_for(9);
    // idle_for(190);
    // EXPECT_EQ(0, layer_state);
    // idle_for(1);
    // EXPECT_EQ(2, layer_state);

    // Layer 1, KC_A down, move this to test below when layers do not leak between tests
    press_key(2, 0);
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_A)));
    run_one_scan_loop();
}

// // OSL Down, then key should work
// TEST_F(OslTests, OslDownThenKey) {
//     TestDriver driver;

//     // OSL(1) DOWN
//     press_key(0, 0);
//     run_one_scan_loop();

//     // Layer 1, KC_A down
//     press_key(2, 0);
//     EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_A)));
//     run_one_scan_loop();
// }

// // OSL Down,Up then key should work
// TEST_F(OslTests, OslDownUpThenKey) {
//     TestDriver driver;

//     // OSL(1) DOWN
//     press_key(0, 0);
//     run_one_scan_loop();

//     // OSL(1) UP
//     release_key(0, 0);
//     run_one_scan_loop();

//     EXPECT_EQ((1 << 1), layer_state);

//     // Layer 1, KC_A down
//     press_key(2, 0);
//     EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_A)));
//     run_one_scan_loop();
// }