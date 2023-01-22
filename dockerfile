#docker system prune -a
#docker build -t steering .
#docker run --name Steering_program -it steering

FROM ros:noetic-ros-base-focal as base


ENV TZ=Europe/Warsaw
RUN ln -snf "/usr/share/zoneinfo/$TZ" /etc/localtime
RUN echo "$TZ" > /etc/timezone
RUN apt-get update
RUN apt-get install -y tzdata
RUN apt-get install g++ -y && apt install git -y && apt install vim -y && apt install g++ -y && apt install build-essential -y
RUN apt-get install build-essential cmake -y --no-install-recommends 
RUN apt-get install libboost-all-dev -y
RUN apt-get install apt-utils
RUN apt-get install git

RUN git clone https://github.com/jupp0r/prometheus-cpp.git
WORKDIR prometheus-cpp
RUN git submodule init
RUN git submodule update --recursive
RUN cmake .. -DBUILD_SHARED_LIBS=ON -DENABLE_PUSH=OFF -DENABLE_COMPRESSION=OFF /prometheus-cpp
RUN cmake --build .
RUN cmake --install .
#cmake build

#RUN git clone https://github.com/PUT-Motorsport/PUTM_DV_STEERING_COLUMN_CONTROLLER.git
#RUN cd PUTM_DV_STEERING_COLUMN_CONTROLLER && mkdir Build && cd Build
#RUN cmake ../PUTM_DV_STEERING_COLUMN_CONTROLLER
#RUN cmake --build .

#RUN cd home && git clone https://github.com/PUT-Motorsport/PUTM_DV_STEERING_COLUMN_CONTROLLER.git && cd PUTM_DV_STEERING_COLUMN_CONTROLLER && git switch ROS_container
#SHELL ["source" ,"/opt/ros/noetic/setup.bash"]
#SHELL ["catkin_make"]


