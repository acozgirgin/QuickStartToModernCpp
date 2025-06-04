#pragma once

#include <cstdint>
#include <string>
#include <array>
#include "AdConstants.h"


namespace Ad{

namespace Types{

    enum class LaneAssociationType : std::uint32_t{

        UnknownLane,
        LeftLane,
        CenterLane,
        RightLane
    };

    struct VehicleType
    {
        std::int32_t Id;
        Types::LaneAssociationType Lane;
        std::int32_t Speed;
        std::int32_t rDistance; // Relative Distance

    };


    // Array for nearby vehicles on left lane (2 vehicles in total)
    // Array for nearby vehicles on center lane (2 vehicles in total)
    // Array for nearby vehicles on right lane (2 vehicles in total)
    struct NeighbourVehiclesType{
        std::array<VehicleType , Ad::Constants::NUM_VEHICLES_ON_LANE> vehiclesCenter{};
        std::array<VehicleType , Ad::Constants::NUM_VEHICLES_ON_LANE> vehiclesLeft{};
        std::array<VehicleType, Ad::Constants::NUM_VEHICLES_ON_LANE> vehiclesRight{};
    };

}


}
