#include <Geode/Geode.hpp>
#include <Geode/modify/GameManager.hpp>

using namespace geode::prelude;
class $modify(MyGameManager, GameManager) {
    bool isIconUnlocked(int iconID, IconType type) {
        if (!Mod::get()->getSettingValue<bool>("unlock-icons")){
            return GameManager::isIconUnlocked(iconID, type);
        }
        return true;
    }
    bool isColorUnlocked(int colorID, UnlockType type) {
        if (!Mod::get()->getSettingValue<bool>("unlock-icons")){
            return GameManager::isColorUnlocked(colorID, type);
        }
        return true;
    }
};

class $modify(UnlockShopsGMHook, GameManager) {
    bool getUGV(const char* key) {
        if (!Mod::get()->getSettingValue<bool>("unlock-shops")) {
            return GameManager::getUGV(key);
        }
        if (GameManager::getUGV(key)) {
            return true;
        }
        return strcmp(key, "11") == 0 ||
               strcmp(key, "20") == 0 ||
               strcmp(key, "34") == 0 ||
               strcmp(key, "35") == 0;
    }
};
