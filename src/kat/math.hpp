#pragma once

#include <glm/glm.hpp>

namespace kat {

    template <typename T>
    concept numeric = std::integral<T> || std::floating_point<T>;

    template <numeric T>
    struct rect {
        glm::tvec2<T> position;
        glm::tvec2<T> size;

        constexpr T area() const noexcept {
            return size.x * size.y;
        }

        constexpr T left() const noexcept {
            return position.x;
        }

        constexpr T right() const noexcept {
            return position.x + size.x;
        }

        constexpr T top() const noexcept {
            return position.y;
        }

        constexpr T bottom() const noexcept {
            return position.y + size.y;
        }

        constexpr T center_x() const noexcept {
            return position.x + size.x / T(2);
        }

        constexpr T center_y() const noexcept {
            return position.y + size.y / T(2);
        }

        constexpr glm::tvec2<T> top_left() const noexcept {
            return { left(), top() };
        }

        constexpr glm::tvec2<T> top_right() const noexcept {
            return { right(), top() };
        }

        constexpr glm::tvec2<T> bottom_left() const noexcept {
            return { left(), bottom() };
        }

        constexpr glm::tvec2<T> bottom_right() const noexcept {
            return { right(), bottom() };
        }

        constexpr glm::tvec2<T> center() const noexcept {
            return { center_x(), center_y() };
        }

        constexpr glm::tvec2<T> left_center() const noexcept {
            return { left(), center_y() };
        }

        constexpr glm::tvec2<T> right_center() const noexcept {
            return { right(), center_y() };
        }

        constexpr glm::tvec2<T> top_center() const noexcept {
            return { center_x(), top() };
        }

        constexpr glm::tvec2<T> bottom_center() const noexcept {
            return { center_x(), bottom() };
        }
    };


}
