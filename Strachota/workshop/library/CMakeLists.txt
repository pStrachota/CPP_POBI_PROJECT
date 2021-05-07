cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        src/math_helpers.cpp
        include/model/Client.h src/model/Client.cpp test/master.cpp test/ClientTest.cpp include/model/Address.h src/model/Address.cpp test/AddressTest.cpp include/model/Rent.h src/model/Rent.cpp include/model/Vehicle.h src/model/Vehicle.cpp test/VehicleTest.cpp test/RentTest.cpp include/typedefs.h include/repositories/ClientRepository.h include/repositories/VehicleRepository.h include/repositories/RentRepository.h src/repositories/ClientRepository.cpp src/repositories/VehicleRepository.cpp src/repositories/RentRepository.cpp include/repositories/StorageContainer.h src/repositories/StorageContainer.cpp test/StorageContainerTest.cpp test/ClientRepositoryTest.cpp test/RentRepositoryTest.cpp test/VehicleRepositoryTest.cpp include/model/Bicycle.h src/model/Bicycle.cpp include/model/MotorVehicle.h src/model/MotorVehicle.cpp src/model/Moped.cpp include/model/Moped.h include/model/Car.h src/model/Car.cpp test/BicycleTest.cpp test/CarTest.cpp test/MopedTest.cpp include/model/ClientType.h src/model/ClientType.cpp include/model/Default.h include/model/Bronze.h include/model/Silver.h include/model/Gold.h include/model/Platinum.h include/model/Diamond.h src/model/Default.cpp src/model/Bronze.cpp src/model/Silver.cpp src/model/Gold.cpp src/model/Platinum.cpp src/model/Diamond.cpp include/managers/ClientManager.h src/managers/ClientManager.cpp include/managers/VehicleManager.h src/managers/VehicleManager.cpp include/managers/RentManager.h src/managers/RentManager.cpp test/ClientManagerTest.cpp test/VehicleManagerTest.cpp test/RentManagerTest.cpp)
#utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES} include/model/Client.h src/model/Client.cpp test/master.cpp test/ClientTest.cpp include/model/Address.h src/model/Address.cpp test/AddressTest.cpp include/model/Rent.h src/model/Rent.cpp include/model/Vehicle.h src/model/Vehicle.cpp test/VehicleTest.cpp test/RentTest.cpp include/typedefs.h include/repositories/ClientRepository.h include/repositories/VehicleRepository.h include/repositories/RentRepository.h src/repositories/ClientRepository.cpp src/repositories/VehicleRepository.cpp src/repositories/RentRepository.cpp include/repositories/StorageContainer.h src/repositories/StorageContainer.cpp test/StorageContainerTest.cpp test/ClientRepositoryTest.cpp test/RentRepositoryTest.cpp test/VehicleRepositoryTest.cpp include/model/Bicycle.h src/model/Bicycle.cpp include/model/MotorVehicle.h src/model/MotorVehicle.cpp src/model/Moped.cpp include/model/Moped.h include/model/Car.h src/model/Car.cpp test/BicycleTest.cpp test/CarTest.cpp test/MopedTest.cpp include/model/ClientType.h src/model/ClientType.cpp include/model/Default.h include/model/Bronze.h include/model/Silver.h include/model/Gold.h include/model/Platinum.h include/model/Diamond.h src/model/Default.cpp src/model/Bronze.cpp src/model/Silver.cpp src/model/Gold.cpp src/model/Platinum.cpp src/model/Diamond.cpp include/managers/ClientManager.h src/managers/ClientManager.cpp include/managers/VehicleManager.h src/managers/VehicleManager.cpp include/managers/RentManager.h src/managers/RentManager.cpp test/ClientManagerTest.cpp test/VehicleManagerTest.cpp test/RentManagerTest.cpp)

target_include_directories(Library PUBLIC include)

enable_testing() # dodane wcześniej w punkcie 2
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES include/model/Address.h src/model/Address.cpp test/AddressTest.cpp include/model/Rent.h src/model/Rent.cpp include/model/Vehicle.h src/model/Vehicle.cpp test/VehicleTest.cpp test/RentTest.cpp include/typedefs.h include/repositories/ClientRepository.h include/repositories/VehicleRepository.h include/repositories/RentRepository.h src/repositories/ClientRepository.cpp src/repositories/VehicleRepository.cpp src/repositories/RentRepository.cpp include/repositories/StorageContainer.h src/repositories/StorageContainer.cpp test/StorageContainerTest.cpp test/ClientRepositoryTest.cpp test/RentRepositoryTest.cpp test/VehicleRepositoryTest.cpp include/model/Bicycle.h src/model/Bicycle.cpp include/model/MotorVehicle.h src/model/MotorVehicle.cpp src/model/Moped.cpp include/model/Moped.h include/model/Car.h src/model/Car.cpp test/BicycleTest.cpp test/CarTest.cpp test/MopedTest.cpp include/model/ClientType.h src/model/ClientType.cpp include/model/Default.h include/model/Bronze.h include/model/Silver.h include/model/Gold.h include/model/Platinum.h include/model/Diamond.h src/model/Default.cpp src/model/Bronze.cpp src/model/Silver.cpp src/model/Gold.cpp src/model/Platinum.cpp src/model/Diamond.cpp include/managers/ClientManager.h src/managers/ClientManager.cpp include/managers/VehicleManager.h src/managers/VehicleManager.cpp include/managers/RentManager.h src/managers/RentManager.cpp test/ClientManagerTest.cpp test/VehicleManagerTest.cpp test/RentManagerTest.cpp) # tu w przyszłości będą dodawane pliki źródłowe testów

add_executable (LibraryTest ${SOURCE_TEST_FILES}
        test/master.cpp
        test/ClientTest.cpp include/model/Address.h src/model/Address.cpp test/AddressTest.cpp include/model/Rent.h src/model/Rent.cpp include/model/Vehicle.h src/model/Vehicle.cpp test/VehicleTest.cpp test/RentTest.cpp include/typedefs.h include/repositories/ClientRepository.h include/repositories/VehicleRepository.h include/repositories/RentRepository.h src/repositories/ClientRepository.cpp src/repositories/VehicleRepository.cpp src/repositories/RentRepository.cpp include/repositories/StorageContainer.h src/repositories/StorageContainer.cpp test/StorageContainerTest.cpp test/ClientRepositoryTest.cpp test/RentRepositoryTest.cpp test/VehicleRepositoryTest.cpp include/model/Bicycle.h src/model/Bicycle.cpp include/model/MotorVehicle.h src/model/MotorVehicle.cpp src/model/Moped.cpp include/model/Moped.h include/model/Car.h src/model/Car.cpp test/BicycleTest.cpp test/CarTest.cpp test/MopedTest.cpp include/model/ClientType.h src/model/ClientType.cpp include/model/Default.h include/model/Bronze.h include/model/Silver.h include/model/Gold.h include/model/Platinum.h include/model/Diamond.h src/model/Default.cpp src/model/Bronze.cpp src/model/Silver.cpp src/model/Gold.cpp src/model/Platinum.cpp src/model/Diamond.cpp include/managers/ClientManager.h src/managers/ClientManager.cpp include/managers/VehicleManager.h src/managers/VehicleManager.cpp include/managers/RentManager.h src/managers/RentManager.cpp test/ClientManagerTest.cpp test/VehicleManagerTest.cpp test/RentManagerTest.cpp)

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
