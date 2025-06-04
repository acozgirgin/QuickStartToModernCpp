#pragma once

#include "AdTypes.h"


namespace Ad
{

    namespace Utils
    {
        float kph_to_mps(const float kph);

        std::string to_string(Ad::Types::LaneAssociationType lane);

    }

    namespace Data
    {
        Ad::Types::VehicleType init_ego_vehicle();
        Ad::Types::NeighbourVehiclesType init_vehicles();
    }

    namespace Visualize
    {
        void print_vehicle(const Ad::Types::VehicleType& vehicle);
        void print_neighbour_vehicles(const Ad::Types::NeighbourVehiclesType& vehicles);
    }



}
