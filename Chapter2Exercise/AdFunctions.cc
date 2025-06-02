#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"
#include "AdTypes.h"


float Ad::Utils::kph_to_mps(const float kph){

    return kph * (1000.0f / 3600.0f);
}



Ad::Types::VehicleType Ad::Data::init_ego_vehicle()
{
    return Ad::Types::VehicleType
    {
        Ad::Constants::EGO_VEHICLE_ID,
        Ad::Types::LaneAssociationType::CenterLane,
        100,
        50
    };
}

std::string Ad::Utils::to_string(Ad::Types::LaneAssociationType lane) {

    switch (lane) {
        case Ad::Types::LaneAssociationType::UnknownLane:
            return "Unknown Lane";
        case Ad::Types::LaneAssociationType::LeftLane:
            return "Left Lane";
        case Ad::Types::LaneAssociationType::CenterLane:
            return "Center Lane";
        case Ad::Types::LaneAssociationType::RightLane:
            return "Right Lane";
        default:
            return "Invalid Lane";
    }
}

void Ad::Visualize::print_vehicle(const Ad::Types::VehicleType vehicle){

    std::cout << "Vehicle ID:" << vehicle.Id << std::endl;
    std::cout << "Speed:" << vehicle.Speed <<"kph" <<std::endl;
    std::cout << "Relative Distance:" << vehicle.rDistance << std::endl;
    std::cout << "Current lane: " << Ad::Utils::to_string(vehicle.Lane);
}
