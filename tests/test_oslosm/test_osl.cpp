
#include "test_common.hpp"

using testing::_;
using testing::Return;

class OslTests : public TestFixture {};


TEST_F(OslTests, OslTesting) {
    TestDriver driver;
    press_key(0, 0);
    keyboard_task();

    press_key(0, 0);
    keyboard_task();
    release_key(0, 0);

    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_A)));
    keyboard_task();
}