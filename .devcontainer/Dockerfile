# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.145.1/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version: debian-10, debian-9
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

RUN mkdir -p /usr/ \
    && mkdir -p /opt/mercury/inc \
    && mkdir -p /opt/mercury/src \
    && mkdir -p /opt/mercury/test\
    && mkdir -p /opt/build/boost

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends g++ build-essential cmake git curl \
    && curl -L https://dl.bintray.com/boostorg/release/1.74.0/source/boost_1_74_0.tar.gz -o boost_1_74_0.tar.gz \
    && tar -xzf boost_1_74_0.tar.gz --directory /opt/build/boost \
    && cd /opt/build/boost/boost_1_74_0 \
    && ./bootstrap.sh --prefix=/usr/ --with-libraries=system,filesystem,test \
    && ./b2 -j 2 install                                                   \
    && ldconfig