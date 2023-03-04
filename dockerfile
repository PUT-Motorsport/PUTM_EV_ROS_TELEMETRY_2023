#docker system prune -a
#docker build -t steering .
#docker run --name Steering_program -it steering
#sudo docker run --name telemetry_node --network=host -v /home/ketirange/Projects/PUTM_EV_ROS_TELEMETRY_2023/:/home/putm -it telemetry

FROM ros:noetic-ros-base-focal as base


ENV TZ=Europe/Warsaw
RUN ln -snf "/usr/share/zoneinfo/$TZ" /etc/localtime
RUN echo "$TZ" > /etc/timezone
RUN sudo apt-get update && sudo dpkg --configure -a

RUN apt-get install -y tzdata
RUN apt-get install g++ -y && apt install git -y && apt install vim -y && apt install g++ -y && apt install build-essential -y
RUN apt-get install build-essential cmake -y --no-install-recommends 
RUN apt-get install libboost-all-dev -y
RUN apt-get install apt-utils libprotobuf-dev -y
RUN apt-get install curl libssl-dev libcurl4-openssl-dev -y
RUN apt-get install libfmt-dev -y
RUN sudo apt-get install -y libsnappy-dev
RUN apt-get install gdb -y

RUN git clone https://github.com/jupp0r/prometheus-cpp.git
WORKDIR prometheus-cpp
RUN git submodule init
RUN git submodule update --recursive
RUN cmake .. -DBUILD_SHARED_LIBS=ON -DENABLE_PUSH=OFF -DENABLE_COMPRESSION=OFF /prometheus-cpp
RUN cmake --build .
RUN cmake --install .

WORKDIR /
RUN git clone https://github.com/mircodezorzi/loki-cpp.git
WORKDIR loki-cpp
RUN mkdir build && cd build
WORKDIR /loki-cpp/build
RUN cmake .. -DCMAKE_BUILD_TYPE=Release
RUN cmake --build .
RUN cmake --install .

WORKDIR /
RUN git clone https://github.com/fmtlib/fmt.git
WORKDIR fmt
RUN mkdir build && cd build
WORKDIR /fmt/build
RUN cmake ..
RUN make
RUN make install


#cmake build

#RUN git clone https://github.com/PUT-Motorsport/PUTM_DV_STEERING_COLUMN_CONTROLLER.git
#RUN cd PUTM_DV_STEERING_COLUMN_CONTROLLER && mkdir Build && cd Build
#RUN cmake ../PUTM_DV_STEERING_COLUMN_CONTROLLER
#RUN cmake --build .

#RUN cd home && git clone https://github.com/PUT-Motorsport/PUTM_DV_STEERING_COLUMN_CONTROLLER.git && cd PUTM_DV_STEERING_COLUMN_CONTROLLER && git switch ROS_container
#SHELL ["source" ,"/opt/ros/noetic/setup.bash"]
#SHELL ["catkin_make"]


