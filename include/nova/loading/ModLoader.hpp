#pragma once

#include <memory>
#include <string>
#include <vector>

namespace nova {

class ModLoader {
private:
    inline static std::shared_ptr<ModLoader> INSTANCE = nullptr;
    std::vector<void*> libs;

public:
    ~ModLoader() = default;

    /**
     * Loads a dynamic library.
     *
     * Note that this function does not to input validation, and assumes
     * you pass a valid path. It also doesn't do extension validation due
     * to the primary use as a blanket loader; a different set of checks
     * determines what to load, and this just loads it.
     *
     * Use with care.
     */
    void loadDynamicLibrary(const std::string& path);

    static std::shared_ptr<ModLoader> getInstance();
};

} // namespace nova
