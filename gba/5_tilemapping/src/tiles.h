#ifndef GBA_TILES_H
#define GBA_TILES_H

#include <cstdint>
#include <array>

#include "graphics.h"
#include "video.h"

namespace gba::graphics::layers {

struct Tile {
  std::array<std::uint32_t, 8> rows;
};

static auto& bg_palette = *new (reinterpret_cast<void*>(0x0500'0000)) std::array<std::uint16_t, 256>{};
static auto& tiles = *new (reinterpret_cast<void*>(0x0600'0000)) std::array<Tile, 0x40>{};
static auto& tilemap = *new (std::end(tiles)) std::array<std::uint16_t, 1024>{};

inline auto& bg_controls(graphics::Layer layer) {
    return *(reinterpret_cast<std::uint16_t*>(0x0400'0008) + utils::value_of(layer));
}

inline void set_bg_priority(graphics::Layer layer, unsigned priority) {
    auto& control = bg_controls(layer);
    control = (control & ~0b11) | (priority & 0b11);
}

inline void set_base_charblock(graphics::Layer layer, unsigned value) {
    auto& control = bg_controls(layer);
    control = (control & ~0b1100) | ((value & 0b11) << 2);
}

inline void set_base_screenblock(graphics::Layer layer, unsigned value) {
    auto& control = bg_controls(layer);
    control = (control & (~0x1fu << 8)) | ((value & 0x1f) << 8);
}

inline void bg_visible(graphics::Layer layer, bool enabled=true) {
    video::lcd_control[utils::value_of(layer)+8] = enabled;
}

inline volatile auto& bg_ox_register(graphics::Layer layer) {
    return *(reinterpret_cast<std::uint16_t*>(0x0400'0010) + utils::value_of(layer));
}

inline volatile auto& bg_oy_register(graphics::Layer layer) {
    return *(reinterpret_cast<std::uint16_t*>(0x0400'0012) + utils::value_of(layer));
}

inline void set_bg_ox(graphics::Layer layer, unsigned ox) {
    bg_ox_register(layer) = ox;
}

inline void set_bg_oy(graphics::Layer layer, unsigned oy) {
    bg_oy_register(layer) = oy;
}

}

#endif
