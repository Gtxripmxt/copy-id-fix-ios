#include <Geode/Geode.hpp>
#include <Geode/modify/InfoLayer.hpp>

using namespace geode::prelude;

class $modify(MyInfoLayer, InfoLayer) {
        void onCopyLevelID(CCObject * sender) {
            Notification::create("Level ID copied to clipboard", NotificationIcon::Success)->show();

            if (!m_level) return;
            std::string idStr = std::to_string(m_level->m_levelID.value());

            auto written = clipboard::write(idStr);
        }
};
