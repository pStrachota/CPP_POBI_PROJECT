#include <boost/test/unit_test.hpp>
#include "model/Car.h"
#include "typedefs.h"

struct TestSuiteCarFixture{
    const int initEngineDis = 1;
    const std::string initPlateNum = "ABC";
    const unsigned int initBasePri = 1;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteCar, TestSuiteCarFixture)

    BOOST_AUTO_TEST_CASE(CarActualRentalPriceTestVarEngine1)
    {
    //klasyAut constant, engine displacement variable
        klasyAut klasa = A;
        const int EngineDis = 500;
        CarPtr t_car = new Car(klasa,EngineDis,initPlateNum,initBasePri);
        BOOST_TEST( t_car->getActualRentalPrice() == 1.0);
        delete t_car;
    }

    BOOST_AUTO_TEST_CASE(CarActualRentalPriceTestVarEngine2)
    {
        //klasyAut constant, engine displacement variable
        klasyAut klasa = A;
        const int EngineDis = 2500;
        CarPtr t_car = new Car(klasa,EngineDis,initPlateNum,initBasePri);
        BOOST_TEST( t_car->getActualRentalPrice() == 1.5 );
        delete t_car;
    }

    BOOST_AUTO_TEST_CASE(CarActualRentalPriceTestVarEngine3)
    {
        //klasyAut constant, engine displacement variable
        klasyAut klasa = A;
        const int EngineDis = 1500;
        CarPtr t_car = new Car(klasa,EngineDis,initPlateNum,initBasePri);
        BOOST_TEST( t_car->getActualRentalPrice() == 1.25 );
        delete t_car;
    }

    BOOST_AUTO_TEST_CASE(CarActualRentalPriceTestVarKlasaA)
    {
        //klasyAut variable, engine displacement const
        klasyAut klasa = A;
        CarPtr t_car = new Car(klasa,initEngineDis,initPlateNum,initBasePri);
        BOOST_TEST( t_car->getActualRentalPrice() == 1);
        delete t_car;
    }

    BOOST_AUTO_TEST_CASE(CarActualRentalPriceTestVarKlasaB)
    {
        //klasyAut variable, engine displacement const
        klasyAut klasa = B;
        CarPtr t_car= new Car(klasa,initEngineDis,initPlateNum,initBasePri);
        BOOST_TEST( t_car->getActualRentalPrice() == 1.1);
        delete t_car;
    }

    BOOST_AUTO_TEST_CASE(CarActualRentalPriceTestVarKlasaC)
    {
        //klasyAut variable, engine displacement const
        klasyAut klasa = C;
        CarPtr t_car= new Car(klasa,initEngineDis,initPlateNum,initBasePri);
        BOOST_TEST( t_car->getActualRentalPrice() == 1.2);
        delete t_car;
    }

    BOOST_AUTO_TEST_CASE(CarActualRentalPriceTestVarKlasaD)
    {
        //klasyAut variable, engine displacement const
        klasyAut klasa = D;
        CarPtr t_car = new Car(klasa,initEngineDis,initPlateNum,initBasePri);
        BOOST_TEST( t_car->getActualRentalPrice() == 1.3);
        delete t_car;
    }

    BOOST_AUTO_TEST_CASE(CarActualRentalPriceTestVarKlasaE)
    {
        //klasyAut variable, engine displacement const
        klasyAut klasa = E;
        CarPtr t_car = new Car(klasa,initEngineDis,initPlateNum,initBasePri);
        BOOST_TEST( t_car->getActualRentalPrice() == 1.5);
        delete t_car;
    }

BOOST_AUTO_TEST_SUITE_END()