FROM ubuntu

MAINTAINER Thomas Li "thomas.tong.li@gmail.com"

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=America/UTC

LABEL description="Docker container for k-means-cpp build"

RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get install -y g++-10 gcc-10 make cmake git lcov gcovr
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 100 --slave /usr/bin/g++ g++ /usr/bin/g++-10 --slave /usr/bin/gcov gcov /usr/bin/gcov-10
RUN git clone "https://github.com/thomastli/k-means-cpp.git"
WORKDIR k-means-cpp
RUN ./build.sh
WORKDIR build

