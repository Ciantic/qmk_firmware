
#include "test_common.hpp"

using testing::_;
using testing::Return;

class OslTests : public TestFixture {};

// OSL switches layer, but only after 200ms the tapping term
// This is unwanted behavior if tap toggling is not turned ons
TEST_F(OslTests, OslShouldSwitchLayerAfterTappingTerm) {
    TestDriver driver;
    layer_state = 0;
    EXPECT_EQ(0, layer_state);

    // OSL(1) DOWN
    press_key(0, 0);
    run_one_scan_loop();
    EXPECT_EQ(0, layer_state); // It has not changed yet

    idle_for(200); // TAPPING_TERM
    EXPECT_EQ(2, layer_state); // It has now changed
}

// OSL Down, then key should work
TEST_F(OslTests, OslDownThenKey) {
    TestDriver driver;
    layer_state = 0;

    // OSL(1) DOWN
    press_key(0, 0);
    run_one_scan_loop();
    idle_for(200); // TAPPING_TERM

    // Layer 1, KC_A down
    press_key(2, 0);
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_A)));
    run_one_scan_loop();
}

// // OSL Down,Up then key should work
// TEST_F(OslTests, OslDownUpThenKey) {
//     TestDriver driver;
//     // layer_state = 0;

//     // OSL(1) DOWN
//     press_key(0, 0);
//     run_one_scan_loop();

//     // OSL(1) UP
//     release_key(0, 0);
//     run_one_scan_loop();

//     EXPECT_EQ(2, layer_state); // It has now changed
//     run_one_scan_loop();

//     // Layer 1, KC_A down
//     press_key(2, 0);
//     EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_A)));
//     run_one_scan_loop();
// }