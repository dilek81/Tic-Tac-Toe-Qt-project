# Qt TicTacToe

This is a simple TicTacToe game implemented in C++ using the Qt framework.

## Requirements

To build and run this application, you will need the following:

-   **Qt Development Environment:**
    -      Qt 5 or 6 
    -      `qttools5-dev-tools` or `qttools6-dev-tools` (for `qmake`).
    -   A C++ compiler (like g++).
-   **Docker (Optional):** If you wish to run this application within a Docker container.

## Installation and Build Instructions

### Without Docker

1.  **Install Qt:**
    -      On Debian/Ubuntu-based systems:
        ```bash
        sudo apt-get update
        sudo apt-get install qtbase5-dev qttools5-dev-tools g++
        # or for QT6
        # sudo apt-get install qtbase6-dev qttools6-dev-tools g++
        ```
    -      On other systems, download and install the Qt SDK from the official Qt website.
2.  **Save the Code:** Save the provided C++ code as `main.cpp`. Create a `TicTacToe.pro` file in the same directory with the following content:

    ```qmake
    QT += widgets
    SOURCES += main.cpp
    ```

3.  **Build the Application:**
    -      Open a terminal and navigate to the directory containing `main.cpp` and `TicTacToe.pro`.
    -      Run `qmake`.
    -      Run `make`.
    -   Run the executable that was created.

### With Docker

1.  **Create a Dockerfile:** Create a file named `Dockerfile` in the same directory as `main.cpp` and `TicTacToe.pro` with the following content:

    ```dockerfile
    FROM ubuntu:20.04

    RUN apt-get update && apt-get install -y \
        qtbase5-dev \
        qttools5-dev-tools \
        g++ \
        make

    COPY . /app
    WORKDIR /app

    RUN qmake && make

    CMD ["/app/TicTacToe"]
    ```
    If you are using QT6, replace `qtbase5-dev` and `qttools5-dev-tools` with the corresponding QT6 packages.
2.  **Build the Docker Image:**
    -      Open a terminal and navigate to the directory containing the `Dockerfile`.
    -      Run: `docker build -t tictactoe-qt .`
3.  **Run the Docker Container:**
    -   Because this is a GUI application, you will need to allow the docker container to display the GUI. On linux this can be done by using the following command.
    ```bash
    xhost +local:docker
    docker run -it --rm -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix tictactoe-qt
    ```
    -   Note that running GUI applications in docker can be complex, and this command may need to be adjusted based on your operating system and configuration.

## Running the Application

Once the application is built (either directly or within Docker), you can run it. Click on the buttons to play the game. The game will display a message box when a player wins.

## Notes

-      The Docker setup provided is a basic example. For more advanced configurations, you might need to adjust the `Dockerfile` and run commands.
-   Running GUI applications in docker requires special configuration.
-   This readme assumes a Debian/Ubuntu based linux distribution, you may need to change the installation commands for other distributions.