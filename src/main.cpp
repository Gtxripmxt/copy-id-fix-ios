#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/InfoLayer.hpp>
class $modify(MyInfoLayer, InfoLayer) {
	bool init() {
		if (!InfoLayer::init()) {
			return false;
		}
        void onCopyLevelID(CCObject * sender) {
            if (!m_level) return;

            std::string idStr = std::to_string(m_level->m_levelID.value());

            auto written = clipboard::write(idStr);
            FLAlertLayer::create(
                "Copy id",
                "Level ID Copied to clipboard",
                "OK"
            )->show();
        }
		return true;
	}
};