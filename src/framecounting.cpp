#include "zBot.hpp"
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

class $modify(PlayLayer) {
    bool init(GJGameLevel* lvl) {
        zBot* mgr = zBot::get();
        bool res = PlayLayer::init(lvl);

        mgr->frame = 0;
        mgr->previousPosition = m_player1->m_position;

        return res;
    }

    void update(float delta) {        
        PlayLayer::update(delta);

        zBot* mgr = zBot::get();
        if (m_player1->m_position != mgr->previousPosition) {
            mgr->frame++;
        }
        mgr->previousPosition = m_player1->m_position;
    }

    void resetLevel() {
        PlayLayer::resetLevel();

        zBot* mgr = zBot::get();
        mgr->frame = mgr->respawnFrame;
        mgr->previousPosition = m_player1->m_position;
    }
};