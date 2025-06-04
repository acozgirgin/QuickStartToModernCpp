#include <cstring>
#include <iostream>
#include <numeric>

#include "AdFunctions.h"
#include "AdTypes.h"

int main()
{

    auto ego_vehicle = Ad::Data::init_ego_vehicle();
    Ad::Visualize::print_vehicle(ego_vehicle);
    auto neighbour_vehicles = Ad::Data::init_vehicles();
    Ad::Visualize::print_neighbour_vehicles(neighbour_vehicles);

    return 0;
}
