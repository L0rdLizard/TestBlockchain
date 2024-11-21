cmake_minimum_required(VERSION 3.12)

project(BlockchainTest)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(BlockchainTest
    src/main.cpp
    src/Blockchain.cpp
    src/Wallet.cpp
    src/Transaction.h
)
