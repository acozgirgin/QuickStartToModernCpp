#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"
#include "AdTypes.h"

using namespace Ad::Types;
using namespace Ad::Constants;
using namespace Ad::Utils;

float Ad::Utils::kph_to_mps(const float kph){

    return kph * (1000.0f / 3600.0f);
}



Ad::Types::VehicleType Ad::Data::init_ego_vehicle()
{
    return Ad::Types::VehicleType
    {
        .Id = EGO_VEHICLE_ID,
        .Lane = LaneAssociationType::CenterLane,
        .Speed = 100,
        .rDistance = 50
    };
}

Ad::Types::NeighbourVehiclesType Ad::Data::init_vehicles()
{
    NeighbourVehiclesType vehicles{};

    for(std::size_t i=0; i<NUM_VEHICLES_ON_LANE; ++i)
    {
        auto factor = static_cast<std::int32_t>(i);

        vehicles.vehiclesCenter[i] = VehicleType{
            .Id = factor,
            .Lane = LaneAssociationType::CenterLane,
            .Speed = 100 + 20 * (factor+1),
            .rDistance = 20 * (factor+1)
        };

        vehicles.vehiclesLeft[i] = VehicleType{
            .Id = factor,
            .Lane = LaneAssociationType::LeftLane,
            .Speed = 100 + 10 * (factor+1),
            .rDistance = 30 * (factor+1)
        };

         vehicles.vehiclesRight[i] = VehicleType{
            .Id = factor,
            .Lane = LaneAssociationType::RightLane,
            .Speed = 100 + 30 * (factor+1),
            .rDistance = 40 * (factor+1)
        };
    }


    return vehicles;

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

void Ad::Visualize::print_vehicle(const VehicleType& vehicle){

    std::cout << "\n\nVehicle ID:" << vehicle.Id << std::endl;
    std::cout << "Speed:" << kph_to_mps(static_cast<float>(vehicle.Speed)) <<"mps" <<std::endl;
    std::cout << "Relative Distance:" << vehicle.rDistance << std::endl;
    std::cout << "Current lane: " << Ad::Utils::to_string(vehicle.Lane);
}

void Ad::Visualize::print_neighbour_vehicles(const NeighbourVehiclesType& vehicles){

    for(size_t j=0; j < NUM_VEHICLES_ON_LANE; ++j)
    {
        print_vehicle(vehicles.vehiclesCenter[j]);
        print_vehicle(vehicles.vehiclesRight[j]);
        print_vehicle(vehicles.vehiclesLeft[j]);
    }

}
