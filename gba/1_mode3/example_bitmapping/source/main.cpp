#include <cstdint>
#include <vector>
#include "gba.h"
#include "video_operations.h"

auto data = std::vector<std::uint16_t>{
    0x1F, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x00,
    0x1F, 0x00, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x1F,
    0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x1F,
    0x1F, 0x00, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x1F,
    0x1F, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x00, 0x1F, 0x1F, 0x1D, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F
};

int main() {
    {
        using namespace gba::video;
        lcd_control() = 3;
        enable_bg(2);
    }
    while (true) {
        gba::video::fill_screen(0x2000);
        gba::video::vsync();
        draw_data(10u, 10u);
    }
}
