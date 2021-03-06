# Class 1.1 - Drawing Primitives

## Summary

1. Fill screen
2. Draw Rectangle
3. Draw Line
4. Draw Circle

## 1. How to fill screen

```C++
auto screen_width = 240;
auto screen_height = 160;
for (auto x = 0u; x < screen_width; ++x) {
  for (auto y = 0u; y < screen_height; ++y) {
    ((std::uint16_t*)0x6000000)[x + screen_width*y] = 0x1EF;
  }
}
```

## 2. How to draw a rectangle on screen

```C++
auto rect_width = 32u;
auto rect_height = 32u;
auto rect_x = 16u;
auto rect_y = 120u;

for (auto x = rect_x; x < rect_x + rect_width; ++x) {
  for (auto y = rect_y; y < rect_y + rect_height; ++y) {
    ((std::uint16_t*)0x6000000)[x + screen_width*y] = 0x1EF;
  }
}

```

## 3. How to draw a Line

Lazy way (starting from (x0, y0) to (x1, y1)):

```C++
auto dx = x1 - x0;
auto dy = y1 - y0;

if (dx > dy) {
    for (auto y = y0; y < y1; ++y) {
        auto x = x0 + dx * (y - y0) / dy;
        auto next_x = x0 + dx * (y + 1 - y0) / dy;
        for (auto x_ = x; x_ < next_x; ++x_) {
            gba::video::vram(x_, y, color);
        }
    }
} else {
    for (auto x = x0; x < x1; ++x) {
        auto y = y0 + dy * (x - x0) / dx;
        auto next_y = y0 + dy * (x + 1 - x0) / dx;
        for (auto y_ = y; y_ < next_y; ++y_) {
            gba::video::vram(x, y_, color);
        }
    }
}
```

## 4. How to draw a circle

```C++
auto x = 0;
auto y = radius;
auto dp = 1 - radius;
do
{
        if (dp < 0)
                dp = dp + 2 * (++x) + 3;
        else
                dp = dp + 2 * (++x) - 2 * (--y) + 5;

        gba::video::vram(x0 + x, y0 + y, color);     //For the 8 octants
        gba::video::vram(x0 - x, y0 + y, color);
        gba::video::vram(x0 + x, y0 - y, color);
        gba::video::vram(x0 - x, y0 - y, color);
        gba::video::vram(x0 + y, y0 + x, color);
        gba::video::vram(x0 - y, y0 + x, color);
        gba::video::vram(x0 + y, y0 - x, color);
        gba::video::vram(x0 - y, y0 - x, color);

} while (x < y);
```


