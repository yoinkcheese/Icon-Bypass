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