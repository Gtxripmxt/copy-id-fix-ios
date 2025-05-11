#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/InfoLayer.hpp>
class $modify(MyInfoLayer, InfoLayer) {
        void onCopyLevelID(CCObject * sender) {
            FLAlertLayer::create(
                "Copy ID",
                "Level ID copied to the clipboard",
                "OK"
             )->show();

            if (!m_level) return;

            std::string idStr = std::to_string(m_level->m_levelID.value());

            auto written = clipboard::write(idStr);
        }
};
