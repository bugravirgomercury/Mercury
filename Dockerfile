FROM ubuntu:18.04

RUN apt-get update                                                     && \
    apt-get install -y                                                    \
    g++ build-essential cmake git curl

RUN mkdir -p /opt/mercury/inc
RUN mkdir -p /opt/mercury/src
RUN mkdir -p /opt/mercury/test
RUN mkdir -p /opt/build/boost

COPY inc /opt/mercury/inc
COPY src /opt/mercury/src
COPY test /opt/mercury/test
COPY CMakeLists.txt /opt/mercury/CMakeLists.txt

RUN curl -L https://dl.bintray.com/boostorg/release/1.74.0/source/boost_1_74_0.tar.gz -o boost_1_74_0.tar.gz                                      && \
    tar -xzf boost_1_74_0.tar.gz --directory /opt/build/boost          && \
    cd /opt/build/boost/boost_1_74_0                                   && \
    ./bootstrap.sh --prefix=/usr/ --with-libraries=system,filesystem,test && \
    ./b2 -j 2 install                                                  && \
    ldconfig

WORKDIR /opt/mercury
RUN cmake -E make_directory ./build                                    && \
    cd ./build                                                         && \
    cmake /opt/mercury -DCMAKE_BUILD_TYPE=Release                      && \
    cmake --build . --config Release                                   && \
    ctest -C Release

