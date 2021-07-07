cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        src/math_helpers.cpp
        src/model/Client.cpp
        include/model/Client.h test/ClientTest.cpp
        src/model/Address.cpp include/model/Address.h test/AddressTest.cpp src/model/Vehicle.cpp include/model/Vehicle.h src/model/Rent.cpp include/model/Rent.h include/typedefs.h src/repositories/ClientRepository.cpp include/repositories/ClientRepository.h src/repositories/VehicleRepository.cpp include/repositories/VehicleRepository.h src/repositories/RentRepository.cpp include/repositories/RentRepository.h src/repositories/StorageContainer.cpp include/repositories/StorageContainer.h src/model/Bicycle.cpp include/model/Bicycle.h src/model/MotorVehicle.cpp include/model/MotorVehicle.h src/model/Moped.cpp include/model/Moped.h src/model/Car.cpp include/model/Car.h include/model/ClientType.h src/model/ClientType.cpp src/model/Default.cpp include/model/Default.h src/model/Bronze.cpp include/model/Bronze.h src/model/Silver.cpp include/model/Silver.h src/model/Gold.cpp include/model/Gold.h src/model/Platinum.cpp include/model/Platinum.h src/model/Diamond.cpp include/model/Diamond.h src/Managers/ClientManager.cpp include/Managers/ClientManager.h src/Managers/VehicleManager.cpp include/Managers/VehicleManager.h src/Managers/RentManager.cpp include/Managers/RentManager.h src/exceptions/ClientException.cpp include/exceptions/ClientException.h src/exceptions/VehicleException.cpp include/exceptions/VehicleException.h src/exceptions/RentException.cpp include/exceptions/RentException.h include/repositories/Repository.h include/model/functors.h)
#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)


enable_testing() # dodane wcześniej w punkcie 2
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES test/ClientRepositoryTest.cpp test/RentRepositoryTest.cpp test/VehicleRepositoryTest.cpp test/StorageContainerTest.cpp ) # tu w przyszłości będą dodawane pliki źródłowe testów

add_executable (LibraryTest ${SOURCE_TEST_FILES}
        test/master.cpp
        test/ClientTest.cpp
        test/AddressTest.cpp
        test/RentTest.cpp
        test/VehicleTest.cpp
        test/CarTest.cpp test/BicycleTest.cpp test/MopedTest.cpp) #tu lepiej dodawac testy

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )