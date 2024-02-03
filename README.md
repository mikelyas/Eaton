# Eaton test

The problem to solve is following:

                You monitor devices, which are sending data to you.

                Each device has a unique name.

                Each device produces measurements.

The challenge is:

                Compute the number of messages you got or read from the devices.

## Getting Started

To test the project, follow these steps:

1. Create a build directory in the project root.

```shell
mkdir build
```

or use

```shell
make
```

2. Navigate to the build directory.

```shell
cd build
```

3. Generate the build files using CMake.

```shell
cmake ..
```

4. Build the project.

```shell
cmake --build .
```

This process generates both the application executable with one use case and an executable for running unit tests.

## Running the Application

After building the project, you can run the application executable from the build directory. The application would be generated in build/app/ and would be called Simulation, it demonstrates the simulation of devices working and communicating with the observer.

## Running Unit Tests

You can run the unit tests executable from the build directory. These tests validate the correctness of the device and observer implementation. The unit tests would be generated in /build/tests and would be called unit_tests.