#include "platform.hpp"

namespace kat {
    const std::shared_ptr<platform> &platform::get() {
        return s_platform;
    }
} // namespace kat
