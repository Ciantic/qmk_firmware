
#include "test_common.hpp"

using testing::_;
using testing::Return;

class OslTests : public TestFixture {};

/*
fredizzimo @fredizzimo 15:09
I think one shots should always work like this.
1. Key down always activate layer or modifier immediately
  * Unless it's already locked, then unlock, and don't process key up
2. Key up, don't do anything, start ONESHOT_TIMEOUT
  * Unless another key already was pressed
3. Key down again, add tap count, but only if the key is transparent on the target layer in case of OSM
  * If the tap count is big enough, then lock modifier or layer
4. Another key down process it, return to the previous layer, or disable the modifier
  * Unless it's another oneshot modifier, then add the modifer to the previous one
5.If ONESHOT_TIMEOUT then disable the layer or modifier
*/

// // OSL switches layer, but only after 200ms the tapping term
// // This is unwanted behavior if tap toggling is not turned ons
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

// OSL Down,Up then key should work
TEST_F(OslTests, OslDownUpThenKey) {
      TestDriver driver;
    // layer_state = 0;

    // OSL(1) DOWN
    press_key(0, 0);
    run_one_scan_loop();

    // OSL(1) UP
    release_key(0, 0);
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport())).Times(2);
    run_one_scan_loop();
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_EQ(2, layer_state); // It has now changed
    // run_one_scan_loop();

    testing::InSequence s;
    // Layer 1, KC_A down
    press_key(2, 0);
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport())).Times(1);
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_A)));
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport())).Times(3);
    run_one_scan_loop();
}