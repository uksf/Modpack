#pragma once
#include "uksf.hpp"

#define LOG_DEBUG(A) LOG(INFO) << A

static auto reng = std::default_random_engine{};

class uksf_common : public singleton<uksf_common> {
public:
    uksf_common();

    static game_value cbaSettingsFncInit;
    static bool threadRun;

    static float getZoom();
    static bool lineOfSight(object& target, object& source, bool zoomCheck, bool groupCheck);
    static side getSide(int sideNumber);
};