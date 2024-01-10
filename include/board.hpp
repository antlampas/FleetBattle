#include <vector>
#include <utility>
#include <string>

/*
 * O = square occupied
 * W = water
 * o = ship square hit
 * w = water square hit
 */

using boardType std::vector<std::vector<char>>;

class board
{
    private:
    std::vector<std::vector<char>>                             board         {};
    std::vector<short short>                                   ships         {};
    std::vector<std::pair<short short&,std::pair<short short>> deployedShips {};

    bool isCoordinateValid(std::string);
    bool isSquareAlreadyHit(std::string);
    bool isShipSunk();
    std::pair<short short,short short>
    bool hit(std::pair<short short,short short>);

    public:
    void shoot(std::string);
    char squareStatus(std::string);

}