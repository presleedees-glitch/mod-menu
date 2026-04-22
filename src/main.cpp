#include "main.hpp"
#include "beatsaber-hook/shared/utils/logging.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"

static modloader::ModInfo modInfo{MOD_ID, VERSION, 0};

Logger& getLogger() {
    static Logger* logger = new Logger(modInfo, LoggerOptions(false, true));
    return *logger;
}

extern "C" void setup(CModInfo* info) {
    info->id      = MOD_ID;
    info->version = VERSION;

    getLogger().info("Setting up %s v%s", MOD_ID, VERSION);
}

extern "C" void late_load() {
    il2cpp_functions::Init();
    getLogger().info("Hello from %s!", MOD_ID);
}
