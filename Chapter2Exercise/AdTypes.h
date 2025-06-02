#pragma once

#include <cstdint>
#include <string>
#include "AdConstants.h"


namespace Ad{

namespace Types{

    enum class LaneAssociationType : std::uint32_t{

        UnknownLane,
        LeftLane,
        CenterLane,
        RightLane
    };

    struct VehicleType{

        std::int32_t Id;
        Types::LaneAssociationType Lane;
        std::int32_t Speed;
        std::int32_t rDistance; // Relative Distance

        VehicleType(std::int32_t id,
                Types::LaneAssociationType lane,
                std::int32_t speed,
                std::int32_t rdistance)
            : Id(id)
            , Lane(lane)
            , Speed(speed)
            , rDistance(rdistance)
        {
        }

    };

}


}
