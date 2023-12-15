#pragma once

#include <cstdint>
#include <limits>

namespace kat {
    struct color {
        float r = 0., g = 0., b = 0., a = 0.;

        color() = default;

        constexpr color(float r, float g, float b, float a = 1.) : r(r), g(g), b(b), a(a) {}

        static constexpr color from_rgba8888(uint32_t v) {
            // 0xRRGGBBAA
            unsigned char r = (v >> 24) & 0xff;
            unsigned char g = (v >> 16) & 0xff;
            unsigned char b = (v >> 8) & 0xff;
            unsigned char a = v & 0xff;

            return from_unorm_bytes(r, g, b, a);
        }

        static constexpr color from_rgb888(uint32_t v) {
            // 0xRRGGBB
            unsigned char r = (v >> 16) & 0xff;
            unsigned char g = (v >> 8) & 0xff;
            unsigned char b = v & 0xff;

            return from_unorm_bytes(r, g, b, 255);
        }

        static constexpr color from_bgra8888(uint32_t v) {
            // 0xBBGGRRAA
            unsigned char b = (v >> 24) & 0xff;
            unsigned char g = (v >> 16) & 0xff;
            unsigned char r = (v >> 8) & 0xff;
            unsigned char a = v & 0xff;

            return from_unorm_bytes(r, g, b, a);
        }

        static constexpr color from_bgr888(uint32_t v) {
            // 0xRRGGBB
            unsigned char b = (v >> 16) & 0xff;
            unsigned char g = (v >> 8) & 0xff;
            unsigned char r = v & 0xff;

            return from_unorm_bytes(r, g, b, 255);
        }

        static constexpr color from_argb8888(uint32_t v) {
            // 0xAARRGGBB
            unsigned char a = (v >> 24) & 0xff;
            unsigned char r = (v >> 16) & 0xff;
            unsigned char g = (v >> 8) & 0xff;
            unsigned char b = v & 0xff;

            return from_unorm_bytes(r, g, b, a);
        }

        static constexpr color from_abgr8888(uint32_t v) {
            // 0xAABBGGRR
            unsigned char a = (v >> 24) & 0xff;
            unsigned char b = (v >> 16) & 0xff;
            unsigned char g = (v >> 8) & 0xff;
            unsigned char r = v & 0xff;

            return from_unorm_bytes(r, g, b, a);
        }


        static constexpr color from_unorm_bytes(uint8_t r, uint8_t g, uint8_t b,
                                                uint8_t a = std::numeric_limits<uint8_t>::max()) {
            const float r_ = static_cast<float>(r) / static_cast<float>(0xff);
            const float g_ = static_cast<float>(g) / static_cast<float>(0xff);
            const float b_ = static_cast<float>(b) / static_cast<float>(0xff);
            const float a_ = static_cast<float>(a) / static_cast<float>(0xff);

            return { r_, g_, b_, a_ };
        }

        static constexpr color lerp(const color &a, const color &b, float t) {
            return {
                a.r + (b.r - a.r) * t,
                a.g + (b.g - a.g) * t,
                a.b + (b.b - a.b) * t,
                a.a + (b.a - a.a) * t,
            };
        }

        constexpr color lerp(const color &b, float t) const { return lerp(*this, b, t); }
    };
} // namespace kat
